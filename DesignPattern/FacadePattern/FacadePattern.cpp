#include "../Common/head.h"


class SubSystem1 {
public:
	void Operation() {
		std::cout << "SubSystem1 operation..." << std::endl;
	}
};


class SubSystem2 {
public:
	void Operation() {
		std::cout << "SubSystem2 operation..." << std::endl;
	}
};

class Facade {
public:
	Facade() {
		_sub1 = new SubSystem1();
		_sub2 = new SubSystem2();
	}

	~Facade() {
		DEL(_sub1);
		DEL(_sub2);
	}

	void OperationWrapper() {
		_sub1->Operation();
		_sub2->Operation();
	}

private:
	SubSystem1* _sub1;
	SubSystem2* _sub2;
};

int main() {
	Facade* facade = new Facade();

	facade->OperationWrapper();

	DEL(facade);
	system("pause");
	return 0;
}