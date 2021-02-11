#pragma once
#include <string>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <stdexcept>

class TFrac
{
private:
	int num;
	int den;
	
public:
	TFrac();
	TFrac(int, int);
	TFrac(std::string);

	TFrac copy();
	TFrac add(TFrac&);
	TFrac multiply(TFrac&);
	TFrac subtract(TFrac&);
	TFrac divide(TFrac&);
	TFrac operator+(TFrac&);
	TFrac operator-(TFrac&);
	TFrac operator*(TFrac&);
	TFrac operator/(TFrac&);
	TFrac square();
	TFrac reverse();
	TFrac operator-();
	bool operator==(TFrac);
	bool operator>(TFrac);

	int getNumeratorNum();
	int getDenominatorNum();
	std::string getNumeratorString();
	std::string getDenominatorString();
	std::string getFractionString();
};

