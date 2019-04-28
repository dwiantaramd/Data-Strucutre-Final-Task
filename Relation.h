#ifndef RELATION_H_INCLUDED
#define RELATION_H_INCLUDED

#include "Personal.h"
#include "Competition.h"
#include "main.h"

#define firstR(P) P.firstR
#define lastR(P) P.lastR
#define nextR(P) P->nextR
#define Peserta(P) P->Peserta
#define Kompetisi(P) P->Kompetisi

typedef struct elmListR *addressR;

struct elmListR{
    addressR nextR;
    addressP Peserta;
    addressC Kompetisi;
};
struct ListR{
    addressR firstR;
    addressR lastR;
};

void Create_ListR(ListR &R);
addressR allocationR(addressP P,addressC C);
void DeallocationR(addressR &R);
void Insert_FirstR(ListR &L, addressR P);
void delete_relation(ListR &L, addressR &R);
void delete_relation_peserta(ListR &L,string peserta);
void delete_relation_kompetisi(ListR &L, string kompetisi);
void print_info_Peserta(ListR L,string peserta);
void print_info_kompetisi(ListR L, string kompetisi);
addressR Find_Relation(ListR L, addressC contest,addressP participant);
int CountPeserta(ListR L, string kompetisi);
int CountKompetisi(ListR L, string peserta);
#endif // RELATION_H_INCLUDED
