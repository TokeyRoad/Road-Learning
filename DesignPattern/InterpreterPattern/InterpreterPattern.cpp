#include "../Common/head.h"


class Context {};

class Expression {
public:
	virtual ~Expression() {}
	virtual void Interpret(const Context& c) = 0;
};

class TerminalExpression :public Expression {
public:
	TerminalExpression(const std::string& statement) {
		_statement = statement;
	}

	void Interpret(const Context& c) {
		std::cout << this->_statement << "--TerminalExpression" << std::endl;
	}

private:
	std::string _statement;
};

class NonterminalExpression :public Expression {
public:
	NonterminalExpression(Expression* expression, int times) {
		_expression = expression;
		_times = times;
	}

	void Interpret(const Context& c) {
		for (size_t i = 0; i < _times; ++i) {
			_expression->Interpret(c);
		}
	}

private:
	Expression* _expression;
	int _times;
};

int main() {
	Context* c = new Context();
	Expression* tp = new TerminalExpression("echo");
	Expression* ntp = new NonterminalExpression(tp, 4);
	ntp->Interpret(*c);

	DEL(ntp);
	DEL(tp);
	DEL(c);
	system("pause");
	return 0;
}