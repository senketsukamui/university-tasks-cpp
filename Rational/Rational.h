#pragma once
#include <iostream>

class Rational
{
private:
	int numenator;
	int denominator;

public:
	Rational(int num = 0, int denom = 1);
	int getNumenator() const;
	int getDenominator() const;
	void setNumenator(int a);
	void setDenominator(int a);
	double getDouble() const;
	friend std::ostream& operator<< (std::ostream& out, const Rational& rational);
	friend std::istream& operator>> (std::istream& in, Rational& rational);
};

class DivisionByZeroException {
private:
	std::string m_error;

public:
	DivisionByZeroException(std::string error);
	const char* getError();
};
std::ostream& operator<< (std::ostream& out, const Rational& rational);
std::istream& operator>> (std::istream& in, Rational& rational);
Rational& operator*= (Rational& r1, const  Rational r2);
bool operator== (const Rational& lhs, const Rational& rhs);
bool operator> (const Rational& lhs, const Rational& rhs);
Rational& operator- (Rational& r);
Rational& operator+=(Rational& r1, const Rational& r2);
Rational operator*(const Rational& r1, const Rational& r2);