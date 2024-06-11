
using System;

namespace StudentManagement
{
    struct Student
    {
        public string Name;
        public float Score;
    }

    class bai11
    {
        static void Main(string[] args)
        {
            Console.Write("Nhập số lượng sinh viên: ");
            int n = int.Parse(Console.ReadLine());

            Student[] students = new Student[n];

            // Nhập thông tin sinh viên
            for (int i = 0; i < n; i++)
            {
                Console.WriteLine($"Nhập thông tin sinh viên {i + 1}:");
                Console.Write("Tên: ");
                students[i].Name = Console.ReadLine();
                Console.Write("Điểm: ");
                students[i].Score = float.Parse(Console.ReadLine());
            }

            // Hiển thị thông tin sinh viên
            Console.WriteLine("\nThông tin sinh viên:");
            for (int i = 0; i < n; i++)
            {
                Console.WriteLine($"Tên: {students[i].Name}, Điểm: {students[i].Score}");
            }

            // Tính điểm trung bình
            float totalScore = 0;
            foreach (var student in students)
            {
                totalScore += student.Score;
            }
            float averageScore = totalScore / n;
            Console.WriteLine($"\nĐiểm trung bình của lớp: {averageScore}");

            Console.ReadLine();
        }
    }
}