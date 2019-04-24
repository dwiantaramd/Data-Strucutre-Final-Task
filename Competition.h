#ifndef COMPETITION_H_INCLUDED
#define COMPETITION_H_INCLUDED

#include "main.h"
#define Comp_Name(P) P->Comp_Name
#define place(P) P->place
#define year(P) P->year
#define nextC(P) P->nextC
#define firstC(P) P.firstC
#define lastC(P) P.lastC


typedef struct elmListC *addressC;

struct elmListC{
    string Comp_Name,place;
    int year;
    addressC nextC;
};
struct ListC{
    addressC firstC;
    addressC lastC;
};

void Create_ListC(ListC &L);
addressC AllocationC(string nama,int tahun,string tempat);
void DeallocationC(addressC &P);
void Insert_LastC(ListC &L, addressC P);
addressC Find_Name_C(ListC L, string x);
void Delete_by_NameC(ListC &L, addressC &P, string nama);
void Print_InfoC(ListC L);

#endif // COMPETITION_H_INCLUDED
