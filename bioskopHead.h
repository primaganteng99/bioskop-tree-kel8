#ifndef BIOSKOPHEAD_H
#define BIOSKOPHEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Maksimal node yang dapat ditampung dalam array
#define jml_maks 20

typedef char infotype[50];
typedef int address;

typedef struct {
    infotype info;
    address ps_fs, ps_nb, ps_pr;
} nbtree;

typedef nbtree Isi_Tree[jml_maks + 1];

typedef struct {
    char waktuMulai[10];
    int totalKursi;
    int sisaKursi;
} WaktuTayang;

typedef struct {
    char judul[50];
    int jumlahAnak;
    WaktuTayang waktuTayang[10];
} Node;

int loginAdmin(char *username, char *password);
void menuPesan(char *waktu, int *jumlahTiket);
int mainMenu();

Node* buatNode(char *judul);
void tambahWaktuTayang(Node *film, char *waktuMulai, int totalKursi);
void pesanTiket(Node *film, char *waktuMulai, int jumlahTiket);
void tampilkanFilm(Node *film);
void deallocBioskop(Node *film);
void editFilm(Node *film);
void editWaktuTayang(Node *film);

void Create_Bone(Isi_Tree X, int *Jml_Node);
bool Search(Isi_Tree P, infotype X);
void PrintTree(Isi_Tree P, int Jml_Node);
bool IsEmpty(Isi_Tree P);
void Create_tree(Isi_Tree X, int Jml_Node);

#endif

