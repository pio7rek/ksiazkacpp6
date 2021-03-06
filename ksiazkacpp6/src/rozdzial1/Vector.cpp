/*
 * Vector.cpp
 *
 *  Created on: 28 pa� 2013
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

Vector::Vector(Vector&& a)
: elem{a.elem}
, sz{a.sz} {
	a.elem = nullptr;
	a.sz = 0;
}

double& Vector::operator[](int i) const {
	return elem[i];
}

int Vector::size() const {
	return sz;
}

Vector::Vector(const Vector& a)
: elem{new double[sz]}
, sz{a.sz} {
	for (int i=0; i!=sz; ++i) {
		elem[i] = a.elem[i];
	}
}

Vector& Vector::operator=(const Vector& a) {
	double* p = new double[a.sz];
	for (int i=0; i!=a.sz; ++i) {
		p[i] = a.elem[i];
	}
		delete[] elem;
		elem = p;
		sz = a.sz;
		return *this;
}

/*void piot::Vector::push_back(double d) {
}*/

} /* namespace piot */


