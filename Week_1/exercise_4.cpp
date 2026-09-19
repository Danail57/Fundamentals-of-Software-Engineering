
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
	if (word.length() > 15) return false;
	for (char symbol : word)
	{
		if (!isupper(symbol)) return false;
	}
	return true;
}

int main()
{
	string first_word, second_word;
	cout << "Write the first capitalized word: ";
	cin >> first_word;

	cout << "Write the second capitalized word: ";
	cin >> second_word;

	if (!is_valid(first_word) || !is_valid(second_word))
	{
		cout << "Invalid input! Words must be up to 15 uppercase letters." << endl;
		return 0;
	}

	int len1 = first_word.length();
	int len2 = second_word.length();

	int pos1 = -1;
	int pos2 = -1;

	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			if (first_word[i] == second_word[j])
			{
				pos1 = i;
				pos2 = j;
				break;
			}
		}
		if (pos1 != -1) break; 
	}
	// same letter / symbol
	if (pos1 != -1)
	{
		for (int r = 0; r < len2; r++)
		{
			if (r == pos2)
			{
				cout << first_word << endl;
			}
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
	
	else
	{
		cout << first_word << endl;

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
