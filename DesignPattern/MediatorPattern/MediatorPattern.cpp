#include "../Common/head.h"

class Person;

class Mediator {
public:
	virtual void Send(const std::string& msg, Person* person) = 0;
	virtual ~Mediator() {}
	void BuildRelation(Person* a, Person* b) {
		m_a = a;
		m_b = b;
	}
protected:
	Person* m_a;
	Person* m_b;
};

class ConcreteMediator :public Mediator {
public:
	void Send(const std::string& msg, Person* p) {
		if (p == m_a) {
			std::cout << msg << "--Mediator--to--PersonB" << std::endl;
		}
		else if (p == m_b) {
			std::cout << msg << "--Mediator--to--PersonA" << std::endl;
		}
	}
};

class Person {
public:
	Person(Mediator* md) :_md(md) {	}
	virtual void SendMsg(const std::string& msg) = 0;
	virtual ~Person() {}

protected:
	Mediator* _md;
};

class ConcretePersonA :public Person {
public:
	ConcretePersonA(Mediator* md) :Person(md) {	}

	void SendMsg(const std::string& msg) {
		_md->Send(msg, this);
	}
};

class ConcretePersonB : public Person {
public:
	ConcretePersonB(Mediator* md):Person(md){}

	void SendMsg(const std::string& msg) {
		_md->Send(msg, this);
	}
};

int main() {
	Mediator* mediator = new ConcreteMediator();
	Person* a = new ConcretePersonA(mediator);
	Person* b = new ConcretePersonB(mediator);

	mediator->BuildRelation(a, b);
	a->SendMsg("I'm PersonA");
	b->SendMsg("I'm PersonB");

	DEL(a);
	DEL(b);
	DEL(mediator);

	system("pause");
	return 0;
}

