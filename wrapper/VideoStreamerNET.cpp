/*
* File:   VideoStreamerNET.cpp
* Author: Burak Hamuryen
*
* Created on 07.05.2019
*/

#include "VideoStreamerNET.h"

Streamer::VideoStreamerNET::VideoStreamerNET(unsigned short port, size_t width, size_t height, size_t fps)
	:m_Streamer(nullptr)
{
	m_Streamer = new VideoStreamer(port, width, height, fps);
}

Streamer::VideoStreamerNET::~VideoStreamerNET()
{
	Destroy();
}

Streamer::VideoStreamerNET::!VideoStreamerNET()
{
	Destroy();
}

void Streamer::VideoStreamerNET::Destroy()
{
	if (m_Streamer != nullptr)
	{
		delete m_Streamer;
		m_Streamer = nullptr;
	}
}

void Streamer::VideoStreamerNET::SetImage(unsigned char* image)
{
	m_Streamer->SetImage(image);
}

bool Streamer::VideoStreamerNET::Run()
{
	return m_Streamer->Run();
}