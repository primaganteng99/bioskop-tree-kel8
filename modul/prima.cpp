#include "../bioskopHead.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

int loginAdmin(char *username, char *password) {
	
	printf("\n---------\n");
	printf("| Login |\n");
	printf("---------\n");
	printf("Username : ");
	scanf("%s",username);
	
	printf("Password : "); 
	scanf("%s",password);
	
    FILE *file = fopen("database/adminAccount.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return 0;
    }
    rewind(file);
    
    char storedUsername[MAX_USERNAME_LENGTH];
    char storedPassword[MAX_PASSWORD_LENGTH];
    
    while (!feof(file)) {
        fscanf(file, "%s %s\n", storedUsername, storedPassword);
        
        if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0) {
            fclose(file);
            printf("==================\n");
            printf("= Login berhasil =\n");
            printf("==================\n");
            return 1; // Login berhasil
        }
    }
    
    printf("===============\n");
    printf("= Login Gagal =\n");
	printf("===============\n");
    fclose(file);
    return 0; // Login gagal
}


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

void cetakHorizontal(Node *node, int level) {
    if (node == NULL) return;

    Node *current = node;
    int count = 0;
    while (current != NULL) {
        if (level == 3 || level == 4) {
            printf("%s ", current->nama);
            count++;
            if (count % 10 == 0) {
                printf("\n");
            }
        } else {
            cetakHorizontal(current, level + 1);
        }
        current = current->nextBrother;
    }
    printf("\n");
}

void tampilkanTreeHelper(Node *node, int depth) {
    if (node == NULL) return;

    // Cetak nama node dengan indentasi sesuai kedalaman
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("%s\n", node->nama);

    // Panggil fungsi rekursif untuk anak pertama
    if (depth < 2 || (depth == 2 && node->firstSon != NULL)) {
        tampilkanTreeHelper(node->firstSon, depth + 1);
    } else {
        // Jika node berada di level 3 dan tidak memiliki anak, cetak horizontal sejajar dengan level 2
        cetakHorizontal(node->firstSon, depth + 1);
    }

    // Panggil fungsi rekursif untuk saudara kandung
    tampilkanTreeHelper(node->nextBrother, depth);
}

void tampilkanTree(Node *root) {
    // Panggil fungsi helper dengan node root dan depth 0
    tampilkanTreeHelper(root, 0);
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
    int jumlahKursi;
    printf("\nBerapa kursi yang ingin ditambahkan: ");
    scanf("%d", &jumlahKursi);

    char namaJamTayang[100];
    printf("Masukkan jam tayang yang menjadi parent: ");
    scanf("%s", namaJamTayang);

    Node *jamTayang = cariNode(bioskop, namaJamTayang);
    if (jamTayang != NULL) {
        char namaKursi[100];
        char huruf = 'A';
        int nomor = 1;

        for (int i = 0; i < jumlahKursi; i++) {
            sprintf(namaKursi, "%c%d", huruf, nomor);
            Node *kursi = buatNode(namaKursi);
            tambahAnak(jamTayang, kursi);

            FILE *file = fopen("database/treeBioskop.txt", "a");
            fprintf(file, "%s %s empty\n", namaKursi, namaJamTayang);
            fclose(file);

            if (nomor == 10) {
                huruf++;
                nomor = 1;
            } else {
                nomor++;
            }
        }

        printf("%d kursi berhasil ditambahkan pada jam tayang %s.\n", jumlahKursi, namaJamTayang);
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
