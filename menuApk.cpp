#include "bioskopHead.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mainMenu(){
	
 	int pilihan;
	 printf("\nSistem Pemesanan Tiket Bioskop\n");
  	 printf("1. Tampilkan film yang tersedia\n");
     printf("2. Pesan tiket\n");
	 printf("3. Keluar\n");
  	 printf("Masukkan pilihan Anda: ");
     scanf("%d", &pilihan);
     return pilihan;
    }
