/*
 * rozdzial06.h
 *
 *  Created on: 4 gru 2013
 *      Author: piot
 */

#ifndef ROZDZIAL06_H_
#define ROZDZIAL06_H_

#include <iostream>
#include <limits>

namespace r06{


void f_bool(int* p) {
	//bool b = p;
	//bool b2 {p!=nullptr};
	if (p) {
		;
	}
}

void intval() {
	for (char c; std::cin >> c;) {
		std::cout << "wartosc '" << c << "' to " << int{c} << '\n';
	}
}

/*void f_charconv(char c, signed char sc, unsigned char uc) {
	char* pc = &uc;
	signed char* psc = pc;
	unsigned char* puc = pc;
	psc = puc;
}*/

void g_char_conv(char c, signed char sc, unsigned char uc) {
	c = 255;
	c = sc;
	c = uc;
	sc = uc;
	uc = sc;
	sc = c;
	uc = c;
}

//void x;
//void& r;
void f_void();
void* pv;

void f_limits() {
	std::cout << "rozmiar long " << sizeof(1L) << '\n';
	std::cout << "rozmair long long " << sizeof(1LL) << '\n';
	std::cout << "rozmiar float " << sizeof(1.F) << '\n';
	std::cout << "rozmair double " << sizeof(1.) << '\n';
	std::cout << "rozmiar long double " << sizeof(1.L) << '\n';
	std::cout << "najwiekszy float == " << std::numeric_limits<float>::max() << '\n';
	std::cout << "najwiekszy double == " << std::numeric_limits<double>::max() << '\n';
	std::cout << "najwiekszy long double == " <<
			std::numeric_limits<long double>::max() << '\n';
	std::cout << "char jest ze znakieem == " << std::numeric_limits<char>::is_signed << '\n';
}

void f_aligment() {
	struct Empty {};

	struct Foo {
		 int f2;
		 float f1;
		 char c;
	};
	std::cout << "alignment of empty class: " << alignof(Empty) << '\n'
			  << "alignment of pointer : "    << alignof(int*)  << '\n'
			  << "alignment of int : "    << alignof(int)  << '\n'
			  << "alignment of float : "    << alignof(float)  << '\n'
			  << "alignment of long double : "    << alignof(1.L)  << '\n'
			  << "alignment of char : "       << alignof(char)  << '\n'
			  << "alignment of char : "    << alignof(char)  << '\n'
			  << "alignment of short : "    << alignof(short)  << '\n'
			  << "alignment of Foo : "        << alignof(Foo)   << '\n' ;

}

void f_init() {
	int a1 {5};
	int a2 = {5};
	int a3 = 5;
    int a4 (5);
}

void f_init_2(double val, int val2) {
	int x2 = val;
	char c2 {val2};
	int x3 {val};
	char c4 {24};
	char c5 {264};
	int x4 {2.0};
}

template<typename T>
class Matrix {
	T operator()(int i, int j) {
		T x;
		return x;
	}
	int rows() { return 4; }
	int cols() { return 4; }
};

template<class T, class U>
auto operator+(const Matrix<T>& a, const Matrix<U>& b) -> Matrix<decltype(T{}+U{})> {
	Matrix<decltype(T{}+U{})> res;
	for (int i=0; i!=a.rows(); ++i) {
		for (int j=0; j!=a.cols(); ++j) {
			res(i,j) += a(i,j) +b(i,j);
		}
	}
}

}
#endif /* ROZDZIAL06_H_ */
