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
#include "StartGame.h"
void changeNumberOfLetters()
{
	cout << "Enter the new number of letters: ";
	cin >> lettersLimit;
}

void changeNumberOfRounds()
{
	cout << "Enter the new number of rounds: ";
	cin >> rounds;
}

void changeShuffleLimit()
{
	cout << "Enter the new number of shuffles: ";
	cin >> shuffleLimit;
}

void enterNewWord()
{
	string out_word;
	ofstream myfile("dictionary.txt", ios::out | ios::app | ios::binary);
	cout << "Please enter a word: ";
	cin >> out_word;	  //Trying to input the user specified word
	if (myfile.is_open())
	{
		myfile << endl << out_word;
		myfile.close();
	}
}