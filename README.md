
# Smart Refrigerator & Material Management System

Bu proje, C dili ile geliştirilmiş bir malzeme yönetimi ve akıllı buzdolabı simülasyonudur. Proje; buzdolabı veya kiler stoklarını takip etmeyi, son tüketim tarihlerini denetlemeyi ve mevcut malzemelere göre yemek tarifi önermeyi amaçlar.

---

## 📌 Özellikler

### 1. Malzeme Yönetimi (Material Management)
- **Malzeme Ekleme:** Malzeme adı, miktarı ve son tüketim tarihi (STT) ile yeni kayıt ekleme.
- **Miktar Güncelleme:** Önceden eklenmiş bir malzeme tekrar girildiğinde var olan miktarın otomatik artırılması.
- **Otomatik Alfabetik Sıralama:** Eklenen her yeni malzemeden sonra tüm listenin alfabetik olarak sıralanması (Bubble Sort).
- **Malzeme Çıkarma / Tüketme:** İstenen miktarda malzeme eksiltme; miktar sıfıra ulaştığında malzemenin listeden tamamen silinmesi.
- **Malzeme Listesi:** Stoktaki tüm malzemelerin ad, miktar ve STT bilgileriyle listelenmesi.

### 2. Akıllı Buzdolabı Sistemi (Smart Refrigerator System)
- **Son Tüketim Tarihi Kontrolü (Expiration Date Check):** Kullanıcı tarafından girilen güncel tarihe göre süresi geçmiş malzemelerin tespiti ve listelenmesi.
- **Tarif Önerisi (Recipe Suggestion):** Stokta bulunan malzemeleri analiz ederek yapılabilecek uygun tariflerin (Cips, Menemen, Krep, Tost vb.) otomatik önerilmesi.

---

## 🛠️ Kurulum ve Çalıştırma

Projeyi GCC veya herhangi bir standart C derleyicisi kullanarak yerel makinenizde çalıştırabilirsiniz.

### 1. Projeyi Derleme
Terminal veya komut istemcisinde (proje dizinindeyken) şu komutu çalıştırın:
```bash
gcc 230709036_sevinc_agalioglu.c.c -o smart_fridge
