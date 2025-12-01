/**       
*** @file        -- DnaIslemleri
*** @description -- Program DNA'nın içindeki Kromozom ve Gen bilgilerini kullanarak DNA'ya Çaprazlama ve Mutasyon gibi işlemlerin gerçekleştirilmesini sağlar
*** @course      -- 2.Öğretim B Grubu
*** @assignment  -- 1.Ödev
*** @date        -- 11.11.2024
*** @author      -- Ömer Faruk TÜRKDOĞDU  -  G231210002  -  omer.turkdogdu@ogr.sakarya.edu.tr
**/ 
#ifndef KROMOZOM_HPP
#define KROMOZOM_HPP
#include "Gen.hpp"
#include <iostream>
using namespace std;

class Kromozom {
public:
    Gen* bas;
    Kromozom();
    ~Kromozom();
    
    void genEkle(const std::string& veri);
    void yazdir() const;
};

#endif