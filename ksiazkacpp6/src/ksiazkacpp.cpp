/*
 * ksiazkacpp.cpp
 *
 *  Created on: 28 pa� 2013
 *      Author: piot
 */

#include <iostream>
#include <istream>
#include <ostream>
#include "rozdzial3/Vector.h"
#include "rozdzial1/Vector.h"
#include "rozdzial3/Container.h"
#include "rozdzial3/Vectorcontainer.h"
#include "rozdzial3/Shape.h"
#include "rozdzial05/rozdzial05.h"
#include "rozdzial06/rozdzial06.h"
#include <vector>
#include <list>
#include <memory>
#include <string>
#include <algorithm>
#include <iterator>
#include <utility>
#include <map>

void r4m3() {
	std::string imie = "Polomski Piotr";

	std::string s = imie.substr(9, 5);
	imie.replace(0, 8, "polomski");
	imie[0] = std::toupper(imie[0]);
}

void r4respond(const std::string& answer) {
	if (answer == "No") { }
	else if (answer == "Yes") { }
}

template<typename T>
class Less_than {
	const T val;
public:
	Less_than(const T& v) : val(v) { }
	bool operator()(const T& x) const { return x<val; }
};

template<typename C, typename P>
int count(const C& c, P pred) {
	int cnt = 0;
	for (const auto& x : c) {
		if (pred(x)) {
			++cnt;
		}
	}
	return cnt;
}

void fcnt(const std::vector<int>& vec, const std::list<std::string>& lst, int x,
		const std::string& s) {
	std::cout << "liczba wartosci mniejszych od " << x
			<< ": " << count(vec, Less_than<int>{x})
			<< std::endl;
	std::cout << "liczba wartosci mnijszych od " << s
			<< ": " << count(lst, Less_than<std::string>{s})
			<< std::endl;
}

void fct(int n, const std::string& s) {
	Less_than<int> lti{42};
	Less_than<std::string> lts{"Backus"};
	bool b1 = lti(n);
	bool b2 = lts(s);

	std::cout << n << " jest mniejsze od 42 " << b1 << std::endl;
	std::cout << s << " jest mniejsze od \"Backus\" " << b2 << std::endl;

}

template<typename Container, typename Value>
Value suma(const Container& c, Value v) {
	for (auto x : c) {
		v+=c;
	}
	return v;
}


//dla kazdego obiektu wskazanego przez wska�niki z pojemnika C wykonaj operacje Oper (Oper to funktor)
template<class C, class Oper>
void for_all(C& c, Oper op) { //zak�adamy �e C jest pojemnikiem wska�nik�w
	for(auto& x : c) {
		op(*x); //u�ywa op() na referencji wskazywanych obiekt�w z pojemnika C
	}
}

template<typename T>
void gg(T t) {
	std::cout << t << ' ';
}

void ff() { }

template<typename T, typename... Tail>
void ff(T head, Tail... tail) {
	gg(head);
	ff(tail...);
}

template<typename C>
using Element_type = typename C::value_type;

template<typename Container>
void algo(Container& c) {
	std::vector<Element_type<Container>> vec;
	//...
}




/*void user() {
	std::vector<std::unique_ptr<piot::Shape>> v;
	while(std::cin) {
		v.push_back(read_shape(std::cin));
		for_all(v, [](piot::Shape s){s.draw(); });
		for_all(v, [](piot::Shape s){s.rotate(45); })
	}
}*/


/*void write2(const piot3::Vector<std::string> vs) {
	for (auto& s : vs) {
		std::cout << s << std::endl;
	}
}*/

/*void write(const piot3::Vector<std::string>& vs) {
	for (int i = 0; i!=vs.size(); ++i) {
		std::cout << vs.operator [](i) << std::endl;
	}
}*/

void bad_copy() {
	piot::Vector v1(5), v2(5);
	v1 = v2;
}

void use(piot::Container& c) {
	const int sz = c.size();
	for ( int i=0; i!=sz; ++i) {
		std::cout << c[i] << std::endl;
	}
}

void g() {
	piot::Vector_container vc{10, 9, 8, 7, 6, 5, 4, 3, 2, 1 ,0};
	use(vc);
}

void vector_test() {
	piot::Vector v(10);
	for (int i=0; i!=v.size(); ++i) {
		v[i] = i*2;
		std::cout << v[i] << ' ';
	}
	std::cout << std::endl;
}

