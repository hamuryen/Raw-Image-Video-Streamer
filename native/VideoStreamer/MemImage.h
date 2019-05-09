/*
* File:   MemImage.h
* Author: Burak Hamuryen
*
* Created on 07.05.2019
*/

#ifndef MEM_IMAGE_H
#define MEM_IMAGE_H

typedef unsigned int ssize_t;

#include "Definition.h"

namespace Streamer
{
	class DLL_EXPORT MemImage
	{
	public:
		MemImage(unsigned char* image, size_t size);
		virtual ~MemImage();

		void SetImage(unsigned char* image);
		void UpdateImage();

		unsigned char* m_Image;
		size_t m_Size;
		size_t m_Pos = 0;
	private:
		unsigned char* m_ImageCache;
		std::mutex m_ImageMutex;
	};
};

#endif // !MEM_IMAGE_H