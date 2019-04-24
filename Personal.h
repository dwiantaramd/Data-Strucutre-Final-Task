#ifndef PERSONAL_H_INCLUDED
#define PERSONAL_H_INCLUDED

#include "main.h"

#define name(P) P->name
#define city(P) P->city
#define age(P) P->age
#define nextP(P) P->nextP
#define prevP(P) P->prevP
#define firstP(P) P.firstP
#define lastP(P) P.lastP


typedef struct elmlistP *addressP;
struct elmlistP {
    string name,city;
    int age;
    addressP nextP,prevP;
};
struct ListP{
    addressP firstP;
    addressP lastP;
};

void Create_ListP(ListP &L);
addressP AllocationP(string name,string city, int age);
void DeallocationP(addressP &P);
void Insert_FirstP(ListP &L, addressP P);
void Insert_LastP(ListP &L, addressP P);
void Insert_AfterP(ListP &L, addressP Prec, addressP P);
void Delete_FirstP(ListP &L, addressP &P);
void Delete_LastP(ListP &L, addressP &P);
void Delete_AfterP(ListP &L, addressP prec, addressP &P);
void Insert_by_NameP(ListP &L, addressP P);
void Delete_by_NameP(ListP &L, addressP &P, string name);
addressP Find_Name_P(ListP L, string x);
void Print_InfoP(ListP L);

#endif // PERSONAL_H_INCLUDED
