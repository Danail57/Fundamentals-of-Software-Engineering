/*Да се състави алгоритъм и напише програма,
която въвежда от клавиатурата няколко думи,
написани на един ред и разделени с един
интервал. След това програмата намира и
извежда най-дългата дума от въведените.
Ако има няколко най-дълги думи, извежда
ги всичките.
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Helper function to check if the string contains any digits (0-9)
bool has_digits(string str) 
{
	for (char c : str) 
	{
		if (isdigit(c)) 
		{
			return true; // Found a digit
		}
	}
	return false; // No digits found
}



// Helper function to validate and get a non-empty line of text without numbers
string get_valid_input(string prompt)
{
	string line;
	while (true)
	{
		cout << prompt;
		getline(cin, line);

		// Check if the input contains at least one word
		stringstream check_stream(line);
		string temp_word;

		if (check_stream >> temp_word)
		{
			// Check if the input line contains any numbers/digits
			if (!has_digits(line))
			{
				return line; // Valid input (contains words and no numbers)
			}
			cout << "Invalid input! Words must NOT contain numbers and digits.\n\n";
		}
		else
		{
			cout << "Invalid input! Please enter at least one word.\n\n";
		}
	}
}


int main()
{
	string line = get_valid_input("Write words separated by space: ");

	stringstream words(line); // Stream for separating words by spaces
	string text[1000];
	string word;
	int count = 0;
	size_t max_len = 0;

	// Read each word and track the maximum word length
	while (words >> word)
	{
		text[count] = word;
		if (word.length() > max_len)
		{
			max_len = word.length();
		}
		count++;
	}

	// Output the maximum length and all words matching that length
	cout << "\nLength of the longest word(s): " << max_len << " characters" << endl;
	cout << "The longest word(s):" << endl;

	for (int i = 0; i < count; i++)
	{
		if (text[i].length() == max_len)
		{
			cout << text[i] << endl;
		}
	}
	return 0;
}
