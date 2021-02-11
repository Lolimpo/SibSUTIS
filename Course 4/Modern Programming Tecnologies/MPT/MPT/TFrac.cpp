#include "TFrac.h"

TFrac::TFrac() 
{
	num = 0;
	den = 1;
}

TFrac::TFrac(int a, int b) : num(a), den(b)
{
	if (den == 0)
	{
		std::cerr << "Denominator can't be 0!" << std::endl;
		num = 0;
		den = 1;
		return;
	}

	int gcd = std::gcd(num, den);
	num /= gcd;
	den /= gcd;
	if (den < 0)
	{
		num *= -1;
		den *= -1;
	}
}

TFrac::TFrac(std::string frac)
{
	std::string s_num, s_den;
	size_t slash = frac.find('/');
	s_num = frac.substr(0, slash);
	s_den = frac.substr(slash + 1, frac.length());
	num = std::stoi(s_num);
	den = std::stoi(s_den);

	if (den == 0)
	{
		std::cerr << "Denominator can't be 0!" << std::endl;
		num = 0;
		den = 1;
		return;
	}

	int gcd = std::gcd(num, den);
	num /= gcd;
	den /= gcd;
	if (den < 0)
	{
		num *= -1;
		den *= -1;
	}
}

TFrac TFrac::copy()
{
	return {num, den};
}

TFrac TFrac::add(TFrac& frac)
{
	TFrac res;
	res.num = num * frac.den + frac.num * den;
	res.den = den * frac.den;
	int gcd = std::gcd(res.num, res.den);
	res.num /= gcd;
	res.den /= gcd;
	if (res.den < 0)
	{
		res.num *= -1;
		res.den *= -1;
	}
	return res;
}


TFrac TFrac::operator+(TFrac& frac)
{
	TFrac res;
	res.num = num * frac.den + frac.num * den;
	res.den = den * frac.den;
	int gcd = std::gcd(res.num, res.den);
	res.num /= gcd;
	res.den /= gcd;
	if (res.den < 0)
	{
		res.num *= -1;
		res.den *= -1;
	}
	return res;
}

TFrac TFrac::multiply(TFrac& frac)
{
	TFrac res;
	res.num = num * frac.num;
	res.den = den * frac.den;
	int gcd = std::gcd(res.num, res.den);
	res.num /= gcd;
	res.den /= gcd;
	if (res.den < 0)
	{
		res.num *= -1;
		res.den *= -1;
	}
	return res;
}

TFrac TFrac::operator*(TFrac& frac)
{
	TFrac res;
	res.num = num * frac.num;
	res.den = den * frac.den;
	int gcd = std::gcd(res.num, res.den);
	res.num /= gcd;
	res.den /= gcd;
	if (res.den < 0)
	{
		res.num *= -1;
		res.den *= -1;
	}
	return res;
}


TFrac TFrac::subtract(TFrac& frac)
{
	TFrac res;
	res.num = num * frac.den - frac.num * den;
	res.den = frac.den * den;
	int gcd = std::gcd(res.num, res.den);
	res.num /= gcd;
	res.den /= gcd;
	if (res.den < 0)
	{
		res.num *= -1;
		res.den *= -1;
	}
	return res;
}

TFrac TFrac::operator-(TFrac& frac)
{
	TFrac res;
	res.num = num * frac.den - frac.num * den;
	res.den = frac.den * den;
	int gcd = std::gcd(res.num, res.den);
	res.num /= gcd;
	res.den /= gcd;
	if (res.den < 0)
	{
		res.num *= -1;
		res.den *= -1;
	}
	return res;
}

TFrac TFrac::divide(TFrac& frac)
{
	if (frac.num == 0 || den == 0)
	{
		std::cout << "No divinition by 0!" << std::endl;
		return { 0, 1 };
	}
	TFrac res;
	res.num = num * frac.den;
	res.den = den * frac.num;
	int gcd = std::gcd(res.num, res.den);
	res.num /= gcd;
	res.den /= gcd;
	if (res.den < 0)
	{
		res.num *= -1;
		res.den *= -1;
	}
	return res;
}

TFrac TFrac::operator/(TFrac& frac)
{
	if (frac.num == 0 || den == 0)
	{
		std::cout << "No divinition by 0!" << std::endl;
		return { 0, 1 };
	}
	TFrac res;
	res.num = num * frac.den;
	res.den = den * frac.num;
	int gcd = std::gcd(res.num, res.den);
	res.num /= gcd;
	res.den /= gcd;
	if (res.den < 0)
	{
		res.num *= -1;
		res.den *= -1;
	}
	return res;
}

TFrac TFrac::square()
{
	return { num * num, den * den };
}

TFrac TFrac::reverse()
{
	return { den, num };
}


TFrac TFrac::operator-()
{
	return { -num, den };
}

bool TFrac::operator==(TFrac frac)
{
	return num == frac.num && den == frac.den;
}

bool TFrac::operator>(TFrac frac)
{
	return num * frac.den > frac.num * den;
}

int TFrac::getNumeratorNum()
{
	return num;
}

int TFrac::getDenominatorNum()
{
	return den;
}

std::string TFrac::getNumeratorString()
{
	return std::to_string(num);
}

std::string TFrac::getDenominatorString()
{
	return std::to_string(den);
}

std::string TFrac::getFractionString()
{
	return std::to_string(num) + '/' + std::to_string(den);
}
