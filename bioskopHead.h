#ifndef BIOSKOPHEAD_H
#define BIOSKOPHEAD_H
#define MAX_CHILDREN 10
#define MAX_TITLE 50
#define MAX_TIME 10

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

Node* buatNode(char *judul);
void tambahWaktuTayang(Node *film, char *waktuMulai, int totalKursi);
void pesanTiket(Node *film, char *waktuMulai, int jumlahTiket);
void tampilkanFilm(Node *film);
void deallocBioskop(Node *film);

#endif

