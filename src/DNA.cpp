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
#include <fstream>
#include <sstream>

// DNA sınıfı kurucu ve yıkıcı fonksiyonlar
DNA::DNA() : bas(nullptr) {}

DNA::~DNA() {
    DNAKromozomNode* gecici;

    while (bas) {
        gecici = bas;
        bas = bas->sonraki;
        delete gecici;
    }
}

// DNA.txt dosyasından kromozomlar okunur
void DNA::dosyaOku() {
    std::ifstream Oku("Dna.txt");  

    if (!Oku) {
        std::cerr << "Dosya acilamadi!" << std::endl;
        return;
    }

    std::string kromozom;
    int sayac = 1;

    while (getline(Oku, kromozom)) {  
        std::cout << sayac << ". Kromozom: " << kromozom << std::endl;
        
        DNAKromozomNode* yeniKromozom = new DNAKromozomNode;
        yeniKromozom->kromozom = kromozom;
        yeniKromozom->sonraki = nullptr;

        if (bas == nullptr) {
            bas = yeniKromozom;
        } else {
            DNAKromozomNode* gecici = bas;
            while (gecici->sonraki != nullptr) {
                gecici = gecici->sonraki;
            }
            gecici->sonraki = yeniKromozom;
        }
        
        ++sayac;
    }
    Oku.close();
}

// Kromozom bulma
DNAKromozomNode* DNA::kromozomBul(int satir) {
    DNAKromozomNode* gecici = bas;
    int sayac = 0;

    while (gecici && sayac < satir) {
        gecici = gecici->sonraki;
        sayac++;
    }
    return gecici;
}

// Çaprazlama işlemi
void DNA::caprazlama(int k1, int k2) {
    DNAKromozomNode* kromozom1 = kromozomBul(k1);
    DNAKromozomNode* kromozom2 = kromozomBul(k2);

    if (kromozom1 && kromozom2) {
        int orta1 = kromozom1->kromozom.size() / 2;
        int orta2 = kromozom2->kromozom.size() / 2;

        std::string solKisim = kromozom1->kromozom.substr(0, orta1);
        std::string sagKisim = kromozom2->kromozom.substr(orta2);

        if (!solKisim.empty() && solKisim.back() == ' ') solKisim.pop_back();
        if (!sagKisim.empty() && sagKisim.front() == ' ') sagKisim.erase(0, 1);

        std::string yeniKromozom1 = solKisim + " " + sagKisim;

        solKisim = kromozom2->kromozom.substr(0, orta2);
        sagKisim = kromozom1->kromozom.substr(orta1);

        if (!solKisim.empty() && solKisim.back() == ' ') solKisim.pop_back();
        if (!sagKisim.empty() && sagKisim.front() == ' ') sagKisim.erase(0, 1);

        std::string yeniKromozom2 = solKisim + " " + sagKisim;

        dosyayaEkle("Dna.txt", yeniKromozom1);
        dosyayaEkle("Dna.txt", yeniKromozom2);
    } else {
        std::cout << "Gecersiz satir indexi girildi." << std::endl;
    }
}

// Mutasyon işlemi
void DNA::mutasyon(int kromozomNo, int genNo){
    DNAKromozomNode* hedefKromozom = kromozomBul(kromozomNo);

    if (!hedefKromozom) {
        std::cout << "Gecersiz kromozom indexi." << std::endl;
        return;
    }

    int genSayaci = 0;
    for (auto it = hedefKromozom->kromozom.begin(); it != hedefKromozom->kromozom.end(); ++it) {
        if (*it != ' ') {
            if (genSayaci == genNo) {
                *it = 'X';
                std::cout << hedefKromozom->kromozom << std::endl;
                dosyayaEkle("Dna.txt", hedefKromozom->kromozom);
                return;
            }
            genSayaci++;
        }
    }
    std::cout << "Geçersiz gen indexi." << std::endl;
}

// Otomatik işlem
void DNA::otomatikIslem(const std::string& dosyaAdi){
    std::ifstream dosya(dosyaAdi);

    if (!dosya) {
        std::cerr << "Dosya acilamadi: " << dosyaAdi << std::endl;
        return;
    }

    std::string satir;
    while (getline(dosya, satir)) {
        std::istringstream iss(satir);
        char islemTuru;
        int param1, param2;

        if (!(iss >> islemTuru >> param1 >> param2)) {
            std::cerr << "Gecersiz islem: " << satir << std::endl;
            continue;
        }

        if (islemTuru == 'C') {  
            caprazlama(param1, param2);
        } 
        else if (islemTuru == 'M') {  
            mutasyon(param1, param2);
        } 
        else {
            std::cerr << "Bilinmeyen islem turu: " << islemTuru << std::endl;
        }
    }

    dosya.close();
    std::cout << "Islem tamamlandi." << std::endl;
}

// Kromozomları ekrana yazdırma
void DNA::ekranaYaz() {
    DNAKromozomNode* gecici = bas;
    int kromozomNo = 1;

    while (gecici) {
        std::cout << kromozomNo << ". Kromozom: ";
        std::string kromozom = gecici->kromozom;

        if (!kromozom.empty()) {
            char yazilacakGen = kromozom[0];
            bool kucukGenBulundu = false;

            for (int i = kromozom.size() - 1; i > 0; --i) {
                char gen = kromozom[i];
                if (gen == ' ') continue;

                if (gen < yazilacakGen) {
                    yazilacakGen = gen;
                    kucukGenBulundu = true;
                    break;
                }
            }

            std::cout << yazilacakGen;
        }

        if (gecici->sonraki != nullptr) {
            std::cout << " ";
        }

        gecici = gecici->sonraki;
        ++kromozomNo;
    }

    std::cout << std::endl;
}

// Yeni kromozomları dosyaya ekleyen fonksiyon
void DNA::dosyayaEkle(const std::string& dosyaAdi, const std::string& yeniKromozom) {
    std::ofstream dosya(dosyaAdi, std::ios::app); 

    if (!dosya) {
        std::cerr << "Dosya acilamadi: " << dosyaAdi << std::endl;
        return;
    }

    dosya << yeniKromozom << std::endl;
    dosya.close();

    std::cout << "Yeni kromozom dosyaya eklendi: " << yeniKromozom << std::endl;
}