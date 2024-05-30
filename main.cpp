	#include "bioskopHead.h"
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <windows.h>
	
	int main() {
	    int pilihan;
	    char username[50], password[50];
	    Node *bioskop = NULL;
	    int pilihan2; 
	    
	    while (1) {
	        clearScreen();
	        title();
	        pilihan = mainMenu();
	
	        switch (pilihan) {
	            case 1:
	                clearScreen();
	                title();
	                if (loginAdmin(username, password)) {
	                    system("pause");
	                    do {
	                        clearScreen();
	                        title();
	                        menuMasuk(&pilihan2);
	                        switch (pilihan2) {
	                            case 1:
	                                int pilihan3;
	                                clearScreen();
	                                title();
	                                if (bioskop == NULL) {
	                                	bioskop = muatTreeDariFile("database/treeBioskop.txt"); 
	                                }
	                                if (bioskop == NULL) {
	                                	bioskop = masukkanNamaBioskop();
	                                }
	                                do {
	                                    clearScreen();
	                                    title();
	                                    menuBioskop(&pilihan3);
	                                    switch (pilihan3) {
	                                        case 1:
	                                            clearScreen();
	                                            title();
	                                            tampilkanTree(bioskop);
	                                            tambahStudio(bioskop);
	                                            break;
	                                        case 2:
	                                            clearScreen();
	                                            title();
	                                            tampilkanTree(bioskop);
	                                            tambahFilm(bioskop);
	                                            break;
	                                        case 3:
	                                            clearScreen();
	                                            title();
	                                            tampilkanTree(bioskop);
	                                            tambahJamTayang(bioskop);
	                                            break;
	                                        case 4:
	                                            clearScreen();
	                                            title();
	                                            tampilkanTree(bioskop);
	                                            tambahKursi(bioskop);
	                                            break;
	                                        case 5:
	                                            clearScreen();
	                                            title();
	                                            tampilkanTree(bioskop);
	                                            system("pause");
	                                            break;
	                                        case 6:
	                                            clearScreen();
	                                            title();
	                                            tampilkanTree(bioskop);
	                                            cariNodeDanTampilkanHasil(bioskop);
	                                            system("pause");
	                                            break;
	                                        case 7:
	                                            clearScreen();
	                                            title();
	                                      		hapusNodeEx(bioskop);
	                                            break;
	                                        case 8:
	                                            system("pause");
	                                            break;
	                                        default:
	                                            printf("Pilihan tidak valid.\n");
	                                            break;
	                                    }
	                                } while (pilihan3 != 8);
	                                break;
	                            case 2:
	                            	clearScreen();
	                                            title();
	                                menuPesan(bioskop);
	                                system("pause");
	                                break;
	                            case 3:
	                                system("\npause");
	                                break;
	                            default:
	                                printf("Pilihan tidak valid.\n");
	                                break;
	                        }
	                    } while (pilihan2 != 3);
	                }
	                break;
	            case 2:
	                clearScreen();
	                title();
	                registerAdmin(username, password);
	                system("pause");
	                break;
	            case 3:
	                printf("Keluar dari sistem.\n");
	                return 0;
	            default:
	                printf("Pilihan tidak valid, silakan coba lagi.\n");
	        }
	    }
	
	    return 0;
	}

