#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>
#include <sstream>

class TComplex
{
private:
	double re;
	double im;
public:
	TComplex();
	TComplex(double a, double b);
	TComplex(std::string num);

	TComplex copy();
	TComplex add(TComplex d);
	TComplex operator+(TComplex d);
	TComplex multiply(TComplex d);
	TComplex operator*(TComplex d);
	TComplex square();
	TComplex reverse();
	TComplex subtract(TComplex d);
	TComplex operator-(TComplex d);
	TComplex divide(TComplex d);
	TComplex operator/(TComplex d);
	TComplex operator-();
	double abs();
	double angleRad();
	double angleDegree();
	TComplex pow(int n);
	TComplex root(int n, int i);
	bool operator==(TComplex d);
	bool operator!=(TComplex d);
	double getReNum();
	double getImNum();
	std::string getReStr();
	std::string getImStr();
	std::string getComplexStr();
};