
/*Зададен е едномерен масив от цели числа
А0, А1,...,Аn-1. Да се състави алгоритъм и 
напише програма, която създава нов масив а0, 
а1,...,аn-1, като стойността на аi е равна на
средно-аритметичното на нечетните цифри на Аi. 
Предполага се, че във всяко число има поне 
една нечетна цифра.*/

#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Write the array size: ";
	cin >> n;

	if (n <= 0) { return 0; }
	int A[1000];
	for (int i = 0; i < n; i++)
	{
		cout << "A[" << i + 1 << "] = ";
		cin >> A[i];
	}

	double new_array[1000];
	for (int i = 0; i < n; i++)
	{
		int temp = abs(A[i]);
		int sum_odd = 0;
		int count_odd = 0;
		while (temp > 0)
		{
			int digit = temp % 10;
			if (digit % 2 != 0)
			{
				sum_odd += digit;
				count_odd++;
			}
			temp /= 10;
		}
		new_array[i] = (double)sum_odd / count_odd;
	}
	cout << "New array is: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i + 1 << "] = " << new_array[i] << endl;
	}
}

