/*
 * Circle.h
 *
 *  Created on: 1 lis 2013
 *      Author: Piotr
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Shape.h"
#include "Point.h"

namespace piot {

class Circle : public Shape {
public:
	Circle(Point, int);
	~Circle();
	Point center() const;
	void draw() const;
	void rotate(int);
private:
	Point x;
	int r;
};

} /* namespace piot */

#endif /* CIRCLE_H_ */
