/*
 * Container.h
 *
 *  Created on: 28 paü 2013
 *      Author: piot
 */

#ifndef CONTAINER_H_
#define CONTAINER_H_

namespace piot {

class Container {
public:
	virtual double& operator[](int) = 0;
	virtual int size() const = 0;
	virtual ~Container() {};
};

} /* namespace piot */

#endif /* CONTAINER_H_ */
