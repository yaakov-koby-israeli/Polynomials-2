#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_
#include <iostream>
using namespace std;

class Polynomial
{

private:

	double* Coeff;
	int degree;	
	static int MaxDegree;

public:

	Polynomial(int degree=0);
	Polynomial(double* Coeff, int degree=0);
	Polynomial(const Polynomial&p);
	~Polynomial();

	static int getMaxDegree();
	int getDegree(bool what) const;
	
	Polynomial& setCoeff(int degree, double num);
	double getCoeff(int index)const;
	void print()const;
	friend ostream& operator<<(ostream&, const Polynomial&);
	Polynomial& operator* (const double)const;
	Polynomial& operator* (const Polynomial&)const;
	friend Polynomial& operator*(const double, const Polynomial&);
	Polynomial& operator=(const Polynomial& A);
	Polynomial& operator+(const Polynomial& A);
	Polynomial& operator-(const Polynomial& A);
	double& operator[](int const);
	const double operator[](int const) const;
	

};

#endif

