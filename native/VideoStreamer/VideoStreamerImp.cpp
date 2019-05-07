#include "VideoStreamerImp.h"

Streamer::VideoStreamerImp::VideoStreamerImp(unsigned short port, size_t width, size_t height, size_t fps)
	:m_Image(nullptr),
	m_VLC(nullptr),
	m_MediaPlayer(nullptr),
	m_Port(port),
	m_Width(width),
	m_Height(height),
	m_Fps(fps)
{
	m_Image = new Streamer::MemImage(nullptr, width * height * 3);
}

Streamer::VideoStreamerImp::~VideoStreamerImp()
{
	if (m_MediaPlayer != nullptr)
	{
		if (libvlc_media_player_is_playing(m_MediaPlayer))
			libvlc_media_player_stop(m_MediaPlayer);
		libvlc_media_player_release(m_MediaPlayer);
	}
	if (m_VLC != nullptr)
		libvlc_release(m_VLC);

	if (m_Image != nullptr)
		delete m_Image;
}

void Streamer::VideoStreamerImp::SetImage(unsigned char * image)
{
	if (image != nullptr)
		m_Image->SetImage(image);
}

ssize_t MediaReaCB(void* opaque, unsigned char* buf, size_t len)
{
	Streamer::VideoStreamerImp *streamer = static_cast<Streamer::VideoStreamerImp*>(opaque);
	return streamer->MediaRead(opaque, buf, len);
}

int MediaOpenCB(void* opaque, void** datap, uint64_t* sizep)
{
	Streamer::VideoStreamerImp *streamer = static_cast<Streamer::VideoStreamerImp*>(opaque);
	return streamer->MediaOpen(opaque, datap, sizep);
}

int MediaSeekCB(void* opaque, uint64_t offset)
{
	Streamer::VideoStreamerImp *streamer = static_cast<Streamer::VideoStreamerImp*>(opaque);
	return streamer->MediaSeek(opaque, offset);
}

void MediaCloseCB(void* opaque)
{
	Streamer::VideoStreamerImp *streamer = static_cast<Streamer::VideoStreamerImp*>(opaque);
	streamer->MediaClose(opaque);
}

ssize_t Streamer::VideoStreamerImp::MediaRead(void* opaque, unsigned char* buf, size_t len)
{
	size_t copylen = std::min(m_Image->m_Size - m_Image->m_Pos, len);
	unsigned char *start = m_Image->m_Image + m_Image->m_Pos;
	memcpy(buf, start, copylen);
	m_Image->m_Pos += (copylen % m_Image->m_Size);

	if (m_Image->m_Pos >= m_Image->m_Size)
	{
		m_Image->UpdateImage();
	}
	return copylen;
}

int Streamer::VideoStreamerImp::MediaOpen(void* opaque, void** datap, uint64_t* sizep)
{
	*datap = static_cast<Streamer::VideoStreamerImp*>(opaque);
	*sizep = UINT64_MAX;
	return 0;
}

int Streamer::VideoStreamerImp::MediaSeek(void* opaque, uint64_t offset)
{
	return 0;
}

void Streamer::VideoStreamerImp::MediaClose(void* opaque)
{
}

bool Streamer::VideoStreamerImp::Run()
{
	std::vector<const char*> options;
	m_VLC = libvlc_new(static_cast<int>(options.size()), options.data());

	libvlc_media_t* media = libvlc_media_new_callbacks(
		m_VLC,
		MediaOpenCB,
		MediaReaCB,
		MediaSeekCB,
		MediaCloseCB,
		this);

	std::string fps = std::string(":rawvid-fps=").append(std::to_string(m_Fps));
	std::string width = std::string(":rawvid-width=").append(std::to_string(m_Width));
	std::string height = std::string(":rawvid-height=").append(std::to_string(m_Height));
	std::string stream = std::string(":sout=#transcode{vcodec=h264,vb=800,acodec=mpga,ab=128,channels=2,samplerate=44100,scodec=none}:rtp{sdp=rtsp://:").append(std::to_string(m_Port)).append("/video}");

	libvlc_media_add_option(media, ":demux=rawvid");
	libvlc_media_add_option(media, ":rawvid-chroma=RV24");
	libvlc_media_add_option(media, ":sout-keep");
	libvlc_media_add_option(media, fps.c_str());
	libvlc_media_add_option(media, width.c_str());
	libvlc_media_add_option(media, height.c_str());
	libvlc_media_add_option(media, stream.c_str());

	m_MediaPlayer = libvlc_media_player_new_from_media(media);
	int res = libvlc_media_player_play(m_MediaPlayer);
	libvlc_media_release(media);

	return (res == 0 && libvlc_media_player_is_playing(m_MediaPlayer) == 1);
}