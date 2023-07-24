#include <iostream>
#include "Rational.h"

Rational::Rational()
{
	denom.setCoeff(0, 1);
}

Rational::Rational(const Polynomial& nom1, const Polynomial& denom1):nom(nom1),denom(denom1)
{

}

Polynomial& Rational::getNom()
{
	return nom;
}

Polynomial& Rational::getDenom()
{
	return denom;
}

void Rational::print()
{
	nom.print();
	cout << "--------------------" << endl;
	denom.print();
}

Rational& Rational::operator=(const Rational& R1)
{
	this->nom = R1.nom;
	this->denom = R1.denom;
	return *this;
}

Rational& Rational::operator*(const Rational& R1)const
{
	Rational *R2 = new Rational(nom*R1.nom,denom*R1.denom);
	return *R2;
}

Rational& Rational::operator*(const double c)const{
	Rational* R2 = new Rational(nom *c , denom * c);
	return *R2;
}

Rational& operator*(const double c, const Rational& r) {
	return r * c;
}

Rational& Rational::operator+(const Rational& R1)const
{
	Rational* R2 = new Rational(nom * R1.denom + denom * R1.nom, denom * R1.denom);
	return *R2;
	
}

ostream& operator<<(ostream& cout, const Rational& R1)
{
	cout << "numerator="<< R1.nom;
	cout <<" ----------------"<<endl ;
	cout << "denomirator="<< R1.denom;
	return cout;
}






