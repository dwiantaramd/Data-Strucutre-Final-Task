#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <string>
#include <cstddef>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#include "main.h"
#include "Personal.h"
#include "Competition.h"
#include "Relation.h"

using namespace std;

void gotoxy(int x,int y);
void Insert_Participant(ListP &Lpersonal);
void Insert_Competition(ListC &Lcompetition);
void Insert_Relation(ListP &Lpersonal,ListC &Lcompetition,ListR &Lrelation);
void Insert_Menu(ListP &Lpersonal,ListC &Lcompetition,ListR &Lrelation);
void Edit_Menu(ListP &Lpersonal,ListC &Lcompetition,ListR &Lrelation);
void Delete_Peserta(ListP &Lpersonal,ListC &Lcompetition,ListR &Lrelation);
void Delete_Kompetisi(ListP &Lpersonal,ListC &Lcompetition,ListR &Lrelation);
void Delete_Relasi(ListP &Lpersonal,ListC &Lcompetition,ListR &Lrelation);
void Delete_Menu(ListP &Lpersonal,ListC &Lcompetition,ListR &Lrelation);
void View_Kompetisi(ListP Lpersonal,ListC Lcompetition,ListR Lrelation);
void View_Peserta(ListP Lpersonal,ListC Lcompetition,ListR Lrelation);
void View_All(ListP Lpersonal,ListC Lcompetition,ListR Lrelation);
void View_Menu(ListP Lpersonal,ListC Lcompetition,ListR Lrelation);

#endif // MENU_H_INCLUDED
