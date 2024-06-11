using System;
using System.Collections.Generic;

namespace CharacterCounter
{
    class bai8d
    {
        static void Main(string[] args)
        {
            Console.Write("Nhập chuỗi: ");
            string input = Console.ReadLine();

            Dictionary<char, int> charCount = new Dictionary<char, int>();

            foreach (char c in input)
            {
                if (charCount.ContainsKey(c))
                {
                    charCount[c]++;
                }
                else
                {
                    charCount[c] = 1;
                }
            }

            Console.WriteLine("Kết quả đếm:");
            foreach (KeyValuePair<char, int> pair in charCount)
            {
                Console.WriteLine("{0} xuất hiện {1} lần", pair.Key, pair.Value);
            }

            Console.ReadLine();
        }
    }
}