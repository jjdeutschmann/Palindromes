//****************************************************************************************************
//
//     File: pal.cpp
//
//     Author: Jennifer Deutschmann
//
//     This program reads in a string and uses a stack and a queue to see if the string is
//	   a palindrome along with its type, if valid. Regardless, it will print out the string in
//     opposite order as well as determine the type of palindrome it is.
//		
//     Other files needed:
//     1. node.h
//     2. queue.h
//     3. stack.h		 
//		
//****************************************************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

#include "stack.h"
#include "queue.h"

//****************************************************************************************************

bool testDisplayPalindrome ( Stack<char> & backwardPhrase, Queue<char> & forwardPhrase );
char getType ( bool space, bool punct );
void displayType ( char t );

//****************************************************************************************************

int main ()
{
	ifstream inFile ("palindromes.txt");
	Stack<char> backwardPhrase(80);
	Queue<char> forwardPhrase;
	string phrase;
	char type;
	int len;
	bool space;
	bool punct;

	cout << "\tPalindrome Type Guide: \nType 1: no spaces or punctuation\n"
		 << "Type 2: with spaces but no punctuation\n"
		 << "Type 3: with punctuation (with or without spaces)\n\n"
		 << "Enter strings to evaluate (enter 'q' to quit).\n";

	while ( getline(cin, phrase) && tolower(phrase[0]) != 'q')
	{
		space = false;
		punct = false;

		len = int( phrase.length() );

		for (int i = 0; i < len; i++)
		{
			if ( isalpha(phrase[i]) )
			{
				backwardPhrase.push( tolower(phrase[i]) );
				forwardPhrase.enqueue ( tolower(phrase[i]) );
			}
			else if ( isspace(phrase[i]) )
				space = true;
			else if ( ispunct(phrase[i]) )
				punct = true;
		}

		if ( testDisplayPalindrome( backwardPhrase, forwardPhrase ) )
		{
			type = getType ( space, punct );
			displayType ( type );
		}
	}

	return 0;
}

//****************************************************************************************************

bool testDisplayPalindrome ( Stack<char> & backwardPhrase, Queue<char> & forwardPhrase)
{
	bool success = true;
	bool palindrome = true;
	char reverse[80];
	char stkLetter;
	char qLetter;
	int index = 0;

	while ( backwardPhrase.pop(stkLetter) && forwardPhrase.dequeue(qLetter) )
	{
		if ( stkLetter != qLetter )
			success = false;

		reverse[index] = stkLetter;
		index++;
	}

	reverse[index] = '\0';

	cout << setw(25) << left << reverse;

	if ( !success )
		cout << "invalid\n";

	return success;
}

//****************************************************************************************************

char getType ( bool space, bool punct )
{
	char type = '1';

	if ( punct )
		type = '3';
	else if ( space )
		type = '2';

	return type;
}

//****************************************************************************************************

void displayType ( char t )
{
	cout << "Type " << t << "\n";
}

//****************************************************************************************************