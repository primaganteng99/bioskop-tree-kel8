#include "bioskopHead.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

int main() {
	int pilihan;
	char username[50]; char password[50];
	
    while (1) {
        pilihan = mainMenu();

        switch (pilihan) {
        	int pilihan2;
            case 1:
          	 if (loginAdmin(username, password)){
          	 	do {
          	 		printf("\nMenu:\n");
        			printf("1. Tambah Studio\n");
        		   printf("2. Tambah Film\n");
        		   printf("3. Tambah Jam Tayang\n");
        		   printf("4. Tambah Kursi\n");
        		   printf("5. Tampilkan Tree\n");
        		   printf("6. Cari Node\n");
   			  	   printf("7. Keluar\n");
        		   printf("Pilih opsi: ");
        		   scanf("%d", &pilihan2);
        		   
          	 		switch (pilihan2){
          	 			case 1:
          	 				break;
       	 				case 2:
       	 					break;
 	 					case 3:
 	 						break;
					   }
				   }while (pilihan2 != 5);
			   }
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                printf("Keluar dari sistem.\n");
                return 0;
            default:
                printf("Pilihan tidak valid, silakan coba lagi.\n");
        }
    }

    return 0;
}

