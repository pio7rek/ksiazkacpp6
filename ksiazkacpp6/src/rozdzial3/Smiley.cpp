/*
 * Smiley.cpp
 *
 *  Created on: 4 lis 2013
 *      Author: piot
 */

#include "Smiley.h"

namespace piot {

Smiley::~Smiley() {
	delete mouth;
	for (auto p : eyes) {
		delete p;
	}
}

piot::Smiley::Smiley(Point p, int rr)
: Circle{p,rr}
, mouth(nullptr) {
}

void piot::Smiley::move(Point p) {
}

void piot::Smiley::draw() const {
	Circle::draw();
	for (auto p : eyes) {
		p->draw();
	}
	mouth->draw();
}

void piot::Smiley::rotate(int ang) {
}

void piot::Smiley::add_eye(Shape* s) {
	eyes.push_back(s);
}

void piot::Smiley::set_mouth(Shape* m) {
	mouth = m;
}

void piot::Smiley::wink(int i) {
}

} /* namespace piot */
