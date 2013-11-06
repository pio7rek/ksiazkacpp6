/*
 * Vector.h
 *
 *  Created on: 6 lis 2013
 *      Author: piot
 */

#ifndef VECTOR_PIOT3_H_
#define VECTOR_PIOT3_H_

namespace piot3 {

template<typename T>
class Vector {
private:
	T* elem;
	int sz;
public:
	Vector(int);
	~Vector() {
		delete[] elem;
	}
	T& operator[](int);
	const T& operator[](int) const;
	int size() const {
		return sz;
	}
	T* begin() {
		return &elem[0];
	}
	T* end() {
		return begin() + size();
	}
};

} /* namespace piot3 */


#endif /* VECTOR_PIOT3_H_ */
