// Dalam bioskopHead.h
#ifndef BIOSKOPHEAD_H
#define BIOSKOPHEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// Maksimal node yang dapat ditampung dalam array
#define jml_maks 20

// Definisi struct untuk node
typedef struct Node {
    char nama[100];
    char state[100];
    struct Node *firstSon;
    struct Node *nextBrother;
} Node;

/* LOGIN DAN REGISTER*/
int loginAdmin(char *username, char *password);
void registerAdmin(char *username, char *password);

/* TAMPILAN */
void title();
void clearScreen();
int mainMenu();
void menuMasuk(int *pilihan2);
void menuBioskop(int *pilihan3);
void menuPesan(char *waktu, int *jumlahTiket);
void menuHapus(int *pilihan4);

/* CREATE BIOSKOP INFRASTRUKTUR*/
Node* buatNode(char *nama);
void tambahAnak(Node *parent, Node *child);
void tampilkanTree(Node *root, int level);
Node* cariNode(Node *root, char *nama);
Node* muatTreeDariFile(char *filename);

Node* masukkanNamaBioskop();
void tambahStudio(Node *bioskop);
void tambahFilm(Node *bioskop);
void tambahJamTayang(Node *bioskop);
void tambahKursi(Node *bioskop);

void cariNodeDanTampilkanHasil(Node *bioskop);

void hapusNode(Node *parent, char *nama);
void hapusNodeDanChild(Node *node);

void updateFile(Node *root, FILE *file, char *parentName);
void saveTreeToFile(Node *root, char *filename);

void hapusStudio(Node *bioskop);
void hapusFilm(Node *bioskop);
void hapusJamTayang(Node *bioskop);
void hapusKursi(Node *bioskop);
void hapusNodeEx(Node *bioskop);

/* PEMESANAN */
void pesanTiket(Node *bioskop);
void tampilkanFilmDanJamTayang(Node *bioskop);
void cetakTiket(char *namaFilm, char *namaJamTayang, char kursiDipesan[][100], int jumlahKursi);

#endif

