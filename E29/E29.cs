using System;

namespace E29
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] dizi = { 12, 43, 56, 23, 1, 34, 12, 43, 65, 12, 45, 2, 3, 90 };
            int maksElemanSayısı = 100;
            int[] sayilar = new int[maksElemanSayısı];
            for (int i = 0; i < dizi.Length; i++)
            {
                sayilar[dizi[i]] = sayilar[dizi[i]] + 1;
            }
            for (int i = 0; i < sayilar.Length; i++)
            {
                for (int j = 0; j < sayilar[i]; j++)
                {
                    Console.Write(i + " ");
                }
            }
            Console.ReadKey();
        }
    }
}