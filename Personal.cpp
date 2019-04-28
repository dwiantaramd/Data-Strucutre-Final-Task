#include "Personal.h"

void Create_ListP(ListP &L){
    firstP(L) = NULL;
    lastP(L) = NULL;
}
addressP AllocationP(string name,string city, int age,string idpeserta){
    addressP P = new elmlistP;
    name(P) = name;
    city(P) = city;
    age(P) = age;
    ID(P) = idpeserta;
    nextP(P) = NULL;
    prevP(P) = NULL;
    return P;
}
void DeallocationP(addressP &P){
    delete(P);
}
void Insert_FirstP(ListP &L, addressP P){
    if(firstP(L)== NULL){
        firstP(L) = P;
        lastP(L) = P;
    }else{
        nextP(P) = firstP(L);
        prevP(firstP(L)) = P;
        firstP(L) = P;
    }
}
void Insert_LastP(ListP &L, addressP P){
    if(firstP(L) == NULL){
        Insert_FirstP(L,P);
    } else {
        nextP(lastP(L)) = P;
        prevP(P) = lastP(L);
        lastP(L) = P;
    }
}
void Insert_AfterP(ListP &L, addressP prec, addressP P){
    prevP(nextP(prec)) = P;
    nextP(P) = nextP(prec);
    prevP(P) = prec;
    nextP(prec) = P;
}
void Delete_FirstP(ListP &L, addressP &P){
    if(firstP(L)!=NULL && lastP(L)!=NULL){
        P = firstP(L);
        if(firstP(L)==lastP(L)){
            firstP(L) = NULL;
            lastP(L) = NULL;
        }else{
            firstP(L) = nextP(P);
            prevP(nextP(P)) = NULL;
            nextP(P) = NULL;
        }
    }
}
void Delete_LastP(ListP &L, addressP &P){
    if(firstP(L)!=NULL && lastP(L)!=NULL){
        P = lastP(L);
        if(firstP(L)==lastP(L)){
            Delete_FirstP(L,P);
        }else{
            lastP(L) = prevP(P);
            nextP(prevP(P)) = NULL;
            prevP(P) = NULL;
        }
    }
}
void Delete_AfterP(ListP &L, addressP prec, addressP &P){
    P = nextP(prec);
    nextP(prec) = nextP(P);
    prevP(nextP(prec)) = prec;
    nextP(P) = NULL;
    prevP(P) = NULL;
}
addressP Find_Name_P(ListP L, string x){
    addressP P = NULL;
    P = firstP(L);
    while(P!= NULL && name(P)!= x) {
        P = nextP(P);
    }
    return P;
}
addressP Find_ID_P(ListP L, string x){
    addressP P = NULL;
    P = firstP(L);
    while(P!= NULL && ID(P)!= x) {
        P = nextP(P);
    }
    return P;
}
void Insert_by_NameP(ListP &L, addressP P){
     if(firstP(L)==NULL){
        lastP(L) = P;
        firstP(L) = P;
    }else{
        addressP Q = firstP(L);
        while(nextP(Q)!=NULL && name(nextP(Q))<= name(P)){
            Q = nextP(Q);
        }
        if(name(P)<= name(firstP(L))){
            Insert_FirstP(L,P);
        }else if(name(P)>name(lastP(L))){
            Insert_LastP(L,P);
        }else{
            Insert_AfterP(L,Q,P);
        }

    }
}
void Delete_by_NameP(ListP &L, addressP &P, string name){
    P = Find_Name_P(L,name);
    if(firstP(L)==NULL){
        cout<< name <<" Tidak Ditemukan"<<endl;
    }else if(firstP(L)==lastP(L)){
        P = firstP(L);
        firstP(L) = NULL;
        lastP(L) = NULL;
    }else{
        if(P == NULL){
            cout<< name <<" Tidak Ditemukan"<<endl;
        }else{
            if(P == firstP(L)){
                Delete_FirstP(L,P);
            }else if(P == lastP(L)){
                Delete_LastP(L,P);
            }else{
                addressP prec = prevP(P);
                Delete_AfterP(L,prec,P);
            }
        }
    }
}
void Print_InfoP(ListP L){
    if(firstP(L) == NULL)
        cout << " Tidak Ada Data Yang Terdaftar" << endl;
    else{
        addressP P = firstP(L);
        int n = 1;
        while(P != NULL){
            cout << "  " <<n <<". "<< name(P) <<", "<< age(P) <<" Tahun, " << city(P) <<", ID : "<<ID(P) << endl;
            n++;
            P = nextP(P);
        }
        cout << endl;
    }
}
int CountListP(ListP L){
    int sum = 0;
    addressP P = firstP(L);
    while(P != NULL){
        sum++;
        P = nextP(P);
    }
    return sum;
}
