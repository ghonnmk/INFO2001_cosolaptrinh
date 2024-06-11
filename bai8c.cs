using System;

namespace BeepOnSpacePress
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Nhấn phím space để phát tiếng beep. Nhấn Enter để thoát.");

            while (true)
            {
                ConsoleKeyInfo key = Console.ReadKey(true);
                if (key.Key == ConsoleKey.Spacebar)
                {
                    Console.Beep();
                }
                else if (key.Key == ConsoleKey.Enter)
                {
                    break;
                }
            }
        }
    }
}