// Name : Kiran Tulsukar NuID : 001057882

#include <iostream>
using namespace std;

//passing names,grades and total number of students
void insertion_sort(string name[], int grd[], int n)
{
	int temp1;
	string temp2;
	for (int i = 1; i < n; i++)
	{
		int j = i;
		while (j > 0 and grd[j - 1] < grd[j]) // loop for comparing the grades in the array and passing if the condition is satisfied
		{
			temp1 = grd[j - 1]; //swapping the grades
			grd[j - 1] = grd[j];
			grd[j] = temp1;

			temp2 = name[j - 1]; // swapping the names simultaneously
			name[j - 1] = name[j];
			name[j] = temp2;
			j = j - 1;
		}
	}
}

int main() {

	int nu_stud;
	//asking the instructer for total number of students
	cout << "Enter total number of students: "<<'\n';
	cin >> nu_stud;

	//Defining Dynamic Arrays
	int* stud_grade = new int[nu_stud];
	string* stud_names = new string[nu_stud];

	//Asking the instructer to enter name and respecctive scores
	for (int i = 0; i < nu_stud; i++)
	{
		cout << "Enter Student " << i + 1 << " Last name: ";
		cin >> stud_names[i];
		cout << "Enter Student " << i + 1 << " score(0-100): ";
		cin >> stud_grade[i];

	}

    //Printing the name and scores entered by the instructer
	cout << "Entered Data: "<<'\n';
	cout << "Student Last Name " << "--" << " Student Score "<<'\n';
	for (int i = 0; i < nu_stud; i++)
	{
		cout << stud_names[i] << "--" << stud_grade[i]<<'\n';
	}

	//calling insertion sort algorithm
	insertion_sort(stud_names, stud_grade, nu_stud);

	cout << "Arranged Data in Desscending Order: " << '\n';
	cout << "Student Name " << "--" << " Student Score " << '\n';
	for (int i = 0; i < nu_stud; i++)
	{
		cout << stud_names[i] << "--" << stud_grade[i] << '\n';
	}

	delete[] stud_grade;
	delete[] stud_names;

	return 0;
}