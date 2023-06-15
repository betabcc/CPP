using System;

namespace E30
{
    internal class Program
    {
        static string linearArama(int[] dizi, int aranan)
        {
            string sonuc = "";
            int baslangicIndeks = 0;
            while (true)
            {
                int gelenSonuc = ara(dizi, baslangicIndeks, aranan);
                if (gelenSonuc == -1)
                    break;
                sonuc += gelenSonuc + " ";
                baslangicIndeks = gelenSonuc + 1;
            }
            return sonuc;
        }

        static int ara(int[] dizi, int baslangicIndex, int aranan)
        {
            for (int i = baslangicIndex; i < dizi.Length; i++)
            {
                if (dizi[i] == aranan)
                    return i;
            }
            return -1;
        }

        static void Main(string[] args)
        {
            int[] dizi = { 12, 43, 56, 23, 1, 34, 12, 43, 65, 12, 45, 2, 3, 90 };
            int aranan = 12;
            string sonuc = linearArama(dizi, aranan);
            Console.WriteLine(sonuc);
            Console.ReadKey();
        }
    }
}