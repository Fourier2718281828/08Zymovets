#include "complex.h"

Complex::Complex(double re, double im) : _re(re), _im(im)
{
#ifndef NDEBUG
	cout << "--Complex number " << *this << " created" << endl;
#endif
};

ostream& operator<<(ostream& os, const  Complex& a)
{
	os << "(" << a.re() << '+' << a.im() << "i)";
	return os;
}

Complex& Complex::operator= (const Complex& a)&
{
	re() = a.re();
	im() = a.im();
	return *this;
}

Complex& Complex::operator+=(const Complex& b)&
{
	re() += b.re();
	im() += b.im();
	return *this;
}

Complex operator+(Complex a, const Complex& b)
{
	return a += b;
}

bool operator== (const Complex& a, const Complex& b)
{
	return a.re() == b.re() && a.im() == b.im();
}

bool operator!= (const Complex& a, const Complex& b)
{
	return !(a == b);
}