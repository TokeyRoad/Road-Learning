#include "ConcreteStrategy.h"
#include "Context.h"



int main() {
	IStrategy* ps = new StrategyA();
	Context* pc = new Context(ps);
	pc->DoAction();

	DEL(pc);
	DEL(ps);

	system("pause");
	return 0;
}