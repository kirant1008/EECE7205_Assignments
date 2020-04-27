// Name : Kiran Tulsukar NuID : 001057882

#include <iostream>
using namespace std;


//writing function for swapByPointer
void swapP(int* n1, int* n2)
{
	int w;//making a dummy variable
	w = *n1;
	*n1 = *n2;
	*n2 = w;
}

// writing a function for swap by reference
void swapR(int& n1, int& n2)
{
	int w;//making a dummy variable
	w = n1;
	n1 = n2;
	n2 = w;
}
int main(void)
{
	int x; // x and y for swap by pointer
	int y;

	cout << "Swap by Pointer:" << '\n';
	cout << "Enter Value of X before swap" << "\n";
	cin >> x;
	cout << "Enter Value of Y before swap" << "\n";
	cin >> y;
	swapP(&x, &y);// calling the function and passing address of the two variables
	cout << "Value of X after swap is " << x << "\n" << "Value of Y after swap is " << y << "\n";

	int a = 2; // x and y for swap by reference
	int b = 3;

	cout << "Swap by Reference:" << '\n';
	cout << "Enter Value of A before swap" << "\n";
	cin >> a;
	cout << "Enter Value of B before swap is 3" << "\n";
	cin >> b;
	swapR(a, b); // calling the function and passing the values
	cout << "Value of A after swap is " << a << "\n" << "Value of B after swap is " << b << "\n";

	return 0;
}