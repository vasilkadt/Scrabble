/*
*
* Solution to course project # 7
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Vasilka Terzieva
* @idnumber 5MI0600024
* @compiler VC
*
* Header file with helper functions
*
*/

#pragma once
#include "StartGame.h";
using namespace std;

void setcolorandbackground(int textColor, int backgroundColor)
{//set text color and background color
	WORD color = ((backgroundColor & 0x0F) << 4) + (textColor & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void title()
{//prints title of the program
	cout << endl;
	setcolorandbackground(9, 0);
	cout << "\t\t\t|---------------------------------------|" << endl;
	cout << "\t\t\t|";
	setcolorandbackground(14, 0);
	cout << "\tWelcome to SCRABBLE GAME!!";
	setcolorandbackground(9, 0);
	cout << "\t|" << endl;
	cout << "\t\t\t|---------------------------------------|\n" << endl;
}
void menu()
{//prints menu of the program
	setcolorandbackground(6, 0);
	cout << "\n\n\t\t";
	setcolorandbackground(14, 13);
	cout << "----------- MAIN MENU -----------";
	setcolorandbackground(9, 0);
	cout << "\n\n\t\t1.Start a new game." << endl;
	cout << "\n\t\t2.Change the number of letters." << endl;
	cout << "\n\t\t3.Change the number of rounds." << endl;
	cout << "\n\t\t4.Change the number of huffles." << endl;
	cout << "\n\t\t5.Enter a new word." << endl;
	cout << "\n\t\t6.Exit." << endl;
	setcolorandbackground(15, 0);
}