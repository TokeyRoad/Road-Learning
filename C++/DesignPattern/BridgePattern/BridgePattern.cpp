#include "../Common/head.h"

class Abstraction {
public:
	virtual void Operation() = 0;
	virtual ~Abstraction(){}

protected:
	Abstraction() {}
};


class AbstractionImp : public Abstraction {
public:
	virtual void Operation() = 0;
	virtual ~AbstractionImp() {}

protected:
	AbstractionImp() {}
};

class ConcreteAbstractionImp :public AbstractionImp {
public:
	void Operation() {
		std::cout << "ConcreteAbstractionImp Operation..." << std::endl;
	}
};

class RefinedAbstraction : public Abstraction {
public:
	RefinedAbstraction(AbstractionImp* imp) {
		_imp = imp;
	}
	void Operation() {
		_imp->Operation();
	}
private:
	AbstractionImp* _imp;
};

int main() {
	AbstractionImp* imp = new ConcreteAbstractionImp();
	Abstraction* abs = new RefinedAbstraction(imp);

	abs->Operation();

	DEL(imp);
	DEL(abs);

	system("pause");
	return 0;
}