void v_initializer_test() {
	piot::Vector v{2, 4, 6, 8, 10};
	for (int i=0; i!=v.size(); ++i) {
		v[i] = i*2;
		std::cout << v[i] << ' ';
	}
	std::cout << std::endl;

}

void rotate_all(std::vector<piot::Shape*>& vec, int angle) {
	for (auto p : vec) {
		p->rotate(angle);
	}
}


/*piot::Vector read(istream& is) {
	piot::Vector v;
	for (double d; is>>d; ) {
		v.push_back(d);
	}
	return v;
}*/

piot::Vector operator+(const piot::Vector& a, const piot::Vector& b) {
	/*if (a.size() != b.size()) {
		throw Vector_size_mismatch{};
	}*/
	piot::Vector res(a.size());
	for (int i=0; i!=a.size(); ++i) {
		res[i] = a[i] + b[i];
	}
	return res;
}

namespace piot4_5 {
	struct Entry {
		std::string name;
		int number;
	};

	std::ostream& operator<<(std::ostream& os, const Entry& e) {
		return os << "{\"" << e.name << "\", " << e.number << "}";
	}

	bool operator==(const Entry& x, const Entry& y) {
		return (x.name == y.name && x.number == y.number);
	}

	bool operator<(const Entry& x, const Entry& y) {
		return x.name < y.name;
	}

	void f(std::vector<Entry>& vec, std::list<Entry>& lst) {
		std::sort(vec.begin(), vec.end());
		std::unique_copy(vec.begin(), vec.end(), lst.begin());
	}

	std::list<Entry> f(std::vector<Entry>& vec) {
		std::list<Entry> res;
		std::sort(vec.begin(), vec.end());
		std::unique_copy(vec.begin(), vec.end(), std::back_inserter(res));
		return res;
	}

	bool has_c(const std::string& s, char c) {
		return std::find(s.begin(), s.end(), c) != s.end();
	}

/*	std::vector<std::string::iterator> find_all(std::string& s, char c) {
		std::vector<std::string::iterator> res;
		for (auto p=s.begin(); p!=s.end(); ++p) {
			if (*p == c) {
				res.push_back(p);
			}
		}
		return res;
	}*/

	template <typename T> using Invoke = typename T::type;

	template<typename T>
	using Iterator = typename T::iterator;

	template<typename C, typename V>
	std::vector<Iterator<C>> find_all(C& c, V v) {
		std::vector<Iterator<C>> res;
		for (auto p=c.begin(); p!=c.end(); ++p) {
			if (*p==v) {
				res.push_back(p);
			}
		}
		return res;
	}


	void test() {
		std::string m{"Mary had a little lamb"};
		for (auto p : find_all(m, 'x')) {
			if (*p!='x') {
				std::cerr << "a buggy bug!\n";
			}
		}
		std::cout << "test 1 \n";

		std::list<double> ld{1.1, 2.2, 3.3, 4.4, 1.1};
		for (auto p :find_all(ld, 1.1)) {
			if (*p!=1.1) {
				std::cerr << "omg omg blad!\n";
			}
		}
		std::cout << "test 2 \n";

		std::vector<std::string> vs{"red", "blue", "green", "green", "orange", "green"};
		for (auto p : find_all(vs, "green")) {
			if (*p!="green") {
				std::cerr << "blad!\n";
			}
		}
		std::cout << "test 3 \n";

		for (auto p : find_all(vs, "green")) {
			std::cout << *p << std::endl;
		}
	}

	struct Greater_than {
	     int val;
	     Greater_than(int v) : val{v} { }
	     bool operator()(const std::pair<std::string,int>& r) { return r.second>val; }
	};

	void ff(std::map<std::string, int>& m) {
		//auto p = std::find_if(m.begin(), m.end(), Greater_than{42});
		int cxx = std::count_if(m.begin(), m.end(), [](const std::pair<std::string, int>& r){return r.second>42;});
		++cxx;
		--cxx;
	}


}

int main() {

	r06::f_init_2(7.0, 1025);


	/*std::cout << "first: ";
	ff(1, 2.2, "hello", 5);
	std::cout << "\nsecond: ";
	ff(0.2, 'c', "yuck!", 0, 1, 2);
	std::cout << std::endl;*/
	/*std::cout << "hello!" << std::endl;
	std::vector<int> v{1,1,1,1,1,1,1,2,3,4,5,6,7,8,9,10};
	std::list<std::string> s{"a", "b", "c", "d", "e", "f", "g", "h", "i"};
	fcnt(v, s, 6, "e");*/
	return 0;
}



