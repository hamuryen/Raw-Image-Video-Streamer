using Streamer;
using System;

namespace VideoStreamer.NET.Sample
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Running!\n\n");

            VideoStreamerNET streamer = new VideoStreamerNET(554, 1920, 1080, 25);
            streamer.Run();


            Console.ReadLine();
        }
    }
}
