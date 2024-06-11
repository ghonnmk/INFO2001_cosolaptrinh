using System;
using System.Text;

namespace UTF8_Table
{
    class bai8b
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;

            Console.WriteLine("Bảng mã UTF-8 của trang mã 65001:");
            Console.WriteLine("Dec\tHex\tChar");
            Console.WriteLine("---\t---\t----");

            for (int i = 0; i <= 0x10FFFF; i++)
            {
                if (Char.IsLetterOrDigit((char)i) || Char.IsWhiteSpace((char)i))
                {
                    Console.WriteLine("{0}\t{0:X}\t{1}", i, (char)i);
                }
            }

            Console.ReadLine();
        }
    }
}   