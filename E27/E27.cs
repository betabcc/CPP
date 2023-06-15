using System;

namespace E27
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] dizi = { 12, 43, 56, 23, 1, -34, 12, 43, 65, 12, 45, 2, 3, 90 };
            for (int i = 0; i < dizi.Length; i++)
            {
                int min = i;
                for (int j = i + 1; j < dizi.Length; j++)
                {
                    if (dizi[j] < dizi[min])
                        min = j;
                }
                int swap = dizi[i];
                dizi[i] = dizi[min];
                dizi[min] = swap;
            }
            foreach (var item in dizi)
            {
                Console.Write(item);
                Console.Write(" ");
            }
            Console.ReadLine();
        }
    }
}