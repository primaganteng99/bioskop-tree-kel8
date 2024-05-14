#ifndef BIOSKOPHEAD_H
#define BIOSKOPHEAD_H
#define MAX_CHILDREN 10
#define MAX_TITLE 50
#define MAX_TIME 10

//#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Maksimal node yang dapat ditampung dalam array
#define jml_maks 20

//Arah traversal
#define kebawah 1
#define keatas 2
#define kekanan 3
#define nil 0

typedef char infotype;
typedef int address;

typedef struct { 
	infotype info;
	address ps_fs, ps_nb, ps_pr;
}nbtree;

typedef nbtree Isi_Tree[jml_maks+1];

typedef struct WaktuTayang {
    char waktuMulai[MAX_TIME];
    int totalKursi;
    int sisaKursi;
} WaktuTayang;

typedef struct Node {
    char judul[MAX_TITLE];
    int jumlahAnak;
    WaktuTayang waktuTayang[MAX_CHILDREN];
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

void Create_Bone(Isi_Tree X, int Jml_Node);
bool Search (Isi_Tree P, infotype X);
void PrintTree (Isi_Tree P, int Jml_Tree);
bool IsEmpty (Isi_Tree P);
void Create_tree(Isi_Tree X, int Jml_Node);

#endif

