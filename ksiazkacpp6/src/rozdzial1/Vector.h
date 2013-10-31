/*
 * Vector.h
 *
 *  Created on: 28 paü 2013
 *      Author: piot
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include <initializer_list>

namespace piot {

class Vector {
public:
	Vector(int s);
	Vector(std::initializer_list<double>);
	virtual ~Vector();

	double& operator[](int);
	int size() const;
/*	void push_back(double);*/

private:
	double* elem; //tablica elementow
	int sz; //rozmiar wektora
};

} /* namespace piot */

#endif /* VECTOR_H_ */
