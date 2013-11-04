/*
 * Circle.cpp
 *
 *  Created on: 1 lis 2013
 *      Author: Piotr
 */

#include "Circle.h"

namespace piot {

Circle::Circle(Point p, int rr)
: x{p}
, r{rr} {
}

Point Circle::center() const {
	return x;
}

void Circle::move(Point to) {
	x=to;
}

void Circle::draw() const {
}

Circle::~Circle() {

}

void Circle::rotate(int ang) {
}


} /* namespace piot */
