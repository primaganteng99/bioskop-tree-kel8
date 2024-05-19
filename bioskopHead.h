#ifndef BIOSKOPHEAD_H
#define BIOSKOPHEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Maksimal node yang dapat ditampung dalam array
#define jml_maks 20

// Definisi struct untuk node
typedef struct Node {
    char nama[100];
    struct Node *firstSon;
    struct Node *nextBrother;
} Node;

/* LOGIN DAN REGISTER*/
int loginAdmin(char *username, char *password);

/* TAMPILAN */
void title();
int mainMenu();
void menuBioskop(int *pilihan2);
void menuPesan(char *waktu, int *jumlahTiket);

/* CREATE BIOSKOP INFRASTRUKTUR*/
Node* buatNode(char *nama);
void tambahAnak(Node *parent, Node *child);
void tampilkanTree(Node *root, int level);
Node* cariNode(Node *root, char *nama);
void tambahStudio(Node *bioskop);
void tambahFilm(Node *bioskop);
void tambahJamTayang(Node *bioskop);
void tambahKursi(Node *bioskop);

#endif

