#include "../bioskopHead.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi untuk membuat node baru
Node* buatNode(char *nama) {
    Node *node = (Node*)malloc(sizeof(Node));
    strcpy(node->nama, nama);
    strcpy(node->state, "empty");
    node->firstSon = NULL;
    node->nextBrother = NULL;
    return node;
}

// Fungsi untuk menambah node sebagai anak pertama
void tambahAnak(Node *parent, Node *child) {
    if (parent->firstSon == NULL) {
        parent->firstSon = child;
    } else {
        Node *temp = parent->firstSon;
        while (temp->nextBrother != NULL) {
            temp = temp->nextBrother;
        }
        temp->nextBrother = child;
    }
}

// Fungsi untuk menampilkan tree
void tampilkanTree(Node *root, int level) {
    if (root == NULL) return;

    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("%s\n", root->nama);

    tampilkanTree(root->firstSon, level + 1);
    tampilkanTree(root->nextBrother, level);
}

// Fungsi untuk mencari node dalam tree berdasarkan nama
Node* cariNode(Node *root, char *nama) {
    if (root == NULL) return NULL;

    if (strcmp(root->nama, nama) == 0) {
        return root;
    }

    Node *result = cariNode(root->firstSon, nama);
    if (result != NULL) {
        return result;
    }

    return cariNode(root->nextBrother, nama);
}

Node* muatTreeDariFile(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return NULL;
    }

    Node *root = NULL;
    char nama[100], parent[100], state[100];

    while (fscanf(file, "%s %s %s", nama, parent, state) != EOF) {
        Node *newNode = buatNode(nama);
        strcpy(newNode->state, state);

        if (strcmp(parent, "root") == 0) {
            root = newNode;
        } else {
            Node *parentNode = cariNode(root, parent);
            if (parentNode != NULL) {
                tambahAnak(parentNode, newNode);
            } else {
                printf("Parent '%s' tidak ditemukan untuk node '%s'.\n", parent, nama);
                free(newNode);
            }
        }
    }

    fclose(file);
    return root;
}

Node* masukkanNamaBioskop() {
    char namaBioskop[100];
    printf("\nMasukkan nama bioskop (root) : ");
    scanf("%s", namaBioskop);
    
    FILE *file = fopen("database/treeBioskop.txt", "w");
    fprintf(file, "%s root empty\n", namaBioskop);
    
    fclose(file);
    
    return buatNode(namaBioskop);
}

// Fungsi untuk menambah studio ke bioskop
void tambahStudio(Node *bioskop) {
    char nama[100];
    printf("\nMasukkan nama studio: ");
    scanf("%s", nama);

    Node *studio = buatNode(nama);
    tambahAnak(bioskop, studio);
    
    FILE *file = fopen("database/treeBioskop.txt", "a");
    fprintf(file, "%s %s empty\n", nama, bioskop->nama);
    
    fclose(file);
}

// Fungsi untuk menambah film ke studio
void tambahFilm(Node *bioskop) {
    char nama[100];
    printf("\nMasukkan nama film: ");
    scanf("%s", nama);

    char namaStudio[100];
    printf("Masukkan nama studio yang menjadi parent: ");
    scanf("%s", namaStudio);

    Node *studio = cariNode(bioskop, namaStudio);
    if (studio != NULL) {
        Node *film = buatNode(nama);
        tambahAnak(studio, film);
        
        FILE *file = fopen("database/treeBioskop.txt", "a");
        fprintf(file, "%s %s empty\n", nama, namaStudio);
        
        fclose(file);
        
    } else {
        printf("Studio tidak ditemukan.\n");
    }
}

// Fungsi untuk menambah jam tayang ke film
void tambahJamTayang(Node *bioskop) {
    char nama[100];
    printf("\nMasukkan jam tayang (JAM:MENIT) : ");
    scanf("%s", nama);

    char namaFilm[100];
    printf("Masukkan nama film yang menjadi parent: ");
    scanf("%s", namaFilm);

    Node *film = cariNode(bioskop, namaFilm);
    if (film != NULL) {
        Node *jamTayang = buatNode(nama);
        tambahAnak(film, jamTayang);
        
        FILE *file = fopen("database/treeBioskop.txt", "a");
        fprintf(file, "%s %s empty\n", nama, namaFilm);
        
        fclose(file);
        
    } else {
        printf("Film tidak ditemukan.\n");
    }
}

