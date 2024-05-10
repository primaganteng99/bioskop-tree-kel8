#include "../bioskopHead.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

boolean IsEmpty (Isi_Tree P){ // memeriksa apakah tree kosong pada index ke-1
	int i;
	
	for(i = 1; i < jml_maks; i++){
		if(P[i].info != '\0'){
			return false;
		}
	}
	
	return true;
}
