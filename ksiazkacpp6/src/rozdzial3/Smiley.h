/*
 * Smiley.h
 *
 *  Created on: 4 lis 2013
 *      Author: piot
 */

#ifndef SMILEY_H_
#define SMILEY_H_

#include "Circle.h"
#include "Point.h"
#include <vector>

namespace piot {

class Smiley: public piot::Circle {
public:
	Smiley(Point, int);
	~Smiley();
	void move(Point);
	void draw() const;
	void rotate(int);\

	void add_eye(Shape*);
	void set_mouth(Shape*);
	virtual void wink(int);
private:
	std::vector<Shape*> eyes;
	Shape* mouth;
};

} /* namespace piot */

#endif /* SMILEY_H_ */
