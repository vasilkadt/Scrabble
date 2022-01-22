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
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include<windows.h>
using namespace std;

int lettersLimit = 10;
int rounds = 5;
int shuffleLimit = 2;
int remainingTries = 2;

bool validateCharacters(string word, vector<char> letters, vector<string> dictionary, int gameLettersLimit)
{
	//Check if the word has more letters than expected
	if (word.length() > gameLettersLimit)
	{
		return false;
	}

	//Check if the generated letters can form the word
	for (char character : word)
	{
		if (find(letters.begin(), letters.end(), character) != letters.end() == false)
		{
			return false;
		}
	}

	//Check if the dictionary contains the word
	if (find(dictionary.begin(), dictionary.end(), word) != dictionary.end() == false)
	{
		return false;
	}

	return true;
}
void startGame()
{
	//Create a vector of strings from the dictionary txt file
	vector<string> dictionary;
	ifstream file("dictionary.txt");
	copy(istream_iterator<string>(file), istream_iterator<string>(), back_inserter(dictionary));

	vector<char> letters;
	int score = 0;
	int roundNumber = 1;
	int gameLettersLimit = lettersLimit;
	int gameRounds = rounds;
	int gameShuffleLimit = shuffleLimit;
	int gameRemainingTries = remainingTries;
	int counterZero = 0;
	bool noMoreTries = false;
	while (gameRounds > 0 && gameRemainingTries > 0)
	{
		string word;
		if (noMoreTries)
		{
			cout << "No more shuffles!" << endl;
			cout << endl;
			cout << "Round: " << roundNumber << ". Try with word or type 0 for new letters:" << endl;
			cout << "Available letters: ";
			for (int i = 0; i < letters.size(); i++)
			{
				cout << letters[i] << " ";
			}
			cout << endl;
			cin >> word;
		}
		else {
			//Initialize the random number generator used by rand()
			srand(time(NULL));
			int lastVowel = 0;
			int counter = 0;
			//Fill the char vector with random english letters
			for (int i = 0; i < gameLettersLimit; i++)
			{
				letters.push_back('a' + rand() % 26);
				if (letters[i] == 'a' || letters[i] == 'e' || letters[i] == 'u' || letters[i] == 'i' || letters[i] == 'o')
				{
					counter++;
				}
				else lastVowel = i;
			}
			if (counter <= 1)
			{
				char vowel = "aeiou"[rand() % 5];
				if (counter == 0)
				{
					char secondVowel = "aeiou"[rand() % 5];
					letters[lastVowel - 1] = secondVowel;
				}
				letters[lastVowel] = vowel;
			}
			cout << endl;
			cout << "Round: " << roundNumber << ". Try with word or type 0 for new letters:" << endl;
			cout << "Available letters: ";
			for (int i = 0; i < letters.size(); i++)
			{
				cout << letters[i] << " ";
			}
			cout << endl;
			cin >> word;
		}
		if (word == "0")
		{
			counterZero++;

			if (counterZero > gameShuffleLimit)
			{
				noMoreTries = true;
			}
			else
			{
				letters.clear();
			}
			continue;
		}
		else if (!validateCharacters(word, letters, dictionary, gameLettersLimit))
		{
			letters.clear();
			gameRemainingTries--;
			cout << "Invalid word. Remaining tries: " << gameRemainingTries << endl;
			if (gameRemainingTries == 0)
			{
				roundNumber++;
				gameRounds--;
				gameRemainingTries = remainingTries;
				if (gameRounds == 0)
				{
					cout << "Congratulations! You completed the game successfully with " << score << " points." << endl;
				}
			}
			continue;
		}
		else
		{
			letters.clear();
			score += word.length();
			cout << "Your points so far are: " << score << endl;
			roundNumber++;
			gameRounds--;

			if (gameRounds == 0)
			{
				cout << "Congratulations! You completed the game successfully with " << score << " points." << endl;
			}
		}
	}
}
