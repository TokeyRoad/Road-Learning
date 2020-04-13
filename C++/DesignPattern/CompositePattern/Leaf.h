#pragma once
#include "Component.h"


class Leaf :public Component {
public:
	Leaf(string name) :Component(name) {}
	virtual ~Leaf(){}
	void Add(Component * cmpt) {
		cout << "Can't Add to Leaf" << endl;
	}

	void Remove(Component * cmpt) {
		cout << "Can't Remove from Leaf" << endl;
	}
	
	Component * GetChild(int index) {
		cout << "Can't Get child from Leaf" << endl;
		return NULL;
	}

	void Operation(int indent) {
		string newStr(indent, '-');
		cout << newStr << " " << m_strName << endl;
	}
private:
	Leaf();
};