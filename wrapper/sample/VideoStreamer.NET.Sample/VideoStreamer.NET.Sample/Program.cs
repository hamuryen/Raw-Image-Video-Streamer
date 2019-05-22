using Streamer;
using System;
using System.Threading;

namespace VideoStreamer.NET.Sample
{
    class Program
    {
        unsafe static void SetImage(VideoStreamerNET streamer, byte[] data)
        {
            fixed (byte* p = data)
            {
                streamer.SetImage(p);
            }
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Running!\n\n");

            VideoStreamerNET streamer = new VideoStreamerNET(554, 1920, 1080, 25);
            streamer.Run();

            int color = 0;
            while (true)
            {
                Thread.Sleep(40);
                byte[] data = new byte[1080 * 1920 * 3];
                for (int i = color; i < (1080 * 1920 * 3); i += 3)
                    data[i] = 255;
                color = (color + 1) % 3;
                SetImage(streamer, data);
            }
            Console.ReadLine();
        }
    }
}