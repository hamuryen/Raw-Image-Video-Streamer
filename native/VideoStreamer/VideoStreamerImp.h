#ifndef VIDEO_STREAMER_IMP_H
#define VIDEO_STREAMER_IMP_H

#include "Definition.h"
#include "MemImage.h"

namespace Streamer
{
	class DLL_EXPORT VideoStreamerImp
	{
	public:
		VideoStreamerImp(unsigned short port, size_t width, size_t height, size_t fps = 25);
		virtual ~VideoStreamerImp();

		void SetImage(unsigned char* image);
		bool Run();

		//callback methods
		ssize_t MediaRead(void* opaque, unsigned char* buf, size_t len);
		int MediaOpen(void* opaque, void** datap, uint64_t* sizep);
		int MediaSeek(void* opaque, uint64_t offset);
		void MediaClose(void* opaque);

	private:
		unsigned short m_Port;
		MemImage* m_Image;
		size_t m_Width;
		size_t m_Height;
		size_t m_Fps;

		libvlc_instance_t *m_VLC;
		libvlc_media_player_t *m_MediaPlayer;
	};
};

#endif //!VIDEO_STREAMER_IMP_H