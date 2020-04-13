#include "../Common/head.h"

class Target {
public:
	virtual void Request() {
		std::cout << "Target::Request..." << std::endl;
	}
	virtual ~Target() {}
};

class Adaptee {
public:
	void SpecificRequest() {
		std::cout << "Adaptee::SpecificRequest..." << std::endl;
	}
};

class Adapter : public Target , private Adaptee {
public:
	Adapter(Adaptee* ade) {
		_ade = ade;
	}
	void Request() {
		_ade->SpecificRequest();
	}
private:
	Adaptee* _ade;
};


int main() {
	Adaptee* adaptee = new Adaptee();
	Adapter* adapter = new Adapter(adaptee);

	adapter->Request();
	DEL(adapter);
	DEL(adaptee);

	system("pause");
	return 0;
}