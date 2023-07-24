#ifndef RATIONAL_H_
#define RATIONAL_H_
#include "Polynomial.h"

class Rational
{
private:

	Polynomial nom, denom;

public:

	Rational();
	Rational(const Polynomial&, const Polynomial&);

	Polynomial &getNom();
	Polynomial &getDenom();

	void print();
	friend ostream& operator<<(ostream&, const Rational& );
	Rational& operator=(const Rational& );
	Rational& operator*(const Rational& ) const;
	Rational& operator*(const double) const;
	friend Rational& operator*(const double,const Rational&);
	Rational& operator+(const Rational&) const;
};

#endif

