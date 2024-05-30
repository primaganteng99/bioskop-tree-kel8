#include "../bioskopHead.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Fungsi untuk menampilkan film dan jam tayang yang tersedia
void tampilkanFilmDanJamTayang(Node *bioskop) {
    if (bioskop == NULL) return;

    if (bioskop->firstSon != NULL && strcmp(bioskop->firstSon->state, "empty") == 0) {
        printf("Film: %s\n", bioskop->nama);
        Node *film = bioskop->firstSon;
        while (film != NULL) {
            printf("  Jam Tayang: %s\n", film->nama);
            film = film->nextBrother;
        }
    }
    tampilkanFilmDanJamTayang(bioskop->firstSon);
    tampilkanFilmDanJamTayang(bioskop->nextBrother);
}

// Fungsi untuk memeriksa apakah waktu telah melewati jam tayang
int waktuSudahMelewati(char *jamTayang) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    int jam, menit;
    sscanf(jamTayang, "%d:%d", &jam, &menit);

    if (tm.tm_hour > jam || (tm.tm_hour == jam && tm.tm_min > menit)) {
        return 1;
    }
    return 0;
}

// Fungsi untuk menampilkan kursi yang tersedia untuk jam tayang yang dipilih
void tampilkanKursiTersedia(Node *jamTayang) {
    printf("Kursi Tersedia:\n");
    Node *kursi = jamTayang->firstSon;
    while (kursi != NULL) {
        if (strcmp(kursi->state, "empty") == 0) {
            printf("%s ", kursi->nama);
        }
        kursi = kursi->nextBrother;
    }
    printf("\n");
}

// Fungsi untuk memesan tiket
void pesanTiket(Node *bioskop) {
    char namaFilm[100], namaJamTayang[100];
    int jumlahKursi;

    printf("\nFilm dan Jam Tayang yang Tersedia:\n");
    tampilkanFilmDanJamTayang(bioskop);

    printf("\nMasukkan nama film: ");
    scanf("%s", namaFilm);
    Node *film = cariNode(bioskop, namaFilm);
    if (film == NULL) {
        printf("Film tidak ditemukan.\n");
        return;
    }

    printf("Masukkan jam tayang: ");
    scanf("%s", namaJamTayang);
    Node *jamTayang = cariNode(film, namaJamTayang);
    if (jamTayang == NULL) {
        printf("Jam tayang tidak ditemukan.\n");
        return;
    }

    if (waktuSudahMelewati(namaJamTayang)) {
        printf("Waktu sudah melewati jam tayang.\n");
        return;
    }

    tampilkanKursiTersedia(jamTayang); // Menampilkan kursi yang tersedia

    while (1) {
        printf("Masukkan jumlah kursi yang ingin dipesan: ");
        scanf("%d", &jumlahKursi);

        int jumlahKursiTersedia = 0;
        Node *kursi = jamTayang->firstSon;
        while (kursi != NULL) {
            if (strcmp(kursi->state, "empty") == 0) {
                jumlahKursiTersedia++;
            }
            kursi = kursi->nextBrother;
        }

        if (jumlahKursi <= jumlahKursiTersedia) {
            break;
        } else {
            printf("Jumlah kursi yang ingin dipesan melebihi jumlah kursi yang tersedia. Silakan masukkan ulang.\n");
        }
    }

    char kursiDipesan[jumlahKursi][100];
    int kursiDipilih = 0;
    char buffer[100]; // untuk menampung input
    while (kursiDipilih < jumlahKursi) {
        printf("Masukkan nomor kursi yang ingin dipesan (%d dari %d): ", kursiDipilih + 1, jumlahKursi);
        // menggunakan fgets untuk membaca input
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%s", kursiDipesan[kursiDipilih]);

        Node *kursi = cariNode(jamTayang, kursiDipesan[kursiDipilih]);
        if (kursi == NULL || strcmp(kursi->state, "full") == 0) {
            printf("Kursi tidak tersedia. Silakan pilih kursi lain.\n");
        } else {
            kursiDipilih++;
        }
    }

    printf("\nDetail Pesanan:\n");
    printf("Film: %s\n", namaFilm);
    printf("Jam Tayang: %s\n", namaJamTayang);
    printf("Kursi yang dipesan: ");
    for (int i = 0; i < jumlahKursi; i++) {
        printf("%s ", kursiDipesan[i]);
    }
    printf("\nLanjutkan pembayaran? (iya/tidak): ");
    char konfirmasi[10];
    scanf("%s", konfirmasi);

    if (strcmp(konfirmasi, "iya") == 0) {
        for (int i = 0; i < jumlahKursi; i++) {
            Node *kursi = cariNode(jamTayang, kursiDipesan[i]);
            if (kursi != NULL) {
                strcpy(kursi->state, "full");
            }
        }
        saveTreeToFile(bioskop, "database/treeBioskop.txt");
        printf("Pembayaran berhasil. Tiket telah dicetak.\n");
        cetakTiket(namaFilm, namaJamTayang, kursiDipesan, jumlahKursi); // Memanggil prosedur cetakTiket
    } else {
        printf("Pesanan dibatalkan.\n");
    }
}

void cetakTiket(char *namaFilm, char *namaJamTayang, char kursiDipesan[][100], int jumlahKursi) {
    printf("\n=============================================\n");
    printf("            Tiket Bioskop\n");
    printf("=============================================\n");
    printf("Film: %s\n", namaFilm);
    printf("Jam Tayang: %s\n", namaJamTayang);
    printf("Kursi yang dipesan: ");
    for (int i = 0; i < jumlahKursi; i++) {
        printf("%s ", kursiDipesan[i]);
    }
}

