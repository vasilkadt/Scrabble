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
* Main file
*
*/

#include "design.h"
#include "StartGame.h"
#include "Settings.h"

int main()
{
	fstream file;
	file.open("dictionary.txt");
	if (file.fail())
	{
		cout << "Error opening the file" << endl;
	}

	bool gameOn = true;

	title();
	menu();

	while (gameOn)
	{
		int input;
		cout << endl<<"\t\t\tEnter your choice : ";
		cin >> input;
		cout << endl;

		switch (input)
		{
		case 1:
			startGame();
			gameOn = false;
			file.close();
			break;
		case 2:
			changeNumberOfLetters();
			break;
		case 3:
			changeNumberOfRounds();
			break;
		case 4:
			changeShuffleLimit();
			break;
		case 5:
			enterNewWord();
			break;
		case 6:
			gameOn = false;
			file.close();
			break;
		default:
			cout << "Invalid number!";
			return 0;
			break;
		}
	}
}