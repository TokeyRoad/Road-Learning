#include "../Common/head.h"


class Reciver {
public:
	void Action() {
		std::cout << "Reciver::Action..." << std::endl;
	}
};

class Command {
public:
	virtual ~Command(){}
	virtual void Excute() = 0;
};

class ConcreteCommand : public Command {
public:
	ConcreteCommand(Reciver* rev) {
		_rev = rev;
	}

	void Excute() {
		_rev->Action();
	}
private:
	Reciver* _rev;
};

class Invoker {
public:
	Invoker(Command* cmd) {
		_cmd = cmd;
	}

	void Invoke() {
		_cmd->Excute();
	}

private:
	Command* _cmd;
};


int main() {
	Reciver* rev = new Reciver();
	Command* cmd = new ConcreteCommand(rev);
	Invoker* inv = new Invoker(cmd);
	inv->Invoke();

	DEL(rev);
	DEL(cmd);
	DEL(inv);

	system("pause");
	return 0;
}