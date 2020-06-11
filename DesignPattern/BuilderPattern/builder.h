#pragma once
#include "Product.h"



/*
Builder(抽象建造者)：为创建一个产品对象的各个部件指定抽象接口
ConcreateBuild（具体建造者）：实现Builder的接口以构造和装配该产品的部件，定义并明确它所创建的表示，并提供一个检索产品的接口
Director（指挥者）：构建一个使用Builder接口的对象
Product（产品）：表示被构造的复杂对象，ConcreteBuilder创建该产品的内部表示并定义它的装配过程，包括定义组成部件的类，包括将这些组件装配成最终产品的接口。

优点：
	建造者独立，易于拓展
	便于控制细节风险
缺点：
	产品必须有共同点，范围有限制
	如果产品内部过于复杂，将会有很多的建造类

适用：
	需要生成的对象内部具有复杂的内部结构
	对象内部属性相互依赖

案例：
	电脑虽多，但结构基本一致，都是由 CPU、主板、内存、显卡等组成。
	如果为每台电脑都单独设计一个组装流程，管理的成本太高。
	这时，建造者模式就出现了，为所有系列指定一个统一的组装流程，所有的电脑都按照这个流程来组装。
*/



class IBuilder {
public:
	virtual void BuildCPU() = 0;
	virtual void BuildRam() = 0;
	virtual void BuildMainBoard() = 0;
	virtual void BuildVideoCard() = 0;
	virtual Computer* GetResult() = 0;
};