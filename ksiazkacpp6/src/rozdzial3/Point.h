/*
 * Point.h
 *
 *  Created on: 1 lis 2013
 *      Author: Piotr
 */

#ifndef POINT_H_
#define POINT_H_

namespace piot {

class Point {
public:
	Point();
	Point(double);
	Point(double, double);
	virtual ~Point();
private:
	double x, y;
};

} /* namespace piot */

#endif /* POINT_H_ */
