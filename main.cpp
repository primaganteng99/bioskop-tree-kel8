#include "bioskopHead.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

int main() {
	int pilihan;
	char username[50]; char password[50];
	
    while (1) {
    	title();
        pilihan = mainMenu();

        switch (pilihan) {
        	system("cls");
        	title();
        	int pilihan2;
            case 1:
          	 if (loginAdmin(username, password)){
          	 	do {
          	 		menuBioskop(&pilihan2);
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
            	printf("Keluar dari sistem.\n");
                return 0;
            default:
                printf("Pilihan tidak valid, silakan coba lagi.\n");
        }
    }

    return 0;
}

