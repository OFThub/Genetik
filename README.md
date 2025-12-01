# Genetik
Bu proje, C++ kullanarak bağlı listeler (Linked Lists) ile genetik algoritmaların temel adımları olan Çaprazlama (Crossover) ve Mutasyon (Mutation) işlemlerini simüle eden bir uygulamadır. Veri yapısı olarak bağlı listelerin kullanılması, büyük veri setlerinin (gen, kromozom) etkin yönetimini ve bellek verimliliğini sağlamayı amaçlamaktadır.

🧬 Genetik Simülasyon Uygulaması (C++ ve Bağlı Listeler)
Bu proje, bir DNA dosyasından okunan kromozomlar üzerinde temel genetik işlemleri (Çaprazlama, Mutasyon) gerçekleştiren, MinGW C++ ortamında derlenen bir konsol uygulamasıdır. Veri yapıları, dinamik boyutlu gen ve kromozom verilerini yönetmek için bağlı listeler kullanılarak tasarlanmıştır.

🛠️ Proje Teknolojileri ve Mimarisi
Programlama Dili: C++

Derleyici: MinGW C++

Veri Yapısı: Bağlı Listeler (Linked Lists - std::list veya özel implementasyon) kullanılarak Kromozom ve DNA verileri tutulacaktır (ArrayList hariç).

Bellek Yönetimi: Program, büyük dosyaları okuyabilecek şekilde tasarlanmalı ve bellek sızıntılarına (Memory Leaks) karşı optimize edilmelidir.

📁 Giriş Dosyaları
1. Dna.txt
Uygulamanın başlangıç popülasyonunu içerir.

Her satır bir Kromozomu temsil eder.

Kromozomlar, boşluklarla ayrılmış Genlerden oluşur.

Örnek:

A B C D E F G
H I J K L
M N O P
A B C D
...
2. Islemler.txt (Otomatik İşlemler İçin)
Otomatik olarak uygulanacak işlemleri ve parametrelerini içerir.

C: Çaprazlama (Crossover)

M: Mutasyon (Mutation)

Örnek: C 1 3 (1. ve 3. kromozomları çaprazla)

🌐 Uygulama Menüsü
Geliştirilen program aşağıdaki seçenekleri kullanıcıya sunmalıdır:

Çaprazlama (Crossover)

Mutasyon (Mutation)

Otomatik İşlemler

Ekrana Yaz

Çıkış

⚙️ Fonksiyonel Detaylar
1. Çaprazlama (Crossover - C)
Kullanıcıdan alınan iki kromozom satır numarası (0'dan başlayarak) üzerinde çaprazlama yapılır ve iki yeni kromozom popülasyona eklenir.

İşlem: İlk kromozomun orta noktasının sol tarafı, ikinci kromozomun orta noktasının sağ tarafı ile birleştirilir (Yeni Kromozom 1). Tersi de yapılarak Yeni Kromozom 2 oluşturulur.

Tek Gen Sayısı: Tek sayıda gen içeren kromozomlarda ortadaki gen yeni kromozomlara dahil edilmez.

Çift Gen Sayısı: Çift sayıda gen içeren kromozomlarda orta nokta, tam ortadaki iki gen arasından bölünür.

2. Mutasyon (Mutation - M)
Kullanıcıdan kromozom satır numarası ve gen sütun numarası alınarak ilgili gen mutasyona uğratılır.

İşlem: Belirtilen konumdaki gen, sabit bir karakter olan X karakterine dönüştürülür.

3. Otomatik İşlemler
Program, Islemler.txt dosyasını okuyarak içerisinde belirtilen tüm Çaprazlama (C) ve Mutasyon (M) işlemlerini sırayla uygular.

4. Ekrana Yaz
Özel bir kurala göre, her kromozomdan tek bir gen seçilir ve ekrana yazdırılır.

Kural: Her kromozomda sağdan sola doğru gidilir.

Seçim: Kromozomun ilk geninden daha küçük bir gen (alfabetik olarak veya ASCII değeri olarak) bulunduğu anda, bu gen o kromozom için ekrana yazdırılacak gen olarak belirlenir ve arama durdurulur.

Varsayım: Eğer ilk gene kadar daha küçük bir gen bulunamazsa, ilk gen ekrana yazdırılır.

5. Çıkış
Programın güvenli bir şekilde sonlandırılması ve dinamik olarak ayrılan belleğin (bağlı listeler) temizlenmesi beklenir. Çöp oluşumuna (Memory Leak) kesinlikle izin verilmemelidir.
