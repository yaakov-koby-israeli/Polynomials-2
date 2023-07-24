#include "Polynomial.h"
#include <iostream>

int Polynomial::MaxDegree = 0;

Polynomial::Polynomial(int degree)
{
	this->degree = degree;
	this->Coeff = new double[degree+1];
	int i;
	for (i = 0; i <= degree; i++)
		this->Coeff[i] = 0;
}

Polynomial::Polynomial(double* ptr, int degree)
{
	this->degree = degree;
	Coeff = new double[degree + 1];

	for (int i = 0; i <= degree; i++)
	{
		Coeff[i] = ptr[i];
		if (ptr[i] && i > MaxDegree)
			MaxDegree = i;
	}	
}
Polynomial::Polynomial(const Polynomial& p)
{
	degree = p.degree;
	if (!p.Coeff) Coeff = NULL;
	else
	{
		Coeff = new double[degree + 1];
		int i;
		for (i = 0; i <= degree; i++)
			Coeff[i] = p.Coeff[i];
	}
}


Polynomial::~Polynomial()
{
	/*if (Coeff)
	{
		delete[]Coeff;
		Coeff = NULL;
	}*/
}

int Polynomial::getMaxDegree()
{
	return MaxDegree;
}

int Polynomial::getDegree(bool what) const
{
	int i,value=0;
	if (what)
	{
		for (i = 0; i <= degree; i++)
		{
			if (Coeff[i])
				value = i;
		}
		return value;
	}
	else return degree;

}

Polynomial &Polynomial::setCoeff(int degree, double num)
{
	Coeff[degree] = num;
	return *this;
}

double Polynomial::getCoeff(int index) const
{
	if (index >=0&&index<=degree) return this->Coeff[index];
	return -1234.12;

}

void Polynomial::print()const
{
	cout << "polynomial = ";
	if (!Coeff && !degree) {
		cout << "0" << endl;
		return;
	}
	int i, max = 0;
	for (i = 0; i <= degree; i++) {
		if (Coeff[i] && i > max)
			max = i;
	}
	for (i = 0; i <= max; i++) {
		if (i == 0) {
			if (!Coeff[i])
				cout << "0";
			else
				cout << Coeff[i];
		}
		else {
			cout << "+";
			if (!Coeff[i])
				cout << "0";
			else
				cout << "(" << Coeff[i] << ")";
			cout << "*X^" << i;
		}
	}
	cout << endl;
}

Polynomial& Polynomial::operator*(const double num)const //A*2
{
	Polynomial* poly = new Polynomial(degree);
	*poly = *this;
	int i;
	for (i = 0; i <= degree; i++)
		poly->Coeff[i] *= num;
	
	return *poly;

}
Polynomial& Polynomial::operator=(const Polynomial& A)
{
	if (!Coeff)
		delete[] Coeff;
	if (degree < A.degree) {
		Coeff = new double[A.degree + 1];
		degree = A.degree;
		MaxDegree = A.MaxDegree;
	}
	int i;
	
	for (i = 0; i <= A.degree; i++)
		Coeff[i] = A.Coeff[i];
	return *this;
}

Polynomial& Polynomial::operator*(const Polynomial& A) const
{
	Polynomial* poly = new Polynomial(degree+A.degree);
	int i,j;
	for (i = 0; i <= degree; i++) {
		for (j = 0; j <= A.degree; j++) {
			poly->Coeff[i + j] += A.Coeff[j] * this->Coeff[i];
			if (poly->Coeff[i+j] && i+j > MaxDegree )
				MaxDegree = i+j;
		}
	}
	return *poly;

}


Polynomial& Polynomial::operator+(const Polynomial& A)
{
	int x,i,y,flag=0;
	if (degree >= A.degree) {
		x = degree;
		y = A.degree;
	}
	else {
		flag = 1;
		x = A.degree;
		y = degree;
	}
	
	Polynomial* poly = new Polynomial(x);
	if (MaxDegree >= A.MaxDegree)
		poly->MaxDegree = MaxDegree;
	else
		poly->MaxDegree = A.MaxDegree;
	for (i = 0; i <= y; i++) {
		poly->Coeff[i] = Coeff[i] + A.Coeff[i];	
	}
	while (i <= x) {
		if (flag == 0) {
			poly->Coeff[i] = Coeff[i];
			i++;
		}
		else {
			poly->Coeff[i] = A.Coeff[i];
			i++;
		}
		
	}
	return *poly;
}

Polynomial& Polynomial::operator-(const Polynomial& A)
{
	int x, i, y, flag = 0,max=0;
	if (degree >= A.degree) {
		x = degree;
		y = A.degree;
	}
	else {
		flag = 1;
		x = A.degree;
		y = degree;
	}

	Polynomial* poly = new Polynomial(x);

	for (i = 0; i <= y; i++) {
		poly->Coeff[i] = Coeff[i] - A.Coeff[i];
		if (poly->Coeff[i] && max < i)
			poly->MaxDegree = i;
	}
	while (i <= x) {
		if (flag == 0) {
			poly->Coeff[i] = Coeff[i];
			if (poly->Coeff[i] && max < i)
				poly->MaxDegree = i;
			i++;
		}
		else {
			poly->Coeff[i] = A.Coeff[i];
			if (poly->Coeff[i] && max < i)
				poly->MaxDegree = i;
			i++;
		}

	}
	return *poly;
}

double& Polynomial::operator[](int const index) 
{
	return this->Coeff[index];
}

ostream& operator<<(ostream& cout, const Polynomial& A)
{
	cout << "polynomial = ";
	if (!A.Coeff && !A.degree) {
		cout << "0" << endl;
		return cout;
	}
	int i, max = 0;
	for (i = 0; i <= A.degree; i++) {
		if (A.Coeff[i] && i > max)
			max = i;
	}
	for (i = 0; i <= max; i++) {
		if (i == 0) {
			if (!A.Coeff[i])
				cout << "0";
			else
				cout << A.Coeff[i];
		}
		else {
			cout << "+";
			if (!A.Coeff[i])
				cout << "(0)";
			else
				cout << "(" << A.Coeff[i] << ")";
			cout << "*X^" << i;
		}
	}
	cout << endl;
	return cout;
}
const double Polynomial::operator[](int const index) const {
	return getCoeff(index);
}

Polynomial& operator*(const double n, const Polynomial& A)
{
	return A * n;
}


 
