/*
 * Vector.cpp
 *
 *  Created on: 28 paü 2013
 *      Author: piot
 */

#include "Vector.h"
#include <stdexcept>

namespace piot {

Vector::Vector(int s) {
	if (s<0) {
		throw std::length_error{"Vector::Vector"};
	}
		elem = new double[s];
		sz = s;
		for (int i=0; i!=s; ++i) {
		elem[i] = 0;
	}
}

Vector::Vector(std::initializer_list<double> lst) {
	elem = new double[lst.size()];
	sz = lst.size();
	std::copy(lst.begin(), lst.end(), elem);
}

Vector::~Vector() {
	delete[] elem;
}

double& Vector::operator[](int i) {
	return elem[i];
}

int Vector::size() const {
	return sz;
}

/*void piot::Vector::push_back(double d) {
}*/

} /* namespace piot */


