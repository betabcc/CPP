using System;

namespace E28
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] dizi = { 12, 43, 56, 23, 1, -34, 12, 43, 65, 12, 45, 2, 3, 90 };
            int a = 0;
            for (int i = 1; i < dizi.Length; i++)
            {
                int indeks = i;
                while (indeks != 0 && (dizi[indeks] < dizi[indeks - 1]))
                {
                    a++;
                    if (dizi[indeks] < dizi[indeks - 1])
                    {
                        int swap = dizi[indeks];
                        dizi[indeks] = dizi[indeks - 1];
                        dizi[indeks - 1] = swap;
                    }
                    indeks--;
                }
            }
            Console.WriteLine(a);
            foreach (var item in dizi)
            {
                Console.Write(item);
                Console.Write(" ");
            }
            Console.ReadLine();
        }
    }
}