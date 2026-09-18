
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
	int code;
	string name;
	string unit; // kg, ml...
	double price;
	double quantity;
};

int main()
{
	int n;
	cout << "Write the product count: ";
	cin >> n;

	vector <Shop> products(n);
	double total_sum = 0;

	for (int i = 0; i < n; i++)
	{
		cout << "Product " << i + 1 << endl;
		cout << "Code: " << endl;
		cin >> products[i].code;

		cout << "Product name: " << endl;
		getline(cin, products[i].name);

		cout << "Unit (kg, litres, etc): " << endl;
		cin >> products[i].unit;

		cout << "Price: " << endl;
		cin >> products[i].price;

		cout << "Quantity: " << endl;
		cin >> products[i].quantity;
		total_sum += products[i].price * products[i].quantity;
	}
	cout << "Total sum: " << fixed << setprecision(2) << total_sum << " €" << endl;
}