// Fungsi untuk menambah kursi ke jam tayang
void tambahKursi(Node *bioskop) {
    char nama[100];
    printf("\nMasukkan nomor kursi: ");
    scanf("%s", nama);

    char namaJamTayang[100];
    printf("Masukkan jam tayang yang menjadi parent: ");
    scanf("%s", namaJamTayang);

    Node *jamTayang = cariNode(bioskop, namaJamTayang);
    if (jamTayang != NULL) {
        Node *kursi = buatNode(nama);
        tambahAnak(jamTayang, kursi);
        
        FILE *file = fopen("database/treeBioskop.txt", "a");
        fprintf(file, "%s %s empty\n", nama, namaJamTayang);
        
        fclose(file);
        
    } else {
        printf("Jam tayang tidak ditemukan.\n");
    }
}

void cariNodeDanTampilkanHasil(Node *bioskop) {
    char namaCari[100];
    printf("Masukkan nama yang ingin dicari: ");
    scanf("%s", namaCari);
    Node *ditemukan = cariNode(bioskop, namaCari);
    if (ditemukan != NULL) {
        printf("Node dengan nama '%s' ditemukan.\n", namaCari);
    } else {
        printf("Node dengan nama '%s' tidak ditemukan.\n", namaCari);
    }
}

// Fungsi untuk menghapus node dan seluruh anaknya secara rekursif
void hapusNodeDanChild(Node *node) {
    if (node == NULL) return;

    hapusNodeDanChild(node->firstSon);
    hapusNodeDanChild(node->nextBrother);

    free(node);
}

// Fungsi untuk menghapus node
void hapusNode(Node *parent, char *nama) {
    if (parent == NULL || parent->firstSon == NULL) {
        printf("Node dengan nama '%s' tidak ditemukan.\n", nama);
        return;
    }

    Node *curr = parent->firstSon;
    Node *prev = NULL;

    while (curr != NULL) {
        if (strcmp(curr->nama, nama) == 0) {
            if (prev == NULL) {
                parent->firstSon = curr->nextBrother;
            } else {
                prev->nextBrother = curr->nextBrother;
            }
            // Menghapus node dan seluruh anaknya secara rekursif
            curr->nextBrother = NULL; // Pastikan tidak ada pointer yang korup
            hapusNodeDanChild(curr);
            printf("Node dengan nama '%s' telah dihapus.\n", nama);
            return;
        }

        prev = curr;
        curr = curr->nextBrother;
    }

    printf("Node dengan nama '%s' tidak ditemukan.\n", nama);
}

void updateFile(Node *root, FILE *file, char *parentName) {
    if (root == NULL) return;

    fprintf(file, "%s %s %s\n", root->nama, parentName, root->state);
    updateFile(root->firstSon, file, root->nama);
    updateFile(root->nextBrother, file, parentName);
}

void saveTreeToFile(Node *root, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    updateFile(root, file, "root");
    fclose(file);
}

void hapusStudio(Node *bioskop) {
    char nama[100];
    printf("Masukkan nama studio yang akan dihapus: ");
    scanf("%s", nama);
    hapusNode(bioskop, nama);
    saveTreeToFile(bioskop, "database/treeBioskop.txt");
}

void hapusFilm(Node *bioskop) {
    char nama[100];
    printf("\nMasukkan nama film yang akan dihapus: ");
    scanf("%s", nama);

    char namaStudio[100];
    printf("Masukkan nama studio yang menjadi parent: ");
    scanf("%s", namaStudio);

    Node *studio = cariNode(bioskop, namaStudio);
    if (studio != NULL) {
        hapusNode(studio, nama);
        saveTreeToFile(bioskop, "database/treeBioskop.txt");
    } else {
        printf("Studio tidak ditemukan.\n");
    }
}

void hapusJamTayang(Node *bioskop) {
    char nama[100];
    printf("\nMasukkan jam tayang yang akan dihapus: ");
    scanf("%s", nama);

    char namaFilm[100];
    printf("Masukkan nama film yang menjadi parent: ");
    scanf("%s", namaFilm);

    Node *film = cariNode(bioskop, namaFilm);
    if (film != NULL) {
        hapusNode(film, nama);
        saveTreeToFile(bioskop, "database/treeBioskop.txt");
    } else {
        printf("Film tidak ditemukan.\n");
    }
}

void hapusKursi(Node *bioskop) {
    char nama[100];
    printf("\nMasukkan nomor kursi yang akan dihapus: ");
    scanf("%s", nama);

    char namaJamTayang[100];
    printf("Masukkan jam tayang yang menjadi parent: ");
    scanf("%s", namaJamTayang);

    Node *jamTayang = cariNode(bioskop, namaJamTayang);
    if (jamTayang != NULL) {
        hapusNode(jamTayang, nama);
        saveTreeToFile(bioskop, "database/treeBioskop.txt");
    } else {
        printf("Jam tayang tidak ditemukan.\n");
    }
}
