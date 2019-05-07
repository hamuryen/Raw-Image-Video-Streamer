#include "MemImage.h"

Streamer::MemImage::MemImage(unsigned char* image, size_t size)
	:m_Image(nullptr), m_ImageCache(nullptr), m_Size(size)
{
	m_Image = new unsigned char[m_Size];
	m_ImageCache = new unsigned char[m_Size];
	if (image != nullptr)
	{
		SetImage(image);
		UpdateImage();
	}
}

Streamer::MemImage::~MemImage()
{
	if (m_Image != nullptr)
		delete[] m_Image;
	if (m_ImageCache != nullptr)
		delete[] m_ImageCache;
}

void Streamer::MemImage::SetImage(unsigned char* image)
{
	std::lock_guard<std::mutex> lock(m_ImageMutex);
	memcpy(m_ImageCache, image, m_Size);
}

void Streamer::MemImage::UpdateImage()
{
	std::lock_guard<std::mutex> lock(m_ImageMutex);
	memcpy(m_Image, m_ImageCache, m_Size);
	m_Pos = 0;
}