/**       
*** @file        -- DnaIslemleri
*** @description -- Program DNA'nın içindeki Kromozom ve Gen bilgilerini kullanarak DNA'ya Çaprazlama ve Mutasyon gibi işlemlerin gerçekleştirilmesini sağlar
*** @course      -- 2.Öğretim B Grubu
*** @assignment  -- 1.Ödev
*** @date        -- 11.11.2024
*** @author      -- Ömer Faruk TÜRKDOĞDU  -  G231210002  -  omer.turkdogdu@ogr.sakarya.edu.tr
**/ 
#include "Kromozom.hpp"
#include <iostream>

Kromozom::Kromozom() : bas(nullptr) {}

Kromozom::~Kromozom() {
    Gen* gecici;
    while (bas) {
        gecici = bas;
        bas = bas->sonraki;
        delete gecici;
    }
}

void Kromozom::genEkle(const std::string& veri) {
    Gen* yeniGen = new Gen(veri);
    if (!bas) {
        bas = yeniGen;
    } 
    else {
        Gen* gecici = bas;
        while (gecici->sonraki) {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = yeniGen;
    }
}

void Kromozom::yazdir() const {
    Gen* gecici = bas;
    while (gecici) {
        std::cout << gecici->veri << " ";
        gecici = gecici->sonraki;
    }
    std::cout << std::endl;
}
