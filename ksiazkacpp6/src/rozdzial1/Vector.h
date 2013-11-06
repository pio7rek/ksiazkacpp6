/*
 * Vector.h
 *
 *  Created on: 28 paü 2013
 *      Author: piot
 */

#ifndef VECTOR_PIOT_H_
#define VECTOR_PIOT_H_

#include <initializer_list>

namespace piot {

class Vector {
public:
	Vector(int s);
	Vector(std::initializer_list<double>);
	virtual ~Vector();

	Vector(const Vector& a);			//copy constructor
	Vector& operator=(const Vector& a);	//copy

	Vector(Vector&& a);					//move constructor
//	Vector& operator=(Vector&& a);		//move

	double& operator[](int) const;
	int size() const;
/*	void push_back(double);*/

private:
	double* elem; //tablica elementow
	int sz; //rozmiar wektora
};

} /* namespace piot */

#endif /* VECTOR_PIOT_H_ */
