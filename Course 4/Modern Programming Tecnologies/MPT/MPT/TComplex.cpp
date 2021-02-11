#include "TComplex.h"

TComplex::TComplex()
{
	re = 0;
	im = 0;
}

TComplex::TComplex(double a, double b) : re(a), im(b) {}

TComplex::TComplex(std::string num)
{
	size_t index = num.find("+i*");
	int sign = 1;
	if (index == std::string::npos)
	{
		index = num.find("-i*");
		sign = -1;
	}
	re = std::stod(num.substr(0, index));
	im = std::stod(num.substr(index + 3)) * sign;
}

TComplex TComplex::copy()
{
	return { re, im };
}

TComplex TComplex::add(TComplex d)
{
	return { re + d.re, im + d.im };
}

TComplex TComplex::operator+(TComplex d)
{
	return { re + d.re, im + d.im };
}

TComplex TComplex::multiply(TComplex d)
{
	return { (re * d.re - im * d.im), (re * d.im + im * d.re) };
}

TComplex TComplex::operator*(TComplex d)
{
	return { (re * d.re - im * d.im), (re * d.im + im * d.re) };
}

TComplex TComplex::square()
{
	return { (re * re - im * im), (re * im + re * im) };
}

TComplex TComplex::reverse()
{
	return { re / (re * re + im * im), -(im / (re * re + im * im)) };
}

TComplex TComplex::subtract(TComplex d)
{
	return { re - d.re, im - d.im };
}

TComplex TComplex::operator-(TComplex d)
{
	return { re - d.re, im - d.im };
}

TComplex TComplex::divide(TComplex d)
{
	return { ((re * d.re + im * d.im) / (d.re * d.re + d.im * d.im)),
	((d.re * im - re * d.im) / (d.re * d.re + d.im * d.im)) };
}

TComplex TComplex::operator/(TComplex d)
{
	return { ((re * d.re + im * d.im) / (d.re * d.re + d.im * d.im)),
	((d.re * im - re * d.im) / (d.re * d.re + d.im * d.im)) };
}

TComplex TComplex::operator-()
{
	return TComplex(0 - re, 0 - im);
}

double TComplex::abs()
{
	return sqrt(re * re + im * im);
}

double TComplex::angleRad()
{
	if (re == 0 && im == 0)
		return 0;
	if (re == 0 && im > 0)
		return M_PI_2;
	if (re == 0 && im < 0)
		return -M_PI_2;
	if (re > 0)
		return atan(im / re);
	if (re < 0)
		return atan(im / re) + M_PI;
	
	return -1;
}

double TComplex::angleDegree()
{
	return (angleRad() * 180) / M_PI;
}

TComplex TComplex::pow(int n)
{
	return { std::pow(abs(), n) * cos(n * angleRad()), std::pow(abs(), n) * sin(n * angleRad()) };
}

TComplex TComplex::root(int n, int i)
{
	if (i >= n)
		return { 0, 0 };

	return { (std::pow(abs(), 1.0 / (double)n) * (cos((angleRad() + 2 * i * M_PI) / (double)n))),
		(std::pow(abs(), 1.0 / (double)n) * (sin((angleRad() + 2 * i * M_PI) / (double)n))) };
}

bool TComplex::operator==(TComplex d)
{
	return (re == d.re && im == d.im);
}

bool TComplex::operator!=(TComplex d)
{
	return !(*this == d);
}

double TComplex::getReNum()
{
	return re;
}

double TComplex::getImNum()
{
	return im;
}

std::string TComplex::getReStr()
{
	return std::to_string(re);
}

std::string TComplex::getImStr()
{
	return std::to_string(im);
}

std::string TComplex::getComplexStr()
{
	std::string symbol = "+";

	if (im < 0) 
	{
		symbol = "-";
		im = -im;
	}

	std::ostringstream str;
	str << re << symbol << "i*" << im;

	return str.str();
}
