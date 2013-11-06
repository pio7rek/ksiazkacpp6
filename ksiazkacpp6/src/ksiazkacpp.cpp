/*
 * ksiazkacpp.cpp
 *
 *  Created on: 28 paü 2013
 *      Author: piot
 */

#include <iostream>
#include <istream>
#include "rozdzial3/Vector.h"
#include "rozdzial1/Vector.h"
#include "rozdzial3/Container.h"
#include "rozdzial3/Vectorcontainer.h"
#include "rozdzial3/Shape.h"
#include <vector>



/*void write2(const piot3::Vector<std::string> vs) {
	for (auto& s : vs) {
		std::cout << s << std::endl;
	}
}*/

void write(const piot3::Vector<std::string>& vs) {
	for (int i = 0; i!=vs.size(); ++i) {
		std::cout << vs.operator [](i) << std::endl;
	}
}

void bad_copy() {
	piot::Vector v1(5), v2(5);
	v1 = v2;
}

void use(piot::Container& c) {
	const int sz = c.size();
	for ( int i=0; i!=sz; ++i) {
		std::cout << c[i] << std::endl;
	}
}

void g() {
	piot::Vector_container vc{10, 9, 8, 7, 6, 5, 4, 3, 2, 1 ,0};
	use(vc);
}

void vector_test() {
	piot::Vector v(10);
	for (int i=0; i!=v.size(); ++i) {
		v[i] = i*2;
		std::cout << v[i] << ' ';
	}
	std::cout << std::endl;
}

void v_initializer_test() {
	piot::Vector v{2, 4, 6, 8, 10};
	for (int i=0; i!=v.size(); ++i) {
		v[i] = i*2;
		std::cout << v[i] << ' ';
	}
	std::cout << std::endl;

}

void rotate_all(std::vector<piot::Shape*>& vec, int angle) {
	for (auto p : vec) {
		p->rotate(angle);
	}
}


/*piot::Vector read(istream& is) {
	piot::Vector v;
	for (double d; is>>d; ) {
		v.push_back(d);
	}
	return v;
}*/

piot::Vector operator+(const piot::Vector& a, const piot::Vector& b) {
	/*if (a.size() != b.size()) {
		throw Vector_size_mismatch{};
	}*/
	piot::Vector res(a.size());
	for (int i=0; i!=a.size(); ++i) {
		res[i] = a[i] + b[i];
	}
	return res;
}

int main() {
	std::cout << "hello!" << std::endl;

	//piot3::Vector<std::string> v(5);
/*	v[0]="ala";
	v[1]="ma";
	v[2]="kota";
	v[3]="ktorego";
	v[4]="lubi";*/
	//write(v);

	//bad_copy();

	return 0;
}



