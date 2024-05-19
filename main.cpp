#include "bioskopHead.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

int main() {
	int pilihan;
	char username[50]; char password[50];
	Node *bioskop = NULL;
	
    while (1) {
    	clearScreen();
	    title();
        pilihan = mainMenu();

        switch (pilihan) {
        	int pilihan2;
            case 1:
          	 if (loginAdmin(username, password)){
          	 	do {
          	 		clearScreen();
          	 		title();
          	 		menuMasuk(&pilihan2);
          	 		switch (pilihan2){
          	 			case 1:
          	 				int pilihan3;
          	 				clearScreen();
       	 					title();
          	 				if (bioskop == NULL) {
                                    bioskop = masukkanNamaBioskop(); // Inisialisasi bioskop jika belum ada
                                }
          	 				do {
          	 					clearScreen();
          	 					title();
          	 					menuBioskop(&pilihan3);
          	 					switch (pilihan3){
          	 						case 1:
          	 							tambahStudio(bioskop);
          	 							break;
          	 						case 2:
          	 							tambahFilm(bioskop);
          	 							break;
									case 3:
										tambahJamTayang(bioskop);
										break;
									case 4:
										tambahKursi(bioskop);
										break;
									case 5:
										tampilkanTree(bioskop, 0);
										system("pause");
										break;
									case 6:
										cariNodeDanTampilkanHasil(bioskop);
										break;
									case 7:
								 		system("pause"); 
										break;    		
								   }
							   } while (pilihan3 != 7);
          	 				break;
       	 				case 2:
       	 					
       	 					break;
 	 					case 3:
 	 						
 	 						break;
 	 					case 4:
		  			 		break;
						case 5:
							system("\npause");
							break; 
					   }
				   }while (pilihan2 != 5);
			   }
                break;
            case 2:
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

