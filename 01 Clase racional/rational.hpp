#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

#define EPSILON 1e-6

using namespace std;

class rational
{
	private:
		int num_, den_;

	public:
		rational();
		rational(int num, int den);
		~rational(){}

		//Get & Set
		int get_num() const {return num_;}
		int get_den() const {return den_;}
		void set_num(const int num) {num_ = num;}
		void set_den(const int den) {den_ = den;}

		//Operations
		rational add(const rational&);
		rational substract(const rational&);
		rational multiply(const rational&);
		rational divide(const rational&);
		void mcm(const rational&);
		void mcd(void);
		double value(void) const;

		//Read & Write
		void write(ostream& os = cout) const;
		void read(istream& is = cin);

		//Comparators functions
		bool equal(const rational& r, const double precision = EPSILON) const;
		bool greater(const rational& r, const double precision = EPSILON) const;
		bool less(const rational& r, const double precision = EPSILON)const;

};
