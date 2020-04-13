#include "../Common/head.h"


class IStrategy {
public:
	virtual ~IStrategy() {}
	virtual void AlgorithmInterface() = 0;	//算法统一接口
};



