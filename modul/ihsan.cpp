#include "../bioskopHead.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WEEKDAY_PRICE 35000
#define WEEKEND_PRICE 45000

// Fungsi untuk menampilkan film dan jam tayang yang tersedia
void tampilkanFilmDanJamTayangHelper(Node *node, int depth) {
    if (node == NULL) return;

    // Jika node adalah film dan levelnya kurang dari 4, cetak namanya
    if (strcmp(node->state, "empty") == 0 && depth < 4) {
        printf("%*s%s\n", depth * 4, "", node->nama);
    }

    // Panggil fungsi rekursif untuk anak-anak dari node saat ini
    tampilkanFilmDanJamTayangHelper(node->firstSon, depth + 1);
    // Panggil fungsi rekursif untuk saudara kandung dari node saat ini
    tampilkanFilmDanJamTayangHelper(node->nextBrother, depth);
}

void tampilkanFilmDanJamTayang(Node *bioskop) {
    // Panggil fungsi helper dengan node bioskop dan depth 0
    tampilkanFilmDanJamTayangHelper(bioskop, 0);
}
// Fungsi untuk menampilkan diagram kursi beserta nama kursi
void tampilkanDiagramKursi(Node *jamTayang) {
    printf("Posisi Kursi:\n");
    printf("------------------------------------------------------------------------------------------");
    printf("\n			               S C R E E N			            \n");
    printf("------------------------------------------------------------------------------------------\n");
    Node *kursi = jamTayang->firstSon;
    int count = 0;
    while (kursi != NULL) {
        printf("(%s) ", kursi->nama); // Menampilkan nama kursi
        if (strcmp(kursi->state, "empty") == 0) {
            printf("[ ] "); // Kursi kosong
        } else {
            printf("[X] "); // Kursi terisi
        }
        count++;
        if (count % 10 == 0) { // Asumsikan 10 kursi per baris
            printf("\n");
        }
        kursi = kursi->nextBrother;
    }
    if (count % 10 != 0) {
        printf("\n");
    }
    printf("\n");
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
    int adaKursiTersedia = 0;
    while (kursi != NULL) {
        if (strcmp(kursi->state, "empty") == 0) {
            printf("%s ", kursi->nama);
            adaKursiTersedia = 1;
        }
        kursi = kursi->nextBrother;
    }
    if (!adaKursiTersedia) {
        printf("Tidak ada kursi tersedia.");
    }
    printf("\n");
}

// Fungsi untuk memesan tiket
void pesanTiket(Node *bioskop) {
    if (bioskop == NULL) {
        bioskop = muatTreeDariFile("database/treeBioskop.txt");
    }
    if (bioskop == NULL) {
        printf("\nBioskop Belum Dikelola\n");
        return;
    }

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

    printf("Masukkan jam tayang (format HH:MM): ");
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

    // Check if there are available seats for the chosen showtime
    int adaKursiTersedia = 0;
    Node *kursi = jamTayang->firstSon;
    while (kursi != NULL) {
        if (strcmp(kursi->state, "empty") == 0) {
            adaKursiTersedia = 1;
            break;
        }
        kursi = kursi->nextBrother;
    }

    if (!adaKursiTersedia) {
        printf("Tidak ada kursi tersedia untuk jam tayang ini.\n");
        return;
    }

    tampilkanDiagramKursi(jamTayang); // Menampilkan diagram kursi

    while (1) {
        printf("Masukkan jumlah kursi yang ingin dipesan: ");
        scanf("%d", &jumlahKursi);

        int jumlahKursiTersedia = 0;
        kursi = jamTayang->firstSon;
        while (kursi != NULL) {
            if (strcmp(kursi->state, "empty") == 0) {
                jumlahKursiTersedia++;
            }
            kursi = kursi->nextBrother;
        }

        if (jumlahKursi <= jumlahKursiTersedia) {
            break;
        } else {
            printf("\n--Jumlah kursi yang ingin dipesan melebihi jumlah kursi yang tersedia. Silakan masukkan ulang.--\n");
        }
    }

    char kursiDipesan[jumlahKursi][100];
    int kursiDipilih = 0;
    char buffer[100]; // untuk menampung input
    while (kursiDipilih < jumlahKursi) {
        printf("Masukkan nomor kursi yang ingin dipesan (%d dari %d): ", kursiDipilih + 1, jumlahKursi);
        scanf("%s", kursiDipesan[kursiDipilih]);

        Node *kursi = cariNode(jamTayang, kursiDipesan[kursiDipilih]);
        if (kursi == NULL || strcmp(kursi->state, "full") == 0) {
            printf("Kursi tidak tersedia. Silakan pilih kursi lain.\n");
        } else {
            kursiDipilih++;
        }
    }

    // Calculate total price
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int totalHarga = 0;

    if (tm.tm_wday >= 1 && tm.tm_wday <= 5) { // Weekdays (Monday to Friday)
        totalHarga = jumlahKursi * WEEKDAY_PRICE;
    } else { // Weekends (Saturday and Sunday)
        totalHarga = jumlahKursi * WEEKEND_PRICE;
    }

    printf("\nDetail Pesanan:\n");
    printf("\n---------------------\n");
    printf("Film: %s\n", namaFilm);
    printf("Jam Tayang: %s\n", namaJamTayang);
    printf("Kursi yang dipesan: ");
    for (int i = 0; i < jumlahKursi; i++) {
        printf("%s ", kursiDipesan[i]);
    }
    printf("\nTotal Harga: Rp %d\n", totalHarga);
    printf("\n---------------------\n");
    printf("Lanjutkan pembayaran? (iya/tidak): ");
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
    printf("\n=============================================\n");
    printf("            SELAMAT MENONTON MANIEZ\n");
    printf("=============================================\n");
    printf("\n");
}
