using System;

namespace E26
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] dizi = { 12, 43, 56, 23, 1, -34, 12, 43, 65, 12, 45, 2, 3, 90 };
            int a = 0;
            for (int i = 0; i < dizi.Length; i++)
            {
                bool degistiMi = false;
                for (int j = 1; j < dizi.Length - i; j++)
                {
                    a++;
                    if (dizi[j - 1] > dizi[j])
                    {
                        int swap = dizi[j];
                        dizi[j] = dizi[j - 1];
                        dizi[j - 1] = swap;
                        degistiMi = true;
                    }
                }
                if (degistiMi == false)
                    break;
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