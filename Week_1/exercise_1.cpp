
/*Дадени са три цели неотрицателни числа a, b, c. 
Необходимо е да се подредят в някакъв ред и между тях да се 
поставят знаците + (за събиране), - (за изваждане) или 
* (за умножение), така че като се пресметне получения 
аритметичен израз неговата стойност да е възможно най-малка.
Между всяка двойка съседни числа може да има само един знак.
Всеки знак може да се използва само един път. Да се състави
алгоритъм и напише програма, която решава тази задача.*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a;
	int b;
	int c;

	// check for input data -> nonnegative numbers
	do {
		cout << "Write three numbers >= 0: ";
		cin >> a;
		cin >> b;
		cin >> c;

		if (a < 0 || b < 0 || c < 0)
		{
			cout << "Number must be >= 0!\n";
		}
	} while (a < 0 || b < 0 || c < 0);

	int min_value = min({ a, b, c });
    int max_value = max({ a, b, c });
    int mid_value = (a + b + c) - min_value - max_value;

	// for getting the minimal result we multiply the
	// two bigger nums and extract from the smallest num
	int result = min_value - (mid_value * max_value);

	cout << "\nResult\n";
    	cout << "Minimal result: " << result << endl;
	return 0; // good practice to have return 0 in the end of the main programme
}
