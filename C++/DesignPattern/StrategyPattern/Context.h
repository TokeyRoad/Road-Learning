#include "ConcreteStrategy.h"

class Context {
public:
	Context(IStrategy* strategy) { m_strategy = strategy; }
	void DoAction() {
		m_strategy->AlgorithmInterface();
	}

private:
	IStrategy* m_strategy;
};