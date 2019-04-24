#include "Competition.h"

void Create_ListC(ListC &L){
    firstC(L) = NULL;
    lastC(L) = NULL;
}
addressC AllocationC(string nama,int tahun,string tempat){
    addressC C = new elmListC;
    Comp_Name(C) = nama;
    year(C) = tahun;
    place(C) = tempat;
    nextC(C) = NULL;
    return C;
}
void DeallocationC(addressC &P){
    delete(P);
}
void Insert_LastC(ListC &L, addressC P){
    if(firstC(L) == NULL){
        firstC(L) = P;
        lastC(L) = P;
        nextC(P) = firstC(L);
    } else {
        nextC(lastC(L)) = P;
        nextC(P) = firstC(L);
        lastC(L) = P;
    }
}

addressC Find_Name_C(ListC L, string x){
    addressC P = firstC(L);
    while(nextC(P)!= firstC(L) && Comp_Name(P)!= x) {
        P = nextC(P);
    }
    if(Comp_Name(P) == x)
        return P;
    else
        return NULL;
}
void Delete_by_NameC(ListC &L, addressC &P, string nama){
    P = Find_Name_C(L,nama);
    if(firstC(L)==NULL){
        cout<< nama <<" Tidak Ditemukan"<<endl;
    }else if(firstC(L)==lastC(L)){
        P = firstC(L);
        firstC(L) = NULL;
        lastC(L) = NULL;
    }else{
        if(P == NULL){
            cout<< nama <<" Tidak Ditemukan"<<endl;
        }else{
            if(P == firstC(L)){
                firstC(L) = nextC(P);
                nextC(lastC(L)) = firstC(L);
                nextC(P) = NULL;
            }else if(P == lastC(L)){
                addressC Q = firstC(L);
                while(nextC(Q) != lastC(L)){
                    Q = nextC(Q);
                }
                lastC(L) = Q;
                nextC(Q) = firstC(L);
                nextC(P) = NULL;
            }else{
                addressC prec = firstC(L);
                while(nextC(prec) != P){
                    prec = nextC(prec);
                }
                nextC(prec) = nextC(P);
                nextC(P) = NULL;
            }
        }
    }
}
void Print_InfoC(ListC L){
    if(firstC(L) == NULL)
        cout << "Tidak Ada Data yang Terdaftar"<< endl;
    else{
        addressC P = firstC(L);
        int n = 1;
        cout << "Daftar Perlombaan : " << endl;
        while(nextC(P) != firstC(L)){
            cout << n <<". "<< Comp_Name(P) <<", Tempat : "<< place(P) <<", Tahun : " << year(P) << endl;
            n++;
            P = nextC(P);
        }
        cout << n <<". "<< Comp_Name(P) <<", Tempat : "<< place(P) <<", Tahun : " << year(P) << endl;
        cout << endl;
    }
}
