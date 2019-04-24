#include "menu.h"

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void Insert_Participant(ListP &Lpersonal){
    char ans = 'y';
    string name,hometown;
    int age;
    while(ans != 'n'){
        system("cls");
        cout << "o=========================================o" << endl;
        cout << "|            Insert Contestant            |" << endl;
        cout << "o=========================================o" << endl;
        cout << "| Name     :                              |" << endl;
        cout << "| Age      :                              |" << endl;
        cout << "| Hometown :                              |" << endl;
        cout << "|-----------------------------------------|" << endl;
        cout << "|                                         |" << endl;
        cout << "o=========================================o" << endl;
        cout << "|                                         |" << endl;
        cout << "o=========================================o" << endl;
        gotoxy(13,3);
        getline(cin >> ws,name);
        gotoxy(13,4);
        cin >> age;
        gotoxy(13,5);
        getline(cin >> ws,hometown);
        addressP P = firstP(Lpersonal);
        while(P != NULL && (name(P)!=name || age(P) != age || city(P)!= hometown))  {
            P = nextP(P);
        }
        if(P == NULL || (P != NULL && (name(P)!=name || age(P)!= age || city(P)!= hometown))){
            addressP node = AllocationP(name,hometown,age);
            Insert_by_NameP(Lpersonal,node);
            gotoxy(2,7);
            cout << "Data Successfully Added" << endl;
        } else {
            gotoxy(2,7);
            cout << "Multiple Data Detected!" << endl;
        }
        gotoxy(2,9);
        Sleep(1000);
        cout <<"Add More Data? [y/n]"<< endl;
        do{
            gotoxy(23,9);
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
        cout << "o=========================================o" << endl;
        cout << "|           Insert New Contest            |" << endl;
        cout << "o=========================================o" << endl;
        cout << "| Contest Name :                          |" << endl;
        cout << "| Year Held    :                          |" << endl;
        cout << "| Place Held   :                          |" << endl;
        cout << "|-----------------------------------------|" << endl;
        cout << "|                                         |" << endl;
        cout << "o=========================================o" << endl;
        cout << "|                                         |" << endl;
        cout << "o=========================================o" << endl;
        gotoxy(17,3);
        getline(cin >>ws,name);
        gotoxy(17,4);
        cin >> year;
        gotoxy(17,5);
        getline(cin >> ws, area);
        addressC P = firstC(Lcompetition);
        while(P!= NULL && nextC(P) != firstC(Lcompetition) && (Comp_Name(P)!=name || year(P) != year || place(P)!= area))  {
            P = nextC(P);
        }
        if(P != NULL && (Comp_Name(P)!=name || year(P) != year || (place(P)) != area)){
            P = NULL;
        }
        if(P == NULL){
            addressC node = AllocationC(name,year,area);
            Insert_LastC(Lcompetition,node);
            gotoxy(2,7);
            cout << "Data Successfully Added" << endl;
        } else {
            gotoxy(2,7);
            cout << "Multiple Data Detected!" << endl;
        }
        gotoxy(2,9);
        Sleep(1000);
        cout <<"Add More Data? [y/n]"<< endl;
        do{
            gotoxy(23,9);
            ans = getch();
        } while(ans != 'y' && ans != 'n');
    }
}
void Insert_Relation(ListP &Lpersonal,ListC &Lcompetition,ListR &Lrelation){
    char ans = 'y';
    string name,area;
    int year;
    while(ans != 'n'){
        system("cls");
        cout << "o=========================================o" << endl;
        cout << "|       Insert Contest Participant        |" << endl;
        cout << "o=========================================o" << endl;
        cout << "| Contest Name :                          |" << endl;
        cout << "| Year Held    :                          |" << endl;
        cout << "| Place Held   :                          |" << endl;
        cout << "|-----------------------------------------|" << endl;
        cout << "|                                         |" << endl;
        cout << "o=========================================o" << endl;
        cout << "|                                         |" << endl;
        cout << "o=========================================o" << endl;
        gotoxy(17,3);
        cin >> name;
        gotoxy(17,4);
        cin >> year;
        gotoxy(17,5);
        cin >> area;
        /*addressC P = firstC(Lcompetition);
        while(P!= NULL && nextC(P) != firstC(Lcompetition) && ((Comp_Name(P))!=name || year(P) != year || (place(P))!= area))  {
            P = nextC(P);
        }
        if(P != NULL && Comp_Name(P)!=name && year(P) != year && (place(P)) != area){
            P = NULL;
        }
        if(P == NULL){
            addressC node = AllocationC(name,year,area);
            Insert_LastC(Lcompetition,node);
            gotoxy(2,7);
            cout << "Data Successfully Added" << endl;
        } else {
            gotoxy(2,7);
            cout << "Multiple Data Detected!" << endl;
        }
        gotoxy(2,9);
        Sleep(1000);
        cout <<"Add More Data? [y/n]"<< endl;
        do{
            gotoxy(23,9);
            ans = getch();
        } while(ans != 'y' && ans != 'n');*/
    }
}
void Insert_Menu(ListP &Lpersonal,ListC &Lcompetition,ListR &Lrelation){
    char ans = 'A';
    while(ans != '0'){
        system("cls");
        cout << "o=========================================o" << endl;
        cout << "|              Insert Menu                |" << endl;
        cout << "o=========================================o" << endl;
        cout << "| 1. Insert Participant Data              |" << endl;
        cout << "| 2. Insert Competition Data              |" << endl;
        cout << "| 3. Insert Relation                      |" << endl;
        cout << "|                                         |" << endl;
        cout << "| 0. Exit                                 |" << endl;
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
void Delete_Menu(ListP &Lpersonal,ListC &Lcompetition,ListR &Lrelation){
    cout << "X";
}
void View_Menu(ListP Lpersonal,ListC Lcompetition,ListR Lrelation){
    char ans = 'A';
    while(ans != '0'){
        system("cls");
        cout << "o=========================================o" << endl;
        cout << "|               View Menu                 |" << endl;
        cout << "o=========================================o" << endl;
        cout << "| 1. View Participant Data                |" << endl;
        cout << "| 2. View Competition Data                |" << endl;
        cout << "| 3. View All Data                        |" << endl;
        cout << "|                                         |" << endl;
        cout << "| 0. Exit                                 |" << endl;
        cout << "o=========================================o" << endl;
        cout << "| Menu :                                  |" << endl;
        cout << "o=========================================o" << endl;
        gotoxy(9,9);
        ans = getche();
        switch(ans){
            case '1' :
                system("cls");
                Print_InfoP(Lpersonal);
                getche();
                break;
            case '2' :
                cout << "X";
                break;
            case '3' :
                cout <<"Y";
                break;
            case '0' :
                break;
        }
    }
}
