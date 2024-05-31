#include "../bioskopHead.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

void registerAdmin(char *username, char *password){
	
	printf("\n--------------\n");
	printf("| Registrasi |\n");
	printf("--------------\n");
	printf("Username : ");
	scanf("%s",username);
	
	printf("Password : ");
	scanf("%s",password);
	
	FILE *file = fopen("database/adminAccount.txt", "r");
	if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }
    rewind(file);
    
    char storedUsername[MAX_USERNAME_LENGTH];
    char storedPassword[MAX_PASSWORD_LENGTH];
	
	    while (fscanf(file, "%s %s\n", storedUsername, storedPassword) == 2) {
        if (strcmp(username, storedUsername) == 0) {
            fclose(file);
            printf("====================\n");
    		printf("= Registrasi Gagal =\n");
    		printf("====================\n");
            printf("Username sudah digunakan.\n");

            return;
        }
	}
	fclose(file);
	
	file = fopen("database/adminAccount.txt", "a");
	if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }
    
    fprintf(file, "%s %s\n", username, password);
    fclose(file);
    
    printf("=======================\n");
    printf("= Registrasi berhasil =\n");
    printf("=======================\n");
}

int mainMenu(){
    int pilihan;
	printf("\nSelamat Datang :\n");
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
	printf("3. Logout\n");
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

void hapusNodeEx(Node *bioskop) {
    int pilihan4;
    do {
        clearScreen();
        title();
        menuHapus(&pilihan4);
        switch (pilihan4) {
            case 1:
                clearScreen();
                title();
                tampilkanTree(bioskop);
                hapusStudio(bioskop);
                system("pause");
                break;
            case 2:
                clearScreen();
                title();
                tampilkanTree(bioskop);
                hapusFilm(bioskop);
                system("pause");
                break;
            case 3:
                clearScreen();
                title();
                tampilkanTree(bioskop);
                hapusJamTayang(bioskop);
                system("pause");
                break;
            case 4:
                clearScreen();
                title();
                tampilkanTree(bioskop);
                hapusKursi(bioskop);
                system("pause");
                break;
            case 5:
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    } while (pilihan4 != 5);
}

void menuPesan(Node *bioskop) {
    int pilihan5;
    do {
        clearScreen();
        title();
        	printf("\nMenu Pemesanan :\n");
    printf("1. Pesan Tiket\n");
    printf("2. Lihat RIwayat\n");
    printf("3. Kembali\n");
    printf("Masukkan pilihan Anda: ");
    scanf("%d", &pilihan5);
        switch (pilihan5) {
            case 1:
                clearScreen();
                title();
                pesanTiket(bioskop);
                system("pause");
                break;
            case 2:
                clearScreen();
                title();
                system("pause");
                break;
            case 3:
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    } while (pilihan5 != 3);
}

void title(){
	FILE *file = fopen("database/grafiti.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Gagal membuka file grafiti.txt.\n");
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
