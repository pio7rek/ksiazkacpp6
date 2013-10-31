/*
 * Vectorcontainer.cpp
 *
 *  Created on: 30 paü 2013
 *      Author: piot
 */

#include "Vectorcontainer.h"

namespace piot {

Vector_container::Vector_container(int s) :v(s) {
	}
Vector_container::~Vector_container() {
	}
double& Vector_container::operator[](int i) {
	return v[i];
}
int Vector_container::size() const {
	return v.size();
}

} /* namespace piot */
