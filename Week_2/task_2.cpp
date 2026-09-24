#include <iostream>
using namespace std;

int main()
{
	int n;
	
	// checking for correct setting of the number of array elements
	do {
		cout << "Count of elements (between 1 and 20): ";
		cin >> n;
		if (n <= 0 || n > 20)
			cout << "Invalid input!\n";
	} while (n <= 0 || n > 20);

	int numbers[21]; // array for the numbers
	int digit_sums[21]; // array for the digit sum

	cout << "Write " << n << " numbers:\n";
	for (int i = 1; i <= n; i++)
	{
		cout << "Number["<< i <<"] = ";
		cin >> numbers[i];

		digit_sums[i] = 0;
		int temp_number = numbers[i];

		while (temp_number > 0)
		{
			digit_sums[i] += (temp_number % 10);
			temp_number /= 10;
		}
	}
	// sorting the arrays by sum and value
	int has_swapped;
	do {
		has_swapped = 0;
		for (int i = 1; i < n; i++)
		{
			if ((digit_sums[i] > digit_sums[i + 1]) ||
				((digit_sums[i] == digit_sums[i + 1]) &&
			(numbers[i] > numbers[i + 1])))
			{
				// swap digit sums
				int temp_sum = digit_sums[i];
				digit_sums[i] = digit_sums[i + 1];
				digit_sums[i + 1] = temp_sum;

				// swap numbers
				int temp_number  = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = temp_number;

				has_swapped = 1;
			}
		}
	} while (has_swapped);

	cout << "\nResult\n";
	cout << "Sorted array: ";
	for (int i = 1; i <= n; i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;
	return 0;
}
