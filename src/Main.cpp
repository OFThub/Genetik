/**       
*** @file        -- DnaIslemleri
*** @description -- Program DNA'nın içindeki Kromozom ve Gen bilgilerini kullanarak DNA'ya Çaprazlama ve Mutasyon gibi işlemlerin gerçekleştirilmesini sağlar
*** @course      -- 2.Öğretim B Grubu
*** @assignment  -- 1.Ödev
*** @date        -- 11.11.2024
*** @author      -- Ömer Faruk TÜRKDOĞDU  -  G231210002  -  omer.turkdogdu@ogr.sakarya.edu.tr
**/ 
#include "DNA.hpp"
#include <iostream>

int main() {
    DNA dna;
    dna.dosyaOku();

    int secim;
    while (true) {
        std::cout << " 1- Caprazlama \n 2- Mutasyon \n 3- Otomatik Islemler \n 4- Ekrana Yazdir \n 5- Cikis \n";
        std::cin >> secim;

        if (secim == 1) {
            int k1, k2;
            std::cout << "Birinci Kromozom indexini giriniz : ";
            std::cin >> k1;
            std::cout << "Ikinci Kromozom indexini giriniz : ";
            std::cin >> k2;
            dna.caprazlama(k1, k2);
        } 
        else if (secim == 2) {
            int kromozomNo, genNo;
            std::cout << "Mutasyon icin kromozom indexini giriniz: ";
            std::cin >> kromozomNo;
            std::cout << "Mutasyon icin gen indexini giriniz: ";
            std::cin >> genNo;
            dna.mutasyon(kromozomNo, genNo);
        } 
        else if (secim == 3) {
            dna.otomatikIslem("Islemler.txt");
        } 
        else if (secim == 4) {
            dna.ekranaYaz();
        }
        else if (secim == 5) {
            break;
        } 
        else {
            std::cout << "Gecersiz secim.\n";
        }
    }
    return 0;
}
