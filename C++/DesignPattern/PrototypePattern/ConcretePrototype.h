#pragma once
#include "Prototype.h"

class BWM :public Car {
public:
	BWM(string own) { m_own = own; }
	~BWM(){}
	
	Car* clone() {
		return new BWM(*this);
	}
	void run() {
		cout << "this is " << m_own << endl;
	}

private:
	string m_own;
	BWM(const BWM &b) {
		m_own = b.m_own;
	}
};