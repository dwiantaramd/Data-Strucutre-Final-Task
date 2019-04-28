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
void Insert_FirstR(ListR &L, addressR P){
    if(firstR(L) == NULL){
        firstR(L) = P;
        lastR(L) = P;
    } else {
        nextR(P) = firstR(L);
        firstR(L) = P;
    }
}
void delete_relation(ListR &L,addressR &R){
    addressR P = firstR(L);
    if(R == firstR(L) && R == lastR(L)){
        firstR(L) = NULL;
        lastR(L) = NULL;
    } else if(R == firstR(L)){
        firstR(L) = nextR(R);
        nextR(R) = NULL;
    } else if(R == lastR(L)){
        while(nextR(P)!=lastR(L)){
            P = nextR(P);
        }
        lastR(L) = P;
        nextR(P) = NULL;
    } else{
        while(nextR(P) != R){
            P = nextR(P);
        }
        nextR(P) = nextR(R);
        nextR(R) = NULL;
    }
}
void delete_relation_peserta(ListR &L, string peserta){
    addressR R = firstR(L);
    while(R != NULL){
        if(name(Peserta(R))==peserta){
            addressR P = R;
            R = nextR(R);
            delete_relation(L,P);
            DeallocationR(P);
        } else {
            R = nextR(R);
        }
    }
}
void delete_relation_kompetisi(ListR &L, string kompetisi){
    addressR R = firstR(L);
    while(R != NULL){
        if(Comp_Name(Kompetisi(R))==kompetisi){
            addressR P = R;
            R = nextR(R);
            delete_relation(L,P);
            DeallocationR(P);
        } else {
            R = nextR(R);
        }
    }
}
void print_info_Peserta(ListR L,string peserta){
    addressR P = firstR(L);
    int n = 1;
    while(P != NULL){
        if(name(Peserta(P)) == peserta){
            cout << "\t" << n <<". "<< Comp_Name(Kompetisi(P)) << endl;
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
            cout << "\t" << n <<". "<< name(Peserta(P)) << ", ID : "<< ID(Peserta(P)) <<endl;
            n++;
        }
        P = nextR(P);
    }
}
addressR Find_Relation(ListR L, addressC contest,addressP participant){
    addressR R = firstR(L);
    while(R!=NULL && (Peserta(R) != participant || Kompetisi(R)!=contest)){
        R = nextR(R);
    }
    return R;
}
int CountPeserta(ListR L, string kompetisi){
    addressR R = firstR(L);
    int temp = 0;
    while(R != NULL){
        if(Comp_Name(Kompetisi(R)) == kompetisi){
            temp++;
        }
        R = nextR(R);
    }
    return temp;
}

int CountKompetisi(ListR L, string peserta){
    addressR R = firstR(L);
    int temp = 0;
    while(R != NULL){
        if(name(Peserta(R)) == peserta){
            temp++;
        }
        R = nextR(R);
    }
    return temp;
}
