/*
 * Shape.h
 *
 *  Created on: 1 lis 2013
 *      Author: Piotr
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include "Point.h"

namespace piot {

class Shape {
public:
	virtual piot::Point center() const = 0;
	virtual void move(piot::Point to) = 0;
	virtual void draw() const = 0;
	virtual void rotate(int angle) = 0;
	virtual ~Shape() {};
};

} /* namespace piot */

#endif /* SHAPE_H_ */
