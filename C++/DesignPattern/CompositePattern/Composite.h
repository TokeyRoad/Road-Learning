#pragma once
#include "Component.h"


class Composite :public Component {
public:
	Composite(string name) :Component(name) {}
	virtual ~Composite() {
		cout << "****DEL****" << endl;
		while (!m_elements.empty()) {
			auto it = m_elements.begin();
			cout << (*it)->GetName() << endl;
			DEL(*it);
			m_elements.erase(it);
		}
	}

	void Add(Component * cmpt) {
		m_elements.push_back(cmpt);
	}

	void Remove(Component * cmpt) {
		auto it = m_elements.begin();
		while (it != m_elements.end()) {
			if (*it == cmpt) {
				DEL(*it);
				m_elements.erase(it);
				break;
			}
			it++;
		}
	}

	Component* GetChild(int index) {
		if (index < 0 || index >= m_elements.size()) {
			return NULL;
		}
		return m_elements[index];
	}

	void Operation(int indent) {
		string newStr(indent, '-');
		cout << newStr << " " << m_strName << endl;
		auto it = m_elements.begin();
		while (it != m_elements.end()) {
			(*it)->Operation(indent + 2);
			it++;
		}
	}

private:
	Composite();
	vector<Component *> m_elements;
};