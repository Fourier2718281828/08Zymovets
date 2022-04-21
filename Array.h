#pragma once
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::ostream;
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

template<size_t Size, typename Elem>
class Array 
{
public:
	class BadArray;
	Array();
	Array(const Array&)			   = delete;
	Array& operator=(const Array&) = delete;
	~Array();
	inline		 size_t getId()					const;
	inline		 size_t size ()					const;
	inline const Elem& operator[](const size_t) const;
	inline		 Elem& operator[](const size_t);
private:
	static size_t freeId;
	const  size_t _id;
	Elem _allocator[Size];
};

//Partial specifications for Array to 
//avoid arrays of type : 
// Array<0, ...> and  Array<..., Elem&>, Array<..., const Elem>
//-------------------------------------------------------------
template<size_t Size, typename Elem>
class Array<Size, const Elem>;

template<size_t Size, typename Elem>
class Array<Size, Elem&>;

template<typename Elem>
class Array<0, Elem>;
//-------------------------------------------------------------

template<size_t Size, typename Elem>
class Array<Size, Elem>::BadArray
{
private:
	const string _reason;
	const size_t _index;
public:
	BadArray(const size_t index, const string& reason) 
		: _reason(reason), _index(index) { return; }
	~BadArray()							 { return; }
	inline void print_reason() const	 
	{
		cout << _reason << ':' << _index << endl;
	}
};

template<size_t Size, typename Elem>
size_t Array<Size, Elem>::freeId = 0;

template<size_t Size, typename Elem>
inline Array<Size, Elem>::Array()
	: _id(++freeId)
{
#ifndef NDEBUG
	cout << "--Array<" << size() << ", " << typeid(Elem).name() << "> (id" << getId() << ") created." << endl;
#endif // !NDEBUG

	return;
}

template<size_t Size, typename Elem>
inline Array<Size, Elem>::~Array() 
{
#ifndef NDEBUG
	cout << "--Array<" << size() << ", " << typeid(Elem).name() << "> (id" << getId() << ") deleted." << endl;
#endif // !NDEBUG
}

template<size_t Size, typename Elem>
inline Elem& Array<Size, Elem>::operator[](const size_t i)
{
	if (i >= size())
		throw BadArray(i, "Index out of acceptable bounds");
	return _allocator[i];
}

template<size_t Size, typename Elem>
inline const Elem& Array<Size, Elem>::operator[](const size_t i) const
{
	if (i >= size())
		throw BadArray(i, "Index out of acceptable bounds");
	return _allocator[i];
}

template<size_t Size, typename Elem>
inline size_t Array<Size, Elem>::getId() const
{
	return _id;
}

template<size_t Size, typename Elem>
inline size_t Array<Size, Elem>::size() const
{
	return Size;
}

template<size_t Size, typename Elem>
inline ostream& operator<<(ostream& o, const Array<Size,Elem>& arr)
{
	cout << '[';
	for (size_t i = 0; i < arr.size(); ++i)
	{
		cout << arr[i] << ((i == arr.size() - 1) ? "" : " ");
	}
	return o << ']';
}