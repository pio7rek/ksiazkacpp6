/*
 * Vectorcontainer.h
 *
 *  Created on: 30 paü 2013
 *      Author: piot
 */

#ifndef VECTORCONTAINER_H_
#define VECTORCONTAINER_H_

#include "Container.h"
#include "../rozdzial1/Vector.h"

namespace piot {


class Vector_container : public Container {
	Vector v;
public:
	Vector_container(int);
	virtual ~Vector_container();
	double& operator[](int);
	int size() const;
};

} /* namespace piot */

#endif /* VECTORCONTAINER_H_ */
