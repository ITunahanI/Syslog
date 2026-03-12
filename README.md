# Linux Syslog İşleme Uygulaması (Linked List)

Bu proje, Linux işletim sistemindeki sistem günlüklerini (syslog) anlamak ve bu verileri **Çift Yönlü Bağlı Liste (Doubly Linked List)** veri yapısı kullanarak hafızada depolamak amacıyla geliştirilmiştir.

## Teknik Detaylar
- **Syslog Nedir?**: İşletim sistemi ve uygulamalar tarafından üretilen tüm mesajların merkezi bir dosyada tutulmasıdır.
- **Seçilen Veri Yapısı**: Çift Yönlü Bağlı Liste.
- **Tercih Sebebi**: Log kayıtları zaman sırasına göre eklenir. Çift yönlü liste, hem en güncel kayıtlara (sona) hızlı erişim sağlar hem de loglar arasında ileri-geri tarama yapmayı kolaylaştırır.

## Kurulum ve Çalıştırma
Sisteminizde `gcc` yüklü olmalıdır.

1. Depoyu klonlayın:
   ```bash
   git clone https://github.com/ITunahanI/Syslog
