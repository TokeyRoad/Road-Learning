#include "../Common/head.h"


class Handle {
public:
	virtual ~Handle() {}

	virtual void HandleRequest() = 0;

	void SetSuccessor(Handle* succ) {
		_succ = succ;
	}

	Handle* GetSuccessor() const {
		return _succ;
	}

protected:
	Handle() { _succ = nullptr; }

	Handle(Handle* succ) { _succ = succ; }

private:
	Handle* _succ;
};

class ConcreteHandleA : public Handle {
public:
	ConcreteHandleA() {}
	ConcreteHandleA(Handle* succ)
		: Handle(succ){}

	void HandleRequest() {
		if (this->GetSuccessor()) {
			std::cout << "ConcreteHandleA--Successor" << std::endl;
			GetSuccessor()->HandleRequest();
		}
		else {
			std::cout << "ConcreteHandleA::HandleRequest.." << std::endl;
		}
	}
};

class ConcreteHandleB : public Handle {
public:
	ConcreteHandleB() {}
	ConcreteHandleB(Handle* succ)
		: Handle(succ){}

	void HandleRequest() {
		if (this->GetSuccessor()) {
			std::cout << "ConcreteHandleB--Successor" << std::endl;
			GetSuccessor()->HandleRequest();
		}
		else {
			std::cout << "ConcreteHandleB::HandleRequest..." << std::endl;
		}
	}
};


int main() {
	Handle* h1 = new ConcreteHandleA();
	Handle* h2 = new ConcreteHandleB(h1);
	//Handle* h2 = new ConcreteHandleB();
	//h1->SetSuccessor(h2);

	h2->HandleRequest();

	DEL(h2);
	DEL(h1);
	system("pause");
	return 0;
}


