#include "../Common/head.h"

class Memento {
private:
	friend class Originator;

	Memento(const std::string& st) {
		_st = st;
	}
	void SetState(const std::string& st) {
		_st = st;
	}
	std::string GetState() {
		return _st;
	}


private:
	std::string _st;
};


class Originator {
public:
	Originator() {
		_mt = nullptr;
	}
	Originator(const std::string& st) {
		_st = st;
		_mt = nullptr;
	}

	Memento* CreateMemento() {
		return new Memento(_st);
	}
	void SetMemento(Memento* mt) {
		_mt = mt;
	}

	void RestoreToMemento(Memento* mt) {
		_st = mt->GetState();
	}

	std::string GetState() {
		return _st;
	}
	void SetState(const string& st) {
		_st = st;
	}

	void PrintState() {
		std::cout << _st << "..." << std::endl;
	}


private:
	std::string _st;
	Memento* _mt;
};


int main() {
	Originator* o = new Originator();
	o->SetState("old");
	o->PrintState();
	Memento* m = o->CreateMemento();
	o->SetState("new");
	o->PrintState();
	o->RestoreToMemento(m);
	o->PrintState();

	DEL(o);
	DEL(m);

	system("pause");
	return 0;
}


