#pragma once
#include <string>
#include <typeinfo>
#include <exception>

using namespace std;

enum StateOfMemory {
	_Off,
	_On
};

template <class T>
class TMemory 
{
private:
	T FNumber;
	int FState;
public:
	TMemory(T FNumber);
	void write(T FNumber);
	T get();
	void add(T FNumber);
	void clear();
	string readFState();
	T readNumber();
	~TMemory();
};

template <class T>
TMemory<T>::TMemory(T FNumber) 
{
	string type = typeid(T).name();
	if (type != "class TFracEditor" &&
		type != "class TPNumber" &&
		type != "class TComplexEditor" &&
		type != "bool" &&
		type != typeid(string).name())
	{
		this->FNumber = FNumber;
		this->FState = _Off;
	}
	else {
		throw invalid_argument("Invalid type");
	}
}

template<class T>
void TMemory<T>::write(T FNumber)
{
	this->FNumber = FNumber;
	this->FState = _On;
}

template<class T>
T TMemory<T>::get()
{
	this->FState = _On;
	return T(this->FNumber);
}

template<class T>
void TMemory<T>::add(T FNumber)
{
	this->FNumber = this->FNumber + FNumber;
	this->FState = _On;
}

template<class T>
void TMemory<T>::clear()
{
	T newObj;
	this->FNumber = newObj;
	this->FState = _Off;
}

template<class T>
string TMemory<T>::readFState()
{
	return string(to_string(this->FState));
}

template<class T>
T TMemory<T>::readNumber()
{
	return this->FNumber;
}

template<class T>
TMemory<T>::~TMemory() {}