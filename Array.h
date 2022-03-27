#pragma once
#include <ostream>
#include <string>
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
	~Array();
	inline Elem& operator[](const size_t index);
	inline const Elem& operator[](const size_t index) const;
	inline size_t size() const; 
private:
	static size_t freeId;
	const size_t _id;
	const size_t _size;
	Elem *const _allocator;
	//bool operator==(const Array&) const;
	Array(const Array&) = delete;
	Array& operator=(const Array&) = delete;
};

template<size_t Size, typename Elem>
class Array<Size, Elem>::BadArray
{
private:
	string _reason;
	size_t _index;
public:
	BadArray(const size_t index, const string& reason = "unknown") 
		: _reason(reason), _index(index) { return; }
	~BadArray() { return; }
	inline void print_reason() const { return; }
};

template<size_t Size, typename Elem>
inline Array<Size, Elem>::Array()
	: _id(++freeId), _size(Size), _allocator(new Elem[Size])
{
	return;
}

template<size_t Size, typename Elem>
inline Array<Size, Elem>::~Array()
{
	delete[] _allocator;
}

template<size_t Size, typename Elem>
inline Elem& Array<Size, Elem>::operator[](const size_t index)
{
	// // O: insert return statement here
}

template<size_t Size, typename Elem>
inline const Elem& Array<Size, Elem>::operator[](const size_t index) const
{
	// // O: insert return statement here
}

template<size_t Size, typename Elem>
inline size_t Array<Size, Elem>::size() const
{
	return _size;
}
