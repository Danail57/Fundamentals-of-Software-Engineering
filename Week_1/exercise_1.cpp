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
	int a, b, c;
	cout << "Write three numbers: ";
	cin >> a;
	cin >> b;
	cin >> c;

	int min_value = min({ a, b, c });
	int max_value = max({ a, b, c });
	int mid_value = (a + b + c) - min_value - max_value;

	int result = min_value - (mid_value * max_value);
	cout << "Minimal result: " << result << endl;
}
