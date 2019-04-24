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
    char ans = 'A';
    while(ans != '0'){
        system("cls");
        cout << "o=========================================o" << endl;
        cout << "|                Main Menu                |" << endl;
        cout << "o=========================================o" << endl;
        cout << "| 1. Insert Data                          |" << endl;
        cout << "| 2. Edit Data                            |" << endl;
        cout << "| 3. Delete Data                          |" << endl;
        cout << "| 4. View Data                            |" << endl;
        cout << "|                                         |" << endl;
        cout << "| 0. Exit                                 |" << endl;
        cout << "o=========================================o" << endl;
        cout << "| Menu :                                  |" << endl;
        cout << "o=========================================o" << endl;
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
