#include "../bioskopHead.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Create_Bone(int Jml_Node){
	
	for(i = 1; i < jml_maks; i++){
		P[i].info = '\0';
	}
	
	printf("Berapa data yang ingin Anda masukkan (Maks 20): ");
 	scanf("%d", &Jml_Node);
	if(Jml_Node > jml_maks){
		printf("\nMelebihi batas input yaitu %d!\n\n", jml_maks);
		system("pause");
	}else{
		Create_tree(P, Jml_Node);
	}
}


void Create_tree(Isi_Tree X, int Jml_Node){
	char input, parent;
	int i, j, posisiParent, posisiBrother, temp;
	
	printf("Masukkan Root: ");
	scanf(" %c", &input);
	X[1].info = input;
	
	for(i = 2; i <= Jml_Node; i++){
		printf("\nMasukkan Data : ");
		scanf(" %c", &input);
		printf("Pilih Parent Data : ");
		scanf(" %c", &parent);
		
		if(Search(X, parent)){
			j = 1;
			while(X[j].info != parent){
				++j;
			}
			posisiParent = j;
			
			if(X[posisiParent].ps_fs == 0){ 
				X[i].info = input; 
				X[i].ps_pr = posisiParent;
				X[i].ps_nb = 0;
				X[posisiParent].ps_fs = i;
			}else{ 
				X[i].ps_pr = posisiParent;
				temp = X[posisiParent].ps_fs;
				
				while(temp != 0){
					posisiBrother = temp;
					temp = X[temp].ps_nb;
				}
				
				X[posisiBrother].ps_nb = i;
				X[i].ps_nb = 0;
				X[i].info = input;
			}
		}else{
			printf("Tidak ada parent");
			--i; 
		}
	}
}

bool IsEmpty (Isi_Tree P){ // memeriksa apakah tree kosong pada index ke-1
	int i;
	
	for(i = 1; i < jml_maks; i++){
		if(P[i].info != '\0'){
			return false;
		}
	}
	
	return true;
}

void PrintTree (Isi_Tree P, int Jml_Node){
	int i;
	printf("info:     fs:     nb:     pr:\n");
	printf("-----     ---     ---     ---\n");
	for(i = 1; i <= Jml_Node; i++){ 
		printf("%c ", P[i].info);
		printf("        %d ", P[i].ps_fs);
		printf("      %d ", P[i].ps_nb);
		printf("      %d \n", P[i].ps_pr);
	}
	printf("-----------------------------\n");
}

bool Search (Isi_Tree P, infotype X){
	int i;
	for(i = 1; i <= jml_maks; i++){
		if(P[i].info == X){
			return true;
		}
	}
	return false;
}
