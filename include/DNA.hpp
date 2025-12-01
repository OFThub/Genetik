/**       
*** @file        -- DnaIslemleri
*** @description -- Program DNA'nın içindeki Kromozom ve Gen bilgilerini kullanarak DNA'ya Çaprazlama ve Mutasyon gibi işlemlerin gerçekleştirilmesini sağlar
*** @course      -- 2.Öğretim B Grubu
*** @assignment  -- 1.Ödev
*** @date        -- 11.11.2024
*** @author      -- Ömer Faruk TÜRKDOĞDU  -  G231210002  -  omer.turkdogdu@ogr.sakarya.edu.tr
**/ 
#ifndef DNA_HPP
#define DNA_HPP

#include <string>
struct DNAKromozomNode {
    std::string kromozom;  
    DNAKromozomNode* sonraki = nullptr; 
};
class DNA {
private:
    DNAKromozomNode* bas;  

public:
    DNA();  
    ~DNA();  

    void dosyaOku();  
    DNAKromozomNode* kromozomBul(int satir); 
    void caprazlama(int k1, int k2);  
    void mutasyon(int kromozomNo, int genNo);  
    void otomatikIslem(const std::string& dosyaAdi);  
    void ekranaYaz(); 
    void dosyayaEkle(const std::string& dosyaAdi, const std::string& yeniKromozom);
};

#endif
