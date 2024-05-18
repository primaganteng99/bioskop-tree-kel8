#include "bioskopHead.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>

int main() {
	
	int Jml_Node = 0;
	Isi_Tree P; int i;
	//P[1].info = '\0';
	
	//for(i = 1; i < jml_maks; i++){
	//	P[i].info = '\0';
	//}
	
	/*
	printf("  Program Non-Binary Tree ");
	printf("\n<=========================>\n");
	
	printf("Berapa data yang ingin Anda masukkan (Maks 20): ");
 	scanf("%d", &Jml_Node);
	if(Jml_Node > jml_maks){
		printf("\nMelebihi batas input yaitu %d!\n\n", jml_maks);
		system("pause");
	}else{
		Create_tree(P, Jml_Node);
	}*/
	
    Node *bioskop = buatNode("Siksa Kubur");/*
    tambahWaktuTayang(bioskop, "10:00", 20);
    tambahWaktuTayang(bioskop, "14:00", 20);
    tambahWaktuTayang(bioskop, "20:00", 20);*/

    int pilihan, jumlahTiket;
    char waktu[10];

	Create_Bone(P, &Jml_Node);
	//Create_tree(P, Jml_Node);
	//Search (Isi_Tree P, infotype X);
	PrintTree (P, Jml_Node);
	//IsEmpty (Isi_Tree P);
	
    while (1) {
        pilihan = mainMenu();

        switch (pilihan) {
            case 1:
                tampilkanFilm(bioskop);
                break;
            case 2:
                menuPesan(waktu, &jumlahTiket);
                pesanTiket(bioskop, waktu, jumlahTiket);
                break;
            case 3:
                editFilm(bioskop);
                editWaktuTayang(bioskop);
                break;
            case 4:
                deallocBioskop(bioskop);
                printf("Keluar dari sistem.\n");
                return 0;
            default:
                printf("Pilihan tidak valid, silakan coba lagi.\n");
        }
    }

    return 0;
}

