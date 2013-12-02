/*
 * rozdzial05.h
 *
 *  Created on: 2 gru 2013
 *      Author: piot
 */
#ifndef ROZDZIAL05_H_
#define ROZDZIAL05_H_

#include <iostream>
#include <thread>
#include <vector>
#include <functional>
#include <type_traits>

namespace r05 {

void f(const std::vector<double>& v);
struct F {
	std::vector<double>& v;
	F(std::vector<double>& vv) :v(vv) {};
	void operator()();
};

void f2(const std::vector<double>& v, double* res);
class F2 {
public:
	F2(const std::vector<double>& vv, double* p) :v{vv}, res{p} { ;}
	void operator()() { ;};
private:
	const std::vector<double>& v;
	double* res;
};

void test1() {
	std::vector<double> some_vec {1,2,3,4,5,6,7,8,9};
	std::vector<double> vec2 {10,11,12,13,14};
	double res1;
	double res2;

//	std::thread t1 {f2, some_vec, &res1};
	std::thread t2 {F2{vec2, &res2}};

	//t1.join();
	t2.join();

	std::cout << res1 << ' ' << res2 << '\n';
}



}
#endif /* ROZDZIAL05_H_ */
