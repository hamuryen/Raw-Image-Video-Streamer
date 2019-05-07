#include <thread>
#include <chrono>

#include "VideoStreamer.h"

int main()
{
	{
		Streamer::VideoStreamer streamer(554, 1920, 1080, 25);
		streamer.Run();

		int color = 0;
		while (true)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(40));
			unsigned char* data = (unsigned char*)calloc(1, 1080 * 1920 * 3);
			for (int i = color; i < (1080 * 1920 * 3); i += 3)
				data[i] = 255;
			color = (color + 1) % 3;
			streamer.SetImage(data);
			free(data);
		}
	}
	return 0;
}