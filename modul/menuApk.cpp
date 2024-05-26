#include "../bioskopHead.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int mainMenu(){
    int pilihan;

    printf("1. Login\n");
    printf("2. Register\n");
    printf("3. Keluar\n");
    printf("Masukkan pilihan Anda: ");
    scanf("%d", &pilihan);
    return pilihan;
}
    
void menuPesan(char *waktu, int *jumlahTiket){
	printf("Masukkan waktu tayang (JJ:MM): ");
 	scanf("%s", waktu);
  	printf("Masukkan jumlah tiket: ");
   	scanf("%d", jumlahTiket);
}

void menuMasuk(int *pilihan2){
	printf("\nMenu Utama :\n");
	printf("1. Kelola Bioskop\n");
	printf("2. Pemesanan\n");
	printf("3. Histori Pemesanan\n");
	printf("4. Kontol\n");
	printf("5. Logout\n");
	printf("Masukan Pilihan Menu : ");
	scanf("%d",pilihan2);
}

void menuBioskop(int *pilihan3){
	printf("\nMenu Kelola :\n");
	printf("1. Tambah Studio\n");
 	printf("2. Tambah Film\n");
  	printf("3. Tambah Jam Tayang\n");
   	printf("4. Tambah Kursi\n");
   	printf("5. Tampilkan Tree\n");
   	printf("6. Cari Node\n");
   	printf("7. Hapus Node\n");
   	printf("8. Keluar\n");
   	printf("Pilih opsi: ");
   	scanf("%d", pilihan3);
}

void menuHapus(int *pilihan4) {
    printf("\nMenu Hapus :\n");
    printf("1. Hapus Studio\n");
    printf("2. Hapus Film\n");
    printf("3. Hapus Jam Tayang\n");
    printf("4. Hapus Kursi\n");
    printf("5. Kembali\n");
    printf("Pilih opsi: ");
    scanf("%d", pilihan4);
}

void title(){
	FILE *file = fopen("database/grafiti.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Gagal membuka file list_barang.txt.\n");
        return;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
		printf(" %s", buffer);
    }
    printf("\n");

    fclose(file);
}

void clearScreen(){
	system("cls");
}
