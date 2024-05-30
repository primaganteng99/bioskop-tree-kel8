#include "../bioskopHead.h"
#include <stdio.h>
#include <time.h>

// Fungsi untuk mencetak tiket
void cetakTiket(char *film, char *jamTayang, char *kursi) {
    printf("\n====================\n");
    printf("     Tiket Bioskop\n");
    printf("====================\n");
    printf("Film      : %s\n", film);
    printf("Jam Tayang: %s\n", jamTayang);
    printf("Kursi     : %s\n", kursi);
    printf("====================\n");
}

// Fungsi untuk memeriksa apakah waktu saat ini sudah melebihi waktu tayang
bool cekWaktu(char *jamTayang) {
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[6];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, sizeof(buffer), "%H:%M", timeinfo);

    if (strcmp(buffer, jamTayang) > 0) {
        return false; // Waktu tayang sudah lewat
    }
    return true;
}

// Fungsi untuk memesan kursi
void pesanKursi(Node *bioskop) {
    char namaFilm[100], jamTayang[100], namaKursi[100];

    printf("\nMasukkan nama film: ");
    scanf("%s", namaFilm);

    Node *film = cariNode(bioskop, namaFilm);
    if (film == NULL) {
        printf("Film tidak ditemukan.\n");
        return;
    }

    printf("Masukkan jam tayang (JJ:MM): ");
    scanf("%s", jamTayang);

    if (!cekWaktu(jamTayang)) {
        printf("Waktu tayang sudah lewat, tidak bisa memesan.\n");
        return;
    }

    Node *jam = cariNode(film, jamTayang);
    if (jam == NULL) {
        printf("Jam tayang tidak ditemukan.\n");
        return;
    }

    printf("Masukkan nomor kursi: ");
    scanf("%s", namaKursi);

    Node *kursi = cariNode(jam, namaKursi);
    if (kursi == NULL) {
        printf("Kursi tidak ditemukan.\n");
        return;
    }

    if (strcmp(kursi->state, "full") == 0) {
        printf("Kursi sudah dipesan.\n");
        return;
    }

    strcpy(kursi->state, "full");
    saveTreeToFile(bioskop, "database/treeBioskop.txt");

    cetakTiket(namaFilm, jamTayang, namaKursi);
    printf("Kursi berhasil dipesan.\n");
}

void menuPesanTiket(Node *bioskop) {
    int pilihan;
    do {
        clearScreen();
        title();
        printf("\nMenu Pemesanan :\n");
        printf("1. Pesan Kursi\n");
        printf("2. Kembali\n");
        printf("Masukan Pilihan Menu : ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                clearScreen();
                title();
                pesanKursi(bioskop);
                system("pause");
                break;
            case 2:
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    } while (pilihan != 2);
}
