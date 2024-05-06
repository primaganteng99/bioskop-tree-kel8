#include "bioskopHead.h"
#include <stdio.h>
#include <string.h>

int main() {
	
    Node *bioskop = buatNode("Siksa Kubur");
    tambahWaktuTayang(bioskop, "10:00", 100);
    tambahWaktuTayang(bioskop, "14:00", 150);
    tambahWaktuTayang(bioskop, "20:00", 200);

    int pilihan, jumlahTiket;
    char waktu[10];

    while (1) {
        printf("\nSistem Pemesanan Tiket Bioskop\n");
        printf("1. Tampilkan film yang tersedia\n");
        printf("2. Pesan tiket\n");
        printf("3. Keluar\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tampilkanFilm(bioskop);
                break;
            case 2:
                printf("Masukkan waktu tayang (JJ:MM): ");
                scanf("%s", waktu);
                printf("Masukkan jumlah tiket: ");
                scanf("%d", &jumlahTiket);
                pesanTiket(bioskop, waktu, jumlahTiket);
                break;
            case 3:
                deallocBioskop(bioskop);
                printf("Keluar dari sistem.\n");
                return 0;
            default:
                printf("Pilihan tidak valid, silakan coba lagi.\n");
        }
    }

    return 0;
}

