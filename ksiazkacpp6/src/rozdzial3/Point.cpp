/*
 * Point.cpp
 *
 *  Created on: 1 lis 2013
 *      Author: Piotr
 */

#include "Point.h"

namespace piot {

Point::Point()
: x{0}
, y{0} {
}

Point::~Point() {
}

piot::Point::Point(double a)
: x{a}
, y{a} {
}

piot::Point::Point(double x, double y)
: x{x}
, y{y} {
}

} /* namespace piot */
