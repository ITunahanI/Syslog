#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Günlük (Log) verisini temsil eden yapı (Node)
// Çift yönlü bağlı liste (Doubly Linked List) kullanılmıştır.
typedef struct LogNode {
    char log_data[1024];        // Log satırının içeriği
    struct LogNode *next_node;  // Sonraki düğüme işaretçi
    struct LogNode *prev_node;  // Önceki düğüme işaretçi
} LogNode;

// Yeni bir log düğümü oluşturan fonksiyon
LogNode* create_new_log_node(const char *data) {
    LogNode *new_node = (LogNode*)malloc(sizeof(LogNode));
    if (new_node == NULL) {
        printf("Bellek hatasi!\n");
        exit(1);
    }
    strncpy(new_node->log_data, data, 1024);
    new_node->next_node = NULL;
    new_node->prev_node = NULL;
    return new_node;
}

// Listenin sonuna yeni bir log ekleyen fonksiyon
void append_log_to_list(LogNode **head_ref, const char *data) {
    LogNode *new_node = create_new_log_node(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    LogNode *last = *head_ref;
    while (last->next_node != NULL) {
        last = last->next_node;
    }
    last->next_node = new_node;
    new_node->prev_node = last;
}

// Bağlı listedeki tüm logları ekrana yazdıran fonksiyon
void display_logs(LogNode *node) {
    printf("\n--- Sistem Gunlukleri (Bagli Liste) ---\n");
    while (node != NULL) {
        printf("%s", node->log_data);
        node = node->next_node;
    }
}

// Belleği temizleyen (free) fonksiyon
void free_log_list(LogNode *head) {
    LogNode *temp;
    while (head != NULL) {
        temp = head;
        head = head->next_node;
        free(temp);
    }
}

int main() {
    LogNode *log_list_head = NULL;
    FILE *file_ptr;
    char line[1024];

    // Linux sistem gunluk dosyasi aciliyor
    // Eger bu dosya okunamazsa (yetki sorunu), yerel bir ornek dosya okunabilir.
    file_ptr = fopen("/var/log/syslog", "r");
    if (file_ptr == NULL) {
        printf("Uyari: /var/log/syslog okunamadi. Lütfen 'sample_logs.txt' dosyasini kullandiginizdan emin olun.\n");
        file_ptr = fopen("sample_logs.txt", "r");
    }

    if (file_ptr == NULL) {
        printf("Hata: Herhangi bir log dosyasi bulunamadi!\n");
        return 1;
    }

    // Dosyadan satirlari oku ve bagli listeye ekle
    int count = 0;
    while (fgets(line, sizeof(line), file_ptr) && count < 50) { // Test icin ilk 50 satir
        append_log_to_list(&log_list_head, line);
        count++;
    }

    fclose(file_ptr);

    // Listeyi goster
    display_logs(log_list_head);

    // Bellegi bosalt
    free_log_list(log_list_head);

    return 0;
}
