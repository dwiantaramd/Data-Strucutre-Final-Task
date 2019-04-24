#include "Relation.h"

void Create_ListR(ListR &R){
    firstR(R) = NULL;
    lastR(R) = NULL;
}
addressR allocationR(addressP P,addressC C){
    addressR R = new elmListR;
    Peserta(R) = P;
    Kompetisi(R) = C;
    nextR(R) = NULL;
    return R;
}
void DeallocationR(addressR &R){
    delete(R);
}
void Insert_FirstC(ListR &L, addressR P){
    if(firstR(L) == NULL){
        firstR(L) = P;
        lastR(L) = P;
    } else {
        nextR(P) = firstR(L);
        firstR(L) = P;
    }
}
void delete_relation(ListR &L, addressR &R,string peserta, string kompetisi);
void print_info_Peserta(ListR L,string peserta){
    addressR P = firstR(L);
    int n = 1;
    while(P != NULL){
        if(name(Peserta(P)) == peserta){
            cout << n <<". "<< Comp_Name(Kompetisi(P)) << endl;
            n++;
        }
        P = nextR(P);
    }
}
void print_info_kompetisi(ListR L, string kompetisi){
    addressR P = firstR(L);
    int n = 1;
    while(P != NULL){
        if(Comp_Name(Kompetisi(P)) == kompetisi){
            cout << n <<". "<< name(Peserta(P)) << endl;
            n++;
        }
        P = nextR(P);
    }
}
