#pragma once
#include "IStrategy.h"

/*
�����������ʵ��������ʵ�֣�IStrategyͳһ���еĽӿ�
*/

class StrategyA : public IStrategy {
public:
	virtual void AlgorithmInterface() {
		std::cout << "This is StrategyA" << std::endl;	//����ʵ��
	}
};

class StrategyB : public IStrategy {
public:
	virtual void AlgorithmInterface() {
		std::cout << "This is StrategyB" << std::endl;	//����ʵ��
	}
};
