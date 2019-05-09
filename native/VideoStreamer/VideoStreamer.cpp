/*
* File:   VideoStreamer.cpp
* Author: Burak Hamuryen
*
* Created on 07.05.2019
*/

#include "VideoStreamer.h"
#include "VideoStreamerImp.h"

Streamer::VideoStreamer::VideoStreamer(unsigned short port, size_t width, size_t height, size_t fps)
{
	m_Imp = std::make_unique<Streamer::VideoStreamerImp>(port, width, height, fps);
}

Streamer::VideoStreamer::~VideoStreamer()
{

}

void Streamer::VideoStreamer::SetImage(unsigned char * image)
{
	m_Imp->SetImage(image);
}

bool Streamer::VideoStreamer::Run()
{
	return m_Imp->Run();
}