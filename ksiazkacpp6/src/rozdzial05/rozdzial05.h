/*
 * rozdzial05.h
 *
 *  Created on: 2 gru 2013
 *      Author: piot
 */
#ifndef ROZDZIAL05_H_
#define ROZDZIAL05_H_

#include <thread>
#include <vector>
#include <functional>
#include <type_traits>
#include <mutex>
#include <chrono>
#include <forward_list>
#include <algorithm>
#include <iterator>
#include <typeinfo>
#include <type_traits>
#include <iostream>
#include <regex>
#include <numeric>
#include <list>
#include <random>

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

	//std::cout << res1 << ' ' << res2 << '\n';
}

std::mutex m;
int sh;
void f3() {
	std::unique_lock<std::mutex> lck {m};
	sh +=7;
}
void f4() {
	using namespace std::chrono;
	auto t0 = high_resolution_clock::now();
	r05::test1();
	auto t1 = high_resolution_clock::now();
	std::cout << duration_cast<milliseconds>(t1-t0).count() << "msec\n";
}

/*template<typename Ran>
void sort_helper(Ran beg, Ran end, std::random_access_iterator_tag) {
	std::sort(beg, end);
}

template<typename For>
void sort_helper(For beg, For end, std::forward_iterator_tag) {
	std::vector<decltype(*beg)> v {beg, end};
	std::sort(v.begin(), v.end());
	copy(v.begin(), v.end(), beg);
}

template<typename C>
using Iterator_type = typename C::iterator;

template<typename Iter>
using Iterator_category = typename std::iterator_traits<Iter>::iterator_category;

template<typename C>
void sort(C& c) {
	using Iter = std::Iterator_type<C>;
	sort_helper(c.begin(), c.end(), std::Iterator_category<Iter>{});
}

void test5421(std::vector<std::string>& v, std::forward_list<int>& lst) {
	std::sort(v);
	std::sort(lst);
}*/

template<typename T>
constexpr bool Is_arithmetic() {
	return std::is_arithmetic<T>::value;
}

template<typename Scalar>
class complex {
	Scalar re, im;
public:
	static_assert(Is_arithmetic<Scalar>(), "Sorry, I only support complex of "
			"arithmetic types");
};

void f5422() {
	bool b1 = Is_arithmetic<int>();
	bool b2 = Is_arithmetic<std::string>();

	std::cout << "b1: " << b1 << " b2: " << b2 << std::endl;
}

complex<int> i;
//complex<std::string> s;
void test55() {
	std::regex pat (R"(\w{2}\s*\d{5}(-\d{4})?)");
	int lineno = 0;
	for (std::string line; getline(std::cin, line);) {
		++lineno;
		std::smatch matches;
		if (std::regex_search(line, matches,pat)) {
			std::cout << lineno << ": " << matches[0] << '\n';
		}
	}
}

void f561() {
	std::list<double>lst {1, 2, 3, 4, 5, 9999.99999};
	auto s = std::accumulate(lst.begin(), lst.end(), 0.0);
	std::cout << s << '\n';
}

class Rand_int {
public:
	Rand_int(int low, int high) :dist{low, high} { }
	int operator()() { return dist(re); }
private:
	std::default_random_engine re;
	std::uniform_int_distribution<> dist;
};

void f563() {
	Rand_int rnd {0,9};
	std::vector<int> histogram(10);
	for (unsigned int i=0; i!=1000; ++i) {
		++histogram[rnd()];
	}
	for (unsigned int i=0; i!=histogram.size(); ++i) {
		std::cout << i << '\t';
		for (int j=0; j!=histogram[i]; ++j) {
			std::cout << '*';
		}
		std::cout << std::endl;
	}
}


}
#endif /* ROZDZIAL05_H_ */
