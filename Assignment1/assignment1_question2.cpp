// Name : Kiran Tulsukar NuID : 001057882

#include <iostream>
using namespace std;


int F1(int n)
{
	if (n == 0) return 1;
	return F1(n - 1) + F1(n - 1);
}
int F2(int n)
{
	if (n == 0) return 1;
	if (n % 2 == 0) {
		int result = F2(n / 2);
		return result * result;
	}
	else
		return 2 * F2(n - 1);
}

int main()
{
	cout << "Output of Function F1 for n = 1 to 10" << '\n';
	for (int i = 1; i < 11; i++)
	{
		cout << F1(i) << '\n'; // to print output of F1
		
	}

	cout << "Output of Function F2 for n = 1 to 10" << '\n';
	for (int i = 1; i < 11; i++)
	{
		cout << F2(i) << '\n'; // to print output of F2

	}
	
	return 1;
}