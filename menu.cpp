#include "menu.h"

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void Insert_Participant(ListP &Lpersonal){
    char ans = 'y';
    string name,hometown,id;
    int age;
    while(ans != 'n'){
        system("cls");
        cout << "o====================================================o" << endl;
        cout << "|               Tambahkan Data Peserta               |" << endl;
        cout << "o====================================================o" << endl;
        cout << "| Nama     :                                         |" << endl;
        cout << "| ID       :                                         |" << endl;
        cout << "| Umur     :                                         |" << endl;
        cout << "| Asal     :                                         | " << endl;
        cout << "|----------------------------------------------------|" << endl;
        cout << "|                                                    |" << endl;
        cout << "o====================================================o" << endl;
        cout << "|                                                    |" << endl;
        cout << "o====================================================o" << endl;
        gotoxy(13,3);
        getline(cin >> ws,name);
        gotoxy(13,4);
        getline(cin >> ws,id);
        gotoxy(13,5);
        cin >> age;
        gotoxy(13,6);
        getline(cin >> ws,hometown);
        addressP P = firstP(Lpersonal);
        while(P != NULL && ID(P)!= id)  {
            P = nextP(P);
        }
        if(P == NULL ){
            addressP node = AllocationP(name,hometown,age,id);
            Insert_by_NameP(Lpersonal,node);
            gotoxy(2,8);
            cout << "Data Berhasil Ditambahkan" << endl;
        } else {
            gotoxy(2,8);
            cout << "ID Sudah Terdaftar" << endl;
        }
        gotoxy(2,10);
        Sleep(1000);
        cout <<"Tambah Data Lagi? [y/n]"<< endl;
        do{
            gotoxy(25,10);
            ans = getch();
        } while(ans != 'y' && ans != 'n');
    }
}
void Insert_Competition(ListC &Lcompetition){
    char ans = 'y';
    string name,area;
    int year;
    while(ans != 'n'){
        system("cls");
        cout << "o====================================================o" << endl;
        cout << "|               Tambah Data Kompetisi                |" << endl;
        cout << "o====================================================o" << endl;
        cout << "| Nama Kompetisi     :                               |" << endl;
        cout << "| Tahun Pelaksanaan  :                               |" << endl;
        cout << "| Tempat Pelaksanaan :                               |" << endl;
        cout << "|----------------------------------------------------|" << endl;
        cout << "|                                                    |" << endl;
        cout << "o====================================================o" << endl;
        cout << "|                                                    |" << endl;
        cout << "o====================================================o" << endl;
        gotoxy(23,3);
        getline(cin >>ws,name);
        gotoxy(23,4);
        cin >> year;
        gotoxy(23,5);
        getline(cin >> ws, area);
        addressC P = firstC(Lcompetition);
        while(P!= NULL && nextC(P) != firstC(Lcompetition) && Comp_Name(P)!=name)  {
            P = nextC(P);
        }
        if(P != NULL && Comp_Name(P)!=name){
            P = NULL;
        }
        if(P == NULL){
            addressC node = AllocationC(name,year,area);
            Insert_LastC(Lcompetition,node);
            gotoxy(2,7);
            cout << "Data Berhasil Ditambahkan" << endl;
        } else {
            gotoxy(2,7);
            cout << "Nama Kompetisi Sudah Terdaftar" << endl;
        }
        gotoxy(2,9);
        Sleep(1000);
        cout <<"Tambah Data Lagi?[y/n]"<< endl;
        do{
            gotoxy(24,9);
            ans = getch();
        } while(ans != 'y' && ans != 'n');
    }
}
void Insert_Relation(ListP &Lpersonal,ListC &Lcompetition,ListR &Lrelation){
    char ans = 'y';
    string ParticipantID;
    string contest;
    int flag = CountListP(Lpersonal)+CountListC(Lcompetition);
    while(ans != 'n'){
        system("cls");
        cout << "o========================================================o" << endl;
        cout << "|               Insert Peserta Kompetisi                 |" << endl;
        cout << "o========================================================o" << endl;
        cout << " Contest ID List :" << endl;
        Print_InfoC(Lcompetition);
        cout << " Contestant ID List :" << endl;
        Print_InfoP(Lpersonal);
        cout << "o========================================================o" << endl;
        cout << "| ID Peserta    :                                        |" << endl;
        cout << "| Kompetisi     :                                        |" << endl;
        cout << "|--------------------------------------------------------|" << endl;
        cout << "|                                                        |" << endl;
        cout << "o========================================================o" << endl;
        cout << "|                                                        |" << endl;
        cout << "o========================================================o" << endl;
        gotoxy(19,8+flag);
        getline(cin >> ws, ParticipantID);
        gotoxy(19,9+flag);
        getline(cin >> ws, contest);
        addressP Participant = Find_ID_P(Lpersonal,ParticipantID);
        addressC Contest = Find_Name_C(Lcompetition,contest);

        if(Participant != NULL && Contest != NULL){
            addressR R = Find_Relation(Lrelation,Contest,Participant);
            if(R == NULL){
                R = allocationR(Participant,Contest);
                Insert_FirstR(Lrelation,R);
                gotoxy(2,11+flag);
                cout << "Data Behasil Ditambahkan" << endl;
            } else {
                gotoxy(2,11+flag);
                cout << name(Participant) <<" Sudah Terdaftar di Kompetisi "<< Comp_Name(Contest)<< endl;
            }
        } else if(Contest == NULL) {
            gotoxy(2,11+flag);
            cout << "Kompetisi Tidak Terdaftar" << endl;
        } else{
            gotoxy(2,11+flag);
            cout << "ID Peserta Tidak Terdaftar" << endl;
        }
        gotoxy(2,13+flag);
        Sleep(1000);
        cout <<"Add More Data? [y/n]"<< endl;
        do{
            gotoxy(23,13+flag);
            ans = getch();
        } while(ans != 'y' && ans != 'n');
    }
}
void Insert_Menu(ListP &Lpersonal,ListC &Lcompetition,ListR &Lrelation){
    char ans = 'A';
    while(ans != '0'){
        system("cls");
        cout << "o=========================================o" << endl;
        cout << "|              Insert Menu                |" << endl;
        cout << "o=========================================o" << endl;
        cout << "| 1. Insert Data Peserta                  |" << endl;
        cout << "| 2. Insert Data Kompetisi                |" << endl;
        cout << "| 3. Insert Peserta Kompetisi             |" << endl;
        cout << "|                                         |" << endl;
        cout << "| 0. Keluar                               |" << endl;
        cout << "o=========================================o" << endl;
        cout << "| Menu :                                  |" << endl;
        cout << "o=========================================o" << endl;
        gotoxy(9,9);
        ans = getche();
        switch(ans){
            case '1' :
                Insert_Participant(Lpersonal);
                break;
            case '2' :
                Insert_Competition(Lcompetition);
                break;
            case '3' :
                Insert_Relation(Lpersonal,Lcompetition,Lrelation);
                break;
            case '0' :
                break;
        }
    }
}
void Edit_Menu(ListP &Lpersonal,ListC &Lcompetition,ListR &Lrelation){
    cout << "X";
}
void Delete_Peserta(ListP &Lpersonal,ListC &Lcompetition,ListR &Lrelation){
    char ans = 'y';
    string id;
    int flag = CountListP(Lpersonal);
    while(ans != 'n'){
        system("cls");
        cout << "o======================================================o" << endl;
        cout << "|                  Hapus Data Peserta                  |" << endl;
        cout << "o======================================================o" << endl;
        Print_InfoP(Lpersonal);
        gotoxy(0,4+flag);
        cout << "o======================================================o" << endl;
        cout << "| ID Peserta yang Ingin Dihapus :                      |" << endl;
        cout << "o======================================================o" << endl;
        gotoxy(34,5+flag);
        getline(cin>>ws,id);

        addressP P = Find_ID_P(Lpersonal,id);
        if(P!=NULL){
            delete_relation_peserta(Lrelation,name(P));
            Delete_by_NameP(Lpersonal,P,name(P));
            DeallocationP(P);
            gotoxy(0,8+flag);
            cout << "o==================================o" << endl;
            cout << "|      Data Berhasil Dihapus       |" << endl;
            cout << "|----------------------------------|" << endl;
            cout << "|                                  |" << endl;
            cout << "o==================================o" << endl;
            Sleep(1000);
            gotoxy(2,11+flag);
            cout <<"Hapus Data Lagi?[y/n]"<< endl;
            do{
                gotoxy(23,11+flag);
                ans = getch();
            } while(ans != 'y' && ans != 'n');
            flag = CountListP(Lpersonal);
        } else {
            gotoxy(0,8+flag);
            cout << "o==================================o" << endl;
            cout << "|        ID Tidak Ditemukan        |" << endl;
            cout << "|----------------------------------|" << endl;
            cout << "|                                  |" << endl;
            cout << "o==================================o" << endl;
            Sleep(1000);
            gotoxy(2,11+flag);
            cout <<"Hapus Data Lagi?[y/n]"<< endl;
            do{
                gotoxy(23,11+flag);
                ans = getch();
            } while(ans != 'y' && ans != 'n');
        }
    }
}
void Delete_Kompetisi(ListP &Lpersonal,ListC &Lcompetition,ListR &Lrelation){
    char ans = 'y';
    string id;
    int flag = CountListC(Lcompetition);
    while(ans != 'n'){
        system("cls");
        cout << "o======================================================o" << endl;
        cout << "|                 Hapus Data Kompetisi                 |" << endl;
        cout << "o======================================================o" << endl;
        Print_InfoC(Lcompetition);
        gotoxy(0,4+flag);
        cout << "o======================================================o" << endl;
        cout << "| Nama Kompetisi  :                                    |" << endl;
        cout << "o======================================================o" << endl;
        gotoxy(20,5+flag);
        getline(cin>>ws,id);

        addressC P = Find_Name_C(Lcompetition,id);
        if(P!=NULL){
            delete_relation_kompetisi(Lrelation,Comp_Name(P));
            Delete_by_NameC(Lcompetition,P,Comp_Name(P));
            DeallocationC(P);
            gotoxy(0,8+flag);
            cout << "o==================================o" << endl;
            cout << "|      Data Berhasil Dihapus       |" << endl;
            cout << "|----------------------------------|" << endl;
            cout << "|                                  |" << endl;
            cout << "o==================================o" << endl;
            Sleep(1000);
            gotoxy(2,11+flag);
            cout <<"Hapus Data Lagi?[y/n]"<< endl;
            do{
                gotoxy(23,11+flag);
                ans = getch();
            } while(ans != 'y' && ans != 'n');
            flag = CountListC(Lcompetition);
        } else {
            gotoxy(0,8+flag);
            cout << "o==================================o" << endl;
            cout << "|       Data Tidak Ditemukan       |" << endl;
            cout << "|----------------------------------|" << endl;
            cout << "|                                  |" << endl;
            cout << "o==================================o" << endl;
            Sleep(1000);
            gotoxy(1,11+flag);
            cout <<"Hapus Data Lagi?[y/n]"<< endl;
            do{
                gotoxy(23,11+flag);
                ans = getch();
            } while(ans != 'y' && ans != 'n');
        }
    }
}
void Delete_Relasi(ListP &Lpersonal,ListC &Lcompetition,ListR &Lrelation){
    char ans = 'y';
    string id,contest;
    int flag = CountListP(Lpersonal);
    while(ans != 'n'){
        system("cls");
        cout << "o======================================================o" << endl;
        cout << "|             Hapus Peserta dari Kompetisi             |" << endl;
        cout << "o======================================================o" << endl;
        addressC C = firstC(Lcompetition);
        if(C != NULL){
            do{
                cout << " Kompetisi : " << Comp_Name(C) << endl;
                cout << " Tahun     : " << year(C) << endl;
                cout << " Tempat    : " << place(C) << endl;
                cout << " Peserta   : " << endl;
                print_info_kompetisi(Lrelation,Comp_Name(C));
                cout << "o============================================o" << endl;
                C = nextC(C);
            } while(C != firstC(Lcompetition));
            cout << " Nama Kompetisi : ";
            getline(cin >> ws, contest);
            cout << " ID Peserta     : ";
            getline(cin >> ws,id);
            cout << endl;

            addressR R = firstR(Lrelation);
            while(R != NULL && (Comp_Name(Kompetisi(R)) != contest || ID(Peserta(R))!=id)){
                R = nextR(R);
            }
            if(R != NULL){
                delete_relation(Lrelation,R);
                DeallocationR(R);
                cout << "o==================================o" << endl;
                cout << "|      Data Berhasil Dihapus       |" << endl;
                cout << "o==================================o" << endl;
            } else {
                cout << "o==================================o" << endl;
                cout << "|       Data Tidak Ditemukan       |" << endl;
                cout << "o==================================o" << endl;
            }
            cout << endl;
            cout <<"Hapus Data Lagi?[y/n]"<< endl;
            do{
                ans = getch();
            } while(ans != 'y' && ans != 'n');
        } else {
            cout << "TIdak Ada Data Yang Tersedia" << endl;
            Sleep(2000);
            break;
        }
    }
}
void Delete_Menu(ListP &Lpersonal,ListC &Lcompetition,ListR &Lrelation){
    char ans = 'A';
    while(ans != '0'){
        system("cls");
        cout << "o==============================================o" << endl;
        cout << "|               Menu Hapus Data                |" << endl;
        cout << "o==============================================o" << endl;
        cout << "| 1. Hapus Data Peserta                        |" << endl;
        cout << "| 2. Hapus Data Kompetisi                      |" << endl;
        cout << "| 3. Hapus Peserta dari suatu Kompetisi        |" << endl;
        cout << "|                                              |" << endl;
        cout << "| 0. Keluar                                    |" << endl;
        cout << "o==============================================o" << endl;
        cout << "| Menu :                                       |" << endl;
        cout << "o==============================================o" << endl;
        gotoxy(9,9);
        ans = getche();
        switch(ans){
            case '1' :
                Delete_Peserta(Lpersonal,Lcompetition,Lrelation);
                break;
            case '2' :
                Delete_Kompetisi(Lpersonal,Lcompetition,Lrelation);
                break;
            case '3' :
                Delete_Relasi(Lpersonal,Lcompetition,Lrelation);
                break;
            case '0' :
                break;
        }
    }
}
void View_Kompetisi(ListP Lpersonal,ListC Lcompetition,ListR Lrelation){
    system("cls");
    string id;
    cout << "o=====================================================================o" << endl;
    cout << "|                           Data Kompetisi                            |" << endl;
    cout << "o=====================================================================o" << endl;
    cout << "| Nama Kompetisi :                         |" << endl;
    cout << "o==========================================o" << endl;
    gotoxy(19,3);
    bool flag = false;
    getline(cin >> ws,id);
    int n = 0;
    addressC C = firstC(Lcompetition);
    if(C!=NULL){
        while(nextC(C)!= firstC(Lcompetition)){

            if(Comp_Name(C) == id){
                gotoxy(0,5+3*n);
                cout << " Kompetisi : " << Comp_Name(C) << endl;
                cout << " Tahun     : " << year(C) << endl;
                cout << " Tempat    : " << place(C) << endl;
                cout << " Peserta   : " << endl;
                print_info_kompetisi(Lrelation,Comp_Name(C));
                cout << "o============================================o" << endl;
                flag = true;
                n++;
            }
            C = nextC(C);

        }
        if(Comp_Name(C) == id){
            gotoxy(0,5+3*n);
            cout << " Kompetisi : " << Comp_Name(C) << endl;
            cout << " Tahun     : " << year(C) << endl;
            cout << " Tempat    : " << place(C) << endl;
            cout << " Peserta   : " << endl;
            print_info_kompetisi(Lrelation,Comp_Name(C));
            cout << "o============================================o" << endl;
            flag = true;
        }
    }
    if(!flag){
        gotoxy(0,5);
        cout << " Kompetisi " << id << " Tidak Ditemukan" << endl;
    }
}
void View_Peserta(ListP Lpersonal,ListC Lcompetition,ListR Lrelation){
    system("cls");
    string id;
    cout << "o=====================================================================o" << endl;
    cout << "|                            Data Peserta                             |" << endl;
    cout << "o=====================================================================o" << endl;
    cout << "| ID Peserta :                         |" << endl;
    cout << "o======================================o" << endl;
    gotoxy(15,3);
    getline(cin >> ws,id);
    addressP P = firstP(Lpersonal);
    while(P != NULL && ID(P)!= id){
        P = nextP(P);
    }

    if(P!= NULL && ID(P) == id){
        gotoxy(0,5);
        cout << " Data Peserta ID " << ID(P) << " :" << endl << endl;
        cout << " Nama      : " << name(P) << endl;
        cout << " Umur      : " << age(P) << endl;
        cout << " Asal      : " << city(P) << endl;
        cout << " Kompetisi : " << endl;
        print_info_Peserta(Lrelation,name(P));

        cout << "o======================================o" << endl;
    } else {
        gotoxy(0,5);
        cout << " ID " << id << " Tidak Ditemukan" << endl;
    }
}
void View_All(ListP Lpersonal,ListC Lcompetition,ListR Lrelation){
    system("cls");
    cout << "o===========================================================================o" << endl;
    cout << "|                                Seluruh Data                               |" << endl;
    cout << "o===========================================================================o" << endl;
    addressC C = firstC(Lcompetition);
    addressP P = firstP(Lpersonal);
    int MaxPeserta = INT_MIN;
    int MinPeserta = INT_MAX;
    int MaxKompetisi = INT_MIN;
    int MinKompetisi = INT_MAX;
    if(P != NULL){
        int n = 1;
        while(P != NULL){
            cout << n << ") " << name(P) << ", ID : " << ID(P) << ", " << age(P) << " Tahun, " << "Asal : " << city(P) << ", Kompetisi :" << endl;
            print_info_Peserta(Lrelation,name(P));
            cout << endl;
            if(CountKompetisi(Lrelation,name(P)) > MaxKompetisi)
                MaxKompetisi = CountKompetisi(Lrelation,name(P));
            if(CountKompetisi(Lrelation,name(P)) < MinKompetisi)
                MinKompetisi = CountKompetisi(Lrelation,name(P));
            n++;
            P = nextP(P);
        }
        if(C != NULL){
            do {
                if(CountPeserta(Lrelation,Comp_Name(C)) > MaxPeserta)
                    MaxPeserta = CountPeserta(Lrelation,Comp_Name(C));
                if(CountPeserta(Lrelation,Comp_Name(C)) < MinPeserta)
                    MinPeserta = CountPeserta(Lrelation,Comp_Name(C));
                C = nextC(C);
            }while(C != firstC(Lcompetition));
        }


        cout << "o===========================================================================o" << endl;
        cout << " Kompetisi Dengan Peserta Terbanyak : ";
        C = firstC(Lcompetition);
        do {
            if(CountPeserta(Lrelation,Comp_Name(C)) == MaxPeserta){
                cout << Comp_Name(C) <<", ";
            }
            C = nextC(C);
        }while(C != firstC(Lcompetition));
        cout << "dengan " << MaxPeserta << " peserta"<< endl;

        cout << " Kompetisi Dengan Peserta Terendah  : ";
        C = firstC(Lcompetition);
        do {
            if(CountPeserta(Lrelation,Comp_Name(C)) == MinPeserta){
                cout << Comp_Name(C) <<", ";
            }
            C = nextC(C);
        }while(C != firstC(Lcompetition));
        cout << "dengan " << MinPeserta << " peserta"<< endl;

        cout << " Peserta Dengan Kompetisi Terbanyak : ";
        P = firstP(Lpersonal);
        while(P != NULL){
            if(CountKompetisi(Lrelation,name(P)) == MaxKompetisi)
                cout << name(P) <<", ";
            P = nextP(P);
        }
        cout << "dengan " << MaxKompetisi << " kompetisi"<< endl;

        cout << " Peserta Dengan Kompetisi Terendah  : ";
        P = firstP(Lpersonal);
        while(P != NULL){
            if(CountKompetisi(Lrelation,name(P)) == MinKompetisi)
                cout << name(P) <<", ";
            P = nextP(P);
        }
        cout << "dengan " << MinKompetisi << " kompetisi"<< endl;
        cout << "o===========================================================================o" << endl;
    } else {
        cout << "Tidak Ada Data Yang Tersedia " << endl;
    }
}
void View_Menu(ListP Lpersonal,ListC Lcompetition,ListR Lrelation){
    char ans = 'A';
    while(ans != '0'){
        system("cls");
        cout << "o=========================================o" << endl;
        cout << "|               View Menu                 |" << endl;
        cout << "o=========================================o" << endl;
        cout << "| 1. Data Kompetisi                       |" << endl;
        cout << "| 2. Data Peserta                         |" << endl;
        cout << "| 3. Seluruh Data                         |" << endl;
        cout << "|                                         |" << endl;
        cout << "| 0. Keluar                               |" << endl;
        cout << "o=========================================o" << endl;
        cout << "| Menu :                                  |" << endl;
        cout << "o=========================================o" << endl;
        gotoxy(9,9);
        ans = getche();
        switch(ans){
            case '1' :
                View_Kompetisi(Lpersonal,Lcompetition,Lrelation);
                getche();
                break;
            case '2' :
                View_Peserta(Lpersonal,Lcompetition,Lrelation);
                getch();
                break;
            case '3' :
                View_All(Lpersonal,Lcompetition,Lrelation);
                getche();
                break;
            case '0' :
                break;
        }
    }
}
