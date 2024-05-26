#include "../bioskopHead.h"

// Fungsi untuk membuat node baru
Node* buatNode(char *nama) {
    Node *node = (Node*)malloc(sizeof(Node));
    strcpy(node->nama, nama);
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

Node* masukkanNamaBioskop() {
    char namaBioskop[100];
    printf("\nMasukkan nama bioskop (root) : ");
    scanf("%s", namaBioskop);
    return buatNode(namaBioskop);
}

// Fungsi untuk menambah studio ke bioskop
void tambahStudio(Node *bioskop) {
    char nama[100];
    printf("\nMasukkan nama studio: ");
    scanf("%s", nama);

    Node *studio = buatNode(nama);
    tambahAnak(bioskop, studio);
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
    } else {
        printf("Studio tidak ditemukan.\n");
    }
}

// Fungsi untuk menambah jam tayang ke film
void tambahJamTayang(Node *bioskop) {
    char nama[100];
    printf("\nMasukkan jam tayang: ");
    scanf("%s", nama);

    char namaFilm[100];
    printf("Masukkan nama film yang menjadi parent: ");
    scanf("%s", namaFilm);

    Node *film = cariNode(bioskop, namaFilm);
    if (film != NULL) {
        Node *jamTayang = buatNode(nama);
        tambahAnak(film, jamTayang);
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
            free(curr);
            printf("Node dengan nama '%s' berhasil dihapus.\n", nama);
            return;
        }
        prev = curr;
        curr = curr->nextBrother;
    }

    printf("Node dengan nama '%s' tidak ditemukan.\n", nama);
}

void hapusStudio(Node *bioskop) {
    char nama[100];
    printf("Masukkan nama studio yang akan dihapus: ");
    scanf("%s", nama);
    hapusNode(bioskop, nama);
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
    } else {
        printf("Jam tayang tidak ditemukan.\n");
    }
}

void hapusNodeEx(Node *bioskop) {
    int pilihan4;
    do {
        clearScreen();
        title();
        menuHapus(&pilihan4);
        switch (pilihan4) {
            case 1:
                clearScreen();
                title();
                tampilkanTree(bioskop, 0);
                hapusStudio(bioskop);
                system("pause");
                break;
            case 2:
                clearScreen();
                title();
                tampilkanTree(bioskop, 0);
                hapusFilm(bioskop);
                system("pause");
                break;
            case 3:
                clearScreen();
                title();
                tampilkanTree(bioskop, 0);
                hapusJamTayang(bioskop);
                system("pause");
                break;
            case 4:
                clearScreen();
                title();
                tampilkanTree(bioskop, 0);
                hapusKursi(bioskop);
                system("pause");
                break;
            case 5:
                system("pause");
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    } while (pilihan4 != 5);
}
