#pragma once
#include "SubjectObserver.h"
#include "Observer.h"

class ConcreteSubject :public ISubject {
public:
	ConcreteSubject() { m_price = 10.0f; }

	void SetPrice(float f) {
		m_price = f;
	}

	void Register(IObserver* p) {
		m_observer.push_back(p);
	}

	void Destory(IObserver* p) {
		m_observer.remove(p);
	}

	void Notify(IObserver * p = NULL) {
		auto it = m_observer.begin();
		while (it != m_observer.end()) {
			if(p != NULL){
				if ((*it) == p) {
					(*it)->update(m_price);
					break;
				}
			}
			else {
				(*it)->update(m_price);
			}
			it++;
		}
	}
private:
	float m_price;
	list<IObserver*> m_observer;
};

