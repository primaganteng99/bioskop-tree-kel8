#include "../bioskopHead.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Create_Bone(Isi_Tree P, int *Jml_Node) {
    int i;
    for (i = 1; i <= jml_maks; i++) {
        memset(P[i].info, '\0', sizeof(P[i].info));
        P[i].ps_fs = 0;
        P[i].ps_nb = 0;
        P[i].ps_pr = 0;
    }

    printf("Berapa data yang ingin Anda masukkan (Maks 20): ");
    scanf("%d", Jml_Node);
    printf("Jumlah Node : %d\n", *Jml_Node);

    if (*Jml_Node > jml_maks) {
        printf("\nMelebihi batas input yaitu %d!\n\n", jml_maks);
        system("pause");
    } else {
        Create_tree(P, *Jml_Node);
    }
}

void Create_tree(Isi_Tree X, int Jml_Node) {
    char input[50], parent[50];
    int i, j, posisiParent, posisiBrother, temp;

    printf("Masukkan Root: ");
    scanf("%s", input);
    strcpy(X[1].info, input);

    for (i = 2; i <= Jml_Node; i++) {
        printf("\nMasukkan Data: ");
        scanf("%s", input);
        printf("Pilih Parent Data: ");
        scanf("%s", parent);

        if (Search(X, parent)) {
            j = 1;
            while (strcmp(X[j].info, parent) != 0 && j <= jml_maks) {
                ++j;
            }
            posisiParent = j;

            if (X[posisiParent].ps_fs == 0) {
                strcpy(X[i].info, input);
                X[i].ps_pr = posisiParent;
                X[i].ps_nb = 0;
                X[posisiParent].ps_fs = i;
            } else {
                X[i].ps_pr = posisiParent;
                temp = X[posisiParent].ps_fs;

                while (X[temp].ps_nb != 0) {
                    temp = X[temp].ps_nb;
                }

                X[temp].ps_nb = i;
                X[i].ps_nb = 0;
                strcpy(X[i].info, input);
            }
        } else {
            printf("Tidak ada parent\n");
            --i;
        }
    }
}

bool IsEmpty(Isi_Tree P) {
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info[0] != '\0') {
            return false;
        }
    }
    return true;
}

void PrintTree(Isi_Tree P, int Jml_Node) {
    printf("info:     fs:     nb:     pr:\n");
    printf("-----     ---     ---     ---\n");
    for (int i = 1; i <= Jml_Node; i++) {
        printf("%-10s %3d     %3d     %3d\n", P[i].info, P[i].ps_fs, P[i].ps_nb, P[i].ps_pr);
    }
    printf("-----------------------------\n");
}

bool Search(Isi_Tree P, infotype X) {
    for (int i = 1; i <= jml_maks; i++) {
        if (strcmp(P[i].info, X) == 0) {
            return true;
        }
    }
    return false;
}

