#include <iostream>
#include "Array.h"
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

/*
* Questions:
* 1). Why in the book private operator== is present? (though not realised just like copying ctor & assignment)
* 2). Is it any different if we use "= delete" notation for copying ctor & assignment instead of just declaring them
* in the private part?
* 3). There's no need of adding "explicit" specifier to the ctor, is there?
* 4). How to pass BadArray as a parameter of the function regarding it is a nested class of a template class?
* 5). Is there sense in template<CONST size_t Size,...>?
* 6). Should an iterator be implemented?
* 7). Why the default values in the array are like that : -842150451 ...
* 8). Why static member initialization doesn't work? (this project)
*/

int main(void)
{
	Array<10, string> a;


	for (size_t i = 0; i < a.size() - 2; ++i)
	{
		a[i] = i;
	}
	
	cout << a << endl;

	try
	{
		a[-1];
	}
	catch (const Array<10, string>::BadArray& ba)
	{
		ba.print_reason();
	}
	return 0;
}