/*
* File:   VideoStreamer.h
* Author: Burak Hamuryen
*
* Created on 07.05.2019
*/

#ifndef VIDEO_STREAMER_H
#define VIDEO_STREAMER_H

#include <memory>

namespace Streamer
{
	class VideoStreamerImp;
	class __declspec(dllexport) VideoStreamer
	{
	public:
		VideoStreamer(unsigned short port, size_t width, size_t height, size_t fps = 25);
		virtual ~VideoStreamer();

		void SetImage(unsigned char* image);
		bool Run();

	private:
		std::unique_ptr<VideoStreamerImp> m_Imp;
	};
};

#endif //!VIDEO_STREAMER_H