#include "../Common/head.h"

class AbstractClass {
public:
	virtual void TemplateMethod() {
		PrimitiveOperation1();
		PrimitiveOperation2();
	}

	virtual ~AbstractClass() {}
protected:
	virtual void PrimitiveOperation1() = 0;
	virtual void PrimitiveOperation2() = 0;
	AbstractClass() {}
};

class ConcreteClass1 : public AbstractClass {
public:
	void PrimitiveOperation1() {
		std::cout << "ConcreteClass1:PrimitiveOperation1" << std::endl;
	}

	void PrimitiveOperation2() {
		std::cout << "ConcreteClass1::PrimitiveOperation2" << std::endl;
	}
};

class ConcreteClass2 : public AbstractClass {
public:
	void PrimitiveOperation1() {
		std::cout << "ConcreteClass2::PrimitiveOperation1" << std::endl;
	}
	void PrimitiveOperation2() {
		std::cout << "ConcreteClass2::PrimitiveOperation2" << std::endl;
	}
};


int main() {
	AbstractClass* p1 = new ConcreteClass1();
	AbstractClass* p2 = new ConcreteClass2();
	p1->TemplateMethod();
	p2->TemplateMethod();

	DEL(p1);
	DEL(p2);

	system("pause");
	return 0;
}