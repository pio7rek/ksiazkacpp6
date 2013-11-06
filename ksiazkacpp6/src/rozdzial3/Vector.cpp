/*
 * Vector.cpp
 *
 *  Created on: 6 lis 2013
 *      Author: piot
 */

#include "Vector.h"
#include <stdexcept>

namespace piot3 {

template<typename T>
Vector<T>::Vector(int s) {
	if (s<0) throw std::length_error{"Vector<T>::Vector"};
	elem = new T[s];
	sz = s;
}

template<typename T>
const T& Vector<T>::operator[](int i) const {
	if (i<0 || size()<=i) {
		throw std::out_of_range{"Vector<T>::operator[]"};
	}
	return elem[i];
}

template<typename T>
T& Vector<T>::operator [](int i) {
	if (i<0 || size()<=i) {
		throw std::out_of_range{"Vector<T>::operator[]"};
	}
	return elem[i];
}

} /* namespace piot3 */
