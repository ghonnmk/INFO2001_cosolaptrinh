using System;

namespace ASCII_Table
{
    class bai8a
    {
        static void Main(string[] args)
        {
            Console.WriteLine("bang ma ASCII:");
            Console.WriteLine("Dec\tHex\tChar");
            Console.WriteLine("---\t---\t----");

            for (int i = 0; i <= 255; i++)
            {
                Console.WriteLine("{0}\t{0:X}\t{1}", i, (char)i);
            }

            Console.ReadLine();
        }
    }
}