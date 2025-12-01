/**       
*** @file        -- DnaIslemleri
*** @description -- Program DNA'nın içindeki Kromozom ve Gen bilgilerini kullanarak DNA'ya Çaprazlama ve Mutasyon gibi işlemlerin gerçekleştirilmesini sağlar
*** @course      -- 2.Öğretim B Grubu
*** @assignment  -- 1.Ödev
*** @date        -- 11.11.2024
*** @author      -- Ömer Faruk TÜRKDOĞDU  -  G231210002  -  omer.turkdogdu@ogr.sakarya.edu.tr
**/ 
#ifndef GEN_HPP
#define GEN_HPP
#include <iostream>
using namespace std;

class Gen {
public:
    std::string veri;
    Gen* sonraki;
    
    Gen(std::string veri);
};


#endif