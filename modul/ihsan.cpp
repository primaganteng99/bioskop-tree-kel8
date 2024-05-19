#include "../bioskopHead.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// buat bikin node baru
Node* buatNode(char *judul) {
    Node *nodeBaru = (Node *)malloc(sizeof(Node));
    if (nodeBaru == NULL) {
        perror("Gagal mengalokasikan memori");
        exit(EXIT_FAILURE);
    }
    strcpy(nodeBaru->judul, judul);
    nodeBaru->jumlahAnak = 0;
    return nodeBaru;
}

// Buat nambahin waktu tayang ke film
void tambahWaktuTayang(Node *film, char *waktuMulai, int totalKursi) {
    if (film->jumlahAnak >= MAX_CHILDREN) {
        printf("Tidak dapat menambah lebih banyak waktu tayang, batas maksimum tercapai.\n");
        return;
    }
    int idx = film->jumlahAnak;
    strcpy(film->waktuTayang[idx].waktuMulai, waktuMulai);
    film->waktuTayang[idx].totalKursi = totalKursi;
    film->waktuTayang[idx].sisaKursi = totalKursi;
    film->jumlahAnak++;
}


void pesanTiket(Node *film, char *waktuMulai, int jumlahTiket) {
    for (int i = 0; i < film->jumlahAnak; i++) {
        if (strcmp(film->waktuTayang[i].waktuMulai, waktuMulai) == 0) {
            if (film->waktuTayang[i].sisaKursi >= jumlahTiket) {
                film->waktuTayang[i].sisaKursi -= jumlahTiket;
                printf("%d tiket berhasil dipesan untuk %s pada pukul %s.\n", jumlahTiket, film->judul, waktuMulai);
                return;
            } else {
            	
                printf("Tidak cukup kursi tersedia.\n");
                return;
            }
        }
    }
    printf("Waktu tayang tidak ditemukan.\n");
}

void tampilkanFilm(Node *film) {
    if (film != NULL) {
        printf("Film: %s\n", film->judul);
        for (int i = 0; i < film->jumlahAnak; i++) {
            printf("\tWaktu Tayang: %s, Kursi Tersedia: %d\n", film->waktuTayang[i].waktuMulai, film->waktuTayang[i].sisaKursi);
        }
    } else {
        printf("Tidak ada film yang tersedia.\n");
    }
}


void deallocBioskop(Node *film) {
    if (film != NULL) {
        free(film);
    }
}

void editFilm(Node *film) {
    printf("Masukkan judul film baru: ");
    scanf(" %[^\n]s", film->judul); // Membaca string dengan spasi
    printf("Judul film telah diubah menjadi '%s'\n", film->judul);
}

void editWaktuTayang(Node *film) {
    int idx;
    printf("Pilih indeks waktu tayang yang ingin diubah: ");
    for (int i = 0; i < film->jumlahAnak; i++) {
        printf("%d. %s, Kursi: %d\n", i + 1, film->waktuTayang[i].waktuMulai, film->waktuTayang[i].totalKursi);
    }
    scanf("%d", &idx);
    idx--;
    if (idx >= 0 && idx < film->jumlahAnak) {
        printf("Masukkan waktu tayang baru (format JJ:MM): ");
        scanf("%s", film->waktuTayang[idx].waktuMulai);
        printf("Masukkan total kursi: ");
        scanf("%d", &film->waktuTayang[idx].totalKursi);
        film->waktuTayang[idx].sisaKursi = film->waktuTayang[idx].totalKursi; // Reset sisa kursi
        printf("Waktu tayang diindeks %d telah diupdate.\n", idx + 1);
    } else {
        printf("Indeks tidak valid.\n");
    }
}


