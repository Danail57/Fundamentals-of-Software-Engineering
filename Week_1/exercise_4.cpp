
/*Съставете алгоритъм и напишете програма,
която въвежда от клавиатурата два низа,
съставени от главни латински букви, всеки с
дължина най-много 15 знака. Ако двата низа
имат поне една обща буква, програмата трябва
да отпечата хоризонтално на екрана първия от
низовете, а втория – вертикално, без да има
празни позиции между буквите им, така че двата
низа да се пресекат там, където общата буква
се среща за първи път и в двата низа. Ако
двата низа нямат нито една обща буква, тогава
програмата трябва да отпечата хоризонтално
първия низ, а от позицията, непосредствено
намираща се под позицията следваща след
последната буква на първия низ – да отпечата
вертикално надолу втория низ.
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool is_valid(string word)
{
	if (word.length() == 0 || word.length() > 15)
	{
		return false;
	}

	for (char symbol : word)
	{
		if (!isupper(symbol)) 
		{
			return false;
		}
	}
	return true;
}


// Helper function for secure word input with validation loop
string get_valid_word(string prompt)
{
	string word;
	while (true) 
	{
		cout << prompt;
		cin >> word;

		if (is_valid(word)) 
		{
			return word;
		}
		cout << "Invalid input! The word must contain ONLY uppercase Latin letters (A-Z) and max 15 characters.\n\n";
	}
}


int main()
{
	string first_word = get_valid_word("Write the first capitalized word:");
	string second_word = get_valid_word("Write the second capitalized word: ");

	int len1 = first_word.length();
	int len2 = second_word.length();

	// Variables to store intersection positions
	int pos1 = -1;// Index of matching character in first_word
	int pos2 = -1;// Index of matching character in second_word


	// find the first common letter in both words
	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			if (first_word[i] == second_word[j])
			{
				pos1 = i;
				pos2 = j;
				break; // Stop inner loop once the match is found
			}
		}
		if (pos1 != -1) 
		{
			break; // Stop outer loop as soon as the first overall match is found
		}
	}


	// case 1: Words share at least one common letter
	if (pos1 != -1)
	{
		for (int r = 0; r < len2; r++)
		{
			// At the intersection row, 
			// print the entire first word
			if (r == pos2)
			{
				cout << first_word << endl;
			}

			// For other rows, print spaces up to pos1,
			// then the character from second_word
			else
			{
				for (int c = 0; c < pos1; c++)
				{
					cout << " ";
				}
				cout << second_word[r] << endl;
			}
		}
	}

	// case 2: No common letters found
	else
	{
		// Print the first word horizontally
		cout << first_word << endl;


		// Print the second word vertically
		// starting directly below
		// the position after the first word
		for (int r = 0; r < len2; r++)
		{
			for (int c = 0; c < len1; c++)
			{
				cout << " ";
			}
			cout << second_word[r] << endl;
		}
	}
}
