
/*В магазин за хранителни продукти, за всеки
продукт се въвеждат:  код,  име,  мярка,
единична цена, количество.
Да се състави алгоритъм и напише програма,
която въвежда в масив данни за определен брой
продукти и изчислява наличната стока
в парично изражение.
*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Shop {
	int code; // product code
	string name; // name of the product
	string unit; // kg, ml...
	double price;
	double quantity;
};

// Function to clear errors and 
// residual input in the buffer
void clearBuffer()
{
	cin.clear(); // Resets cin error flags
	cin.ignore(1000, '\n'); // Skips up to 1000 characters 
	// or until Enter is pressed
}


// function for safely inputting an integer
int input_int(string message)
{
	int value;
	while (true) 
	{
		cout << message;
		if (cin >> value && value > 0) 
		{
			return value;
		}
		cout << "Write a positive integer.\n";
		clearBuffer();
	}
}



// function for safely inputting a decimal number
double input_double(string message) 
{
	double value;
	while (true) 
	{
		cout << message;
		if (cin >> value && value >= 0) 
		{
			return value;
		}
		cout << "Write a positive number (>= 0).\n";
		clearBuffer();
	}
}


int main()
{
	int n = input_int("Write the product count: ");

	vector <Shop> products(n); // creating an array for the products
	double total_sum = 0.0;

	for (int i = 0; i < n; i++)
	{
		cout << "Product " << i + 1 << endl;

		products[i].code = input_int("Code: ");
		

		// Remove the newline character '\n' after the 
		// code so that getline works correctly
		clearBuffer();

		cout << "Product name: " << endl;
		getline(cin, products[i].name);

		cout << "Unit (kg, litres, etc): " << endl;
		cin >> products[i].unit;

		products[i].price = input_double("Price per one: ");

		products[i].quantity = input_double("Quantity: ");
		total_sum += products[i].price * products[i].quantity;
	}
	cout << "Total sum: " << fixed << setprecision(2) << total_sum << " €" << endl;
}
