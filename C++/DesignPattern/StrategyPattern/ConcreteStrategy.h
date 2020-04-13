#pragma once
#include "IStrategy.h"

/*
各个策略类的实现由自身实现，IStrategy统一所有的接口
*/

class StrategyA : public IStrategy {
public:
	virtual void AlgorithmInterface() {
		std::cout << "This is StrategyA" << std::endl;	//具体实现
	}
};

class StrategyB : public IStrategy {
public:
	virtual void AlgorithmInterface() {
		std::cout << "This is StrategyB" << std::endl;	//具体实现
	}
};
