#include "main.h"
#include "menu.h"

using namespace std;

int main()
{
    ListP Lpersonal;
    ListC Lcompetition;
    ListR Lrelation;

    Create_ListP(Lpersonal);
    Create_ListC(Lcompetition);
    Create_ListR(Lrelation);

    addressP P;
    addressC C;

    P = AllocationP("Edgar Vigo","Bukit Tinggi",15,"001");
    Insert_by_NameP(Lpersonal,P);

    P = AllocationP("Raihan Muhith","Serang",18,"002");
    Insert_by_NameP(Lpersonal,P);

    C = AllocationC("ICPC",2019,"Porto");
    Insert_LastC(Lcompetition,C);

    C = AllocationC("VOCOMFEST",2018,"Jakarta");
    Insert_LastC(Lcompetition,C);


    char ans = 'A';
    while(ans != '0'){
        system("cls");
        cout << "o==============================================o" << endl;
        cout << "|                  Menu Utama                  |" << endl;
        cout << "o==============================================o" << endl;
        cout << "| 1. Tambahkan Data                            |" << endl;
        cout << "| 2. Ubah Data                                 |" << endl;
        cout << "| 3. Hapus Data                                |" << endl;
        cout << "| 4. Tampilkan Data                            |" << endl;
        cout << "|                                              |" << endl;
        cout << "| 0. Keluar                                    |" << endl;
        cout << "o==============================================o" << endl;
        cout << "| Menu :                                       |" << endl;
        cout << "o==============================================o" << endl;
        gotoxy(9,10);
        ans = getche();
        switch(ans){
            case '1' :
                Insert_Menu(Lpersonal,Lcompetition,Lrelation);
                break;
            case '2' :
                Edit_Menu(Lpersonal,Lcompetition,Lrelation);
                break;
            case '3' :
                Delete_Menu(Lpersonal,Lcompetition,Lrelation);
                break;
            case '4' :
                View_Menu(Lpersonal,Lcompetition,Lrelation);
                break;
            case '0' :
                break;
        }
    }
}
