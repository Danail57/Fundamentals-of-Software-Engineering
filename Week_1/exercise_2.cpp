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
	do {
        cout << "Write the array size (between 1 and 1000): ";
        cin >> n;
        if (n <= 0 || n > 1000) {
            cout << "Error! Size must be between 1 and 1000. Try again.\n";
        }
    } while (n <= 0 || n > 1000);

	if (n <= 0) { return 0; } // if there are not any elements the program executes with no errors (edge-case)
	
	int A[1000];
	for (int i = 0; i < n; i++)
    {
        bool has_odd_digit;
        do {
            has_odd_digit = false;
            cout << "A[" << i + 1 << "] = ";
            cin >> A[i];

   
			// checking if the written data has at least one odd digit
            int temp_check = abs(A[i]);
            
            // Специален случай за нулата (тя няма нечетни цифри)
			// special case for 0 - has odd digits
            if (temp_check == 0) {
                has_odd_digit = false;
            } else {
                while (temp_check > 0) {
                    if ((temp_check % 10) % 2 != 0) {
                        has_odd_digit = true;
                        break;
                    }
                    temp_check /= 10;
                }
            }

            if (!has_odd_digit) {
                cout << "Error! The number must contain at least one odd digit. Try again.\n";
            }
        } while (!has_odd_digit);
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
