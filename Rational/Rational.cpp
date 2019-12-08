#include <iostream>
#include "Rational.h"

int gcd(int a, int b) {
	while (b) {
		a %= b;
		int z = a;
		a = b;
		b = z;
	}
	return a;
}

int LCM(int a, int b)
{
	return a * b / gcd(a, b);
}

void FractionReduction(Rational& r) {
	int num = r.getNumenator();
	int denom = r.getDenominator();
	int c = gcd(num, denom);
	num /= c;
	denom /= c;
	r.setNumenator(num);
	r.setDenominator(denom);
}

Rational::Rational(int num, int denom) {
	numenator = num;
	denominator = denom;
	if (denominator == 0) {
		throw DivisionByZeroException("Division by zero exception");
	}

}

void Rational::setNumenator(int a) { numenator = a; }
void Rational::setDenominator(int a) { denominator = a; }
int Rational::getDenominator() const { return denominator; }
int Rational::getNumenator() const { return numenator; }
double Rational::getDouble() const { return static_cast<double> (numenator) / denominator; }

std::ostream& operator<< (std::ostream& out, const Rational& rational) {
	out << rational.numenator << "/" << rational.denominator << std::endl;
	return out;
}

std::istream& operator>> (std::istream& in, Rational& rational) {
	in >> rational.numenator;
	in >> rational.denominator;
	rational = Rational(rational.numenator, rational.denominator);
	return in;
}

Rational& operator*=(Rational& r1, const Rational r2)
{
	int a = r1.getNumenator() * r2.getNumenator();
	int b = r1.getDenominator() * r2.getDenominator();
	r1.setNumenator(a);
	r1.setDenominator(b);
	FractionReduction(r1);
	return r1;
}

Rational& operator+=(Rational& r1, const Rational& r2) {
	int denom1 = r1.getDenominator();
	int denom2 = r2.getDenominator();
	int lcm = LCM(denom1, denom2);
	int a = lcm / denom1;
	int b = lcm / denom2;
	int num = a * r1.getNumenator() + b * r2.getNumenator();
	r1.setNumenator(num);
	r1.setDenominator(lcm);
	FractionReduction(r1);
	return r1;
}

bool operator==(const Rational& lhs, const Rational& rhs)
{
	if (lhs.getDouble() == rhs.getDouble()) {
		return true;
	}
	else {
		return false;
	}
}

bool operator>(const Rational& lhs, const Rational& rhs)
{
	if (lhs.getDouble() > rhs.getDouble()) {
		return true;
	}
	else {
		return false;
	}
}

Rational operator+(const Rational& r1, const Rational& r2) {
	Rational r;
	int denom1 = r1.getDenominator();
	int denom2 = r2.getDenominator();
	int lcm = LCM(denom1, denom2);
	int a = lcm / denom1;
	int b = lcm / denom2;
	int num = a * r1.getNumenator() + b * r2.getNumenator();
	r.setNumenator(num);
	r.setDenominator(lcm);
	FractionReduction(r);
	return r;
}

Rational operator*(const Rational& r1, const Rational& r2) {
	Rational r;
	int a = r1.getNumenator() * r2.getNumenator();
	int b = r1.getDenominator() * r2.getDenominator();
	r.setNumenator(a);
	r.setDenominator(b);
	FractionReduction(r);
	return r;
}

Rational& operator-(Rational& r)
{
	int a = r.getNumenator() * -1;
	r.setNumenator(a);
	return r;
}

DivisionByZeroException::DivisionByZeroException(std::string error)
	:m_error(error)
{
}
const char* DivisionByZeroException::getError() { return m_error.c_str(); }

int main()
{
	try {
		Rational finalFraction;
		Rational fraction1(1, 5);
		Rational fraction2(9, 5);
		finalFraction = fraction1 + fraction2;
		std::cout << finalFraction;

	}
	catch (DivisionByZeroException& exception) {
		std::cerr << "A Rational exception  occured (" << exception.getError() << ")\n";
	}
}