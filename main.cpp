#include <iostream>
#include "Array.h"
#include "complex.h"
#include <array>
using std::cout;
using std::endl;
using std::string;

//************************************************************
//Визначити і реалізувати узагальнений клас масивів довільного 
//розміру і довільного типу Array<n,T>, передбачивши вкладений
//клас обробки помилок при виході індексів за межі масиву.
//Виконати тестування класу, зокрема обробку виняткових 
//ситуацій для масивів різних розмірів і типів.
//Developed by Ruslan Zymovets (IPZ, group 1)
//on March 27
//Version 1.0
//************************************************************


int main(void)
{
	array<double, 3> es;
	{
		cout << "#1 Plain Old Data array--------------------------------" << endl;
		cout << "Creating array :" << endl;
		Array<5, double> a;
		//Array<0, double> c;
		//Array<10, double&> f;
		cout << "Notice that we cannot create zero-sized arrays or arrays of references." << endl;
		cout << "Created array : " << endl << a << endl;
		cout << "Size = " << a.size() << endl;
		a[0] = a[1] = a[2] = 1;
		cout << "Filling the array (except for the last two elements) :" << endl << a << endl;
		try
		{
			cout << "When index exceeds the size of the array :" << endl;
			a[10];
		}
		catch (const Array<5, double>::BadArray& ba)
		{
			ba.print_reason();
		}
		cout << "Destructor :" << endl;
	}
	cout << endl;
	{
		cout << "#2 Complex Array----------------------------------------" << endl;
		cout << "Creating array :" << endl;
		Array<3, Complex> a;
		cout << "Created array : " << endl << a << endl;
		cout << "Size = " << a.size() << endl;
		a[0] = 1;
		a[1] = Complex(2, 3);
		a[2] = Complex(4, 5);
		cout << "Filling the array :" << endl << a << endl;
		cout << "Destructor :" << endl;
	}
	cout << endl;
	{
		cout << "#3 Array of pointers--------------------------------------" << endl;
		cout << "Creating array :" << endl;
		Array<3, int*> a;
		
		cout << "Created array : " << endl << a << endl ;
		cout << "Size = " << a.size() << endl ;
		a[0] = new int(1);
		a[1] = new int(3);
		a[2] = new int(5);
		cout << "Filling the array :" << endl << a << endl;
		cout << "What is under pointers : " << '[' << *a[0] << ", " << *a[1] << ", " << *a[2] << ']' << endl;
		cout << "Memory freeing is user's responsibility : " << endl;
		delete a[0]; a[0] = nullptr;
		delete a[1]; a[1] = nullptr;
		delete a[2]; a[2] = nullptr;

		cout << "delete a[0]; a[0] = nullptr;" << endl;
		cout << "delete a[1]; a[1] = nullptr;" << endl;
		cout << "delete a[2]; a[2] = nullptr;" << endl;

		cout << "Destructor :" << endl;
	}

	return 0;
}