using System;

namespace CountWords
{
    class bai9b
    {
        static void Main(string[] args)
        {
            Console.Write("Nhập chuỗi: ");
            string input = Console.ReadLine();

            int wordCount = CountWords(input);

            Console.WriteLine("Số lượng từ trong chuỗi: " + wordCount);
            Console.ReadLine();
        }

        static int CountWords(string str)
        {
            string[] words = str.Split(new char[] { ' ', '\t', '\n' }, StringSplitOptions.RemoveEmptyEntries);
            return words.Length;
        }
    }
}