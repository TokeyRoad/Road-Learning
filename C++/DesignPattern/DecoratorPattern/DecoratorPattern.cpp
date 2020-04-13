#include "../Common/head.h"

class Component {
public:
	virtual void Operation() = 0;
	virtual ~Component() {}
};

class ConcreteComponent : public Component {
public:
	void Operation() {
		std::cout << "ConcreteComponent::Operation..." << std::endl;
	}
};


class Decorator {
public:
	virtual void Operation() = 0;
	virtual void AddBehavior() = 0;
	virtual ~Decorator() {}
};

class ConcreteDecorator : public Decorator {
public:
	ConcreteDecorator(Component* com) {
		_com = com;
	}

	void AddBehavior() {
		std::cout << "ConcreteDecorator::AddBehavior..." << std::endl;
	}

	void Operation() {
		std::cout << "ConcreteDecorator::Operation..." << std::endl;
		AddBehavior();
		_com->Operation();
	}
private:
	Component* _com;
};

int main() {
	Component* com = new ConcreteComponent();
	Decorator* dec = new ConcreteDecorator(com);
	dec->Operation();

	DEL(com);
	DEL(dec);

	system("pause");
	return 0;
}

