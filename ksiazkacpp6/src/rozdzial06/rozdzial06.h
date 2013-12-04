/*
 * rozdzial06.h
 *
 *  Created on: 4 gru 2013
 *      Author: piot
 */

#ifndef ROZDZIAL06_H_
#define ROZDZIAL06_H_

#include <iostream>

namespace r06{


void f_bool(int* p) {
	bool b = p;
	bool b2 {p!=nullptr};
	if (p) {
		;
	}
}

void intval() {
	for (char c; std::cin >> c;) {
		std::cout << "wartosc '" << c << "' to " << int{c} << '\n';
	}
}






}
#endif /* ROZDZIAL06_H_ */
