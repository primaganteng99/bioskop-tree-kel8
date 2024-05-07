#include "bioskopHead.h"
#include <stdio.h>
#include <string.h>

int main() {
	
    Node *bioskop = buatNode("Siksa Kubur");
    tambahWaktuTayang(bioskop, "10:00", 20);
    tambahWaktuTayang(bioskop, "14:00", 20);
    tambahWaktuTayang(bioskop, "20:00", 20);

    int pilihan, jumlahTiket;
    char waktu[10];

    while (1) {
        pilihan = mainMenu();

        switch (pilihan) {
            case 1:
                tampilkanFilm(bioskop);
                break;
            case 2:
                menuPesan(waktu, &jumlahTiket);
                printf("\n%s %d", waktu, jumlahTiket);
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

