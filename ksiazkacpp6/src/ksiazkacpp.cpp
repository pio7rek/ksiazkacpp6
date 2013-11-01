/*
 * ksiazkacpp.cpp
 *
 *  Created on: 28 paü 2013
 *      Author: piot
 */

#include <iostream>
#include <istream>
#include "rozdzial1/Vector.h"
#include "rozdzial3/Container.h"
#include "rozdzial3/Vectorcontainer.h"
#include "rozdzial3/Shape.h"
#include <vector>

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

void rotate_all(vector<piot::Shape*>& vec, int angle) {
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

int main() {
	std::cout << "hello!" << std::endl;

	std::cout << "git test ala ma kota" << std::endl;

	g();

//	v_initializer_test();

	return 0;
}



