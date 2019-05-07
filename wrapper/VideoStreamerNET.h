/*
* File:   VideoStreamerNET.h
* Author: Burak Hamuryen
*
* Created on 07.05.2019
*/

#ifndef VIDEO_STREAMER_NET_H
#define VIDEO_STREAMER_NET_H

#include "VideoStreamer.h"

using namespace System;
namespace Streamer
{
	public ref class VideoStreamerNET
	{
	public:
		VideoStreamerNET(unsigned short port, size_t width, size_t height, size_t fps);
		~VideoStreamerNET();
		!VideoStreamerNET();

		void SetImage(unsigned char* image);
		bool Run();

	private:
		void Destroy();

	private:
		VideoStreamer* m_Streamer;
	};
};

#endif // !VIDEO_STREAMER_NET_H