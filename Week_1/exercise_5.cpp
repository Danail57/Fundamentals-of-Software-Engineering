
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

int main()
{
	string line;
	cout << "Write words separated by space: ";
	getline(cin, line);

	stringstream words(line); // for separating by spaces
	string text[1000];
	string word;
	int count = 0;
	int max_len = 0;

	while (words >> word)
	{
		text[count] = word;
		if (word.length() > max_len)
		{
			max_len = word.length();
		}
		count++;
	}
	cout << "\nThe longest words: " << max_len << endl;
	for (int i = 0; i < count; i++)
	{
		if (text[i].length() == max_len)
		{
			cout << text[i] << endl;
		}
	}
} 
