#include "bioskopHead.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

int main() {
	int pilihan;
	char username[50]; char password[50];
	
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
          	 				do {
          	 					clearScreen();
          	 					title();
          	 					menuBioskop(&pilihan3);
          	 					switch (pilihan3){
          	 						case 1:
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
							   } while (pilihan3 != 5);
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

