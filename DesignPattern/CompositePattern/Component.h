#pragma once
#include "../Common/head.h"


/*
Component（抽象构件）:为叶子构件和容器构件对象定义接口，可以包含所有子类共有行为的声明和实现，在抽象构件中，声明了访问及管理子构件的接口（例如：Add(),Remove(),GetChild()）
Leaf(叶子构件)：叶子节点没有子节点，它实现了Component中定义的行为，对于访问及管理子构件的接口，可以通过异常等方式处理
Composite（容器构件）：容器节点包含子节点（可以是叶子构件，也可以是容器构件）。它提供了一个集合用于存储叶子构件，实现了Componnet中定义的行为，包含访问和管理子构件的接口，在其业务方法中可以递归调用叶子构件的业务方法

透明组合模式：
	在Componnet中定义了用于访问和管理子构件的接口，这样做的好处是确保所有的构件类都具有相同的接口。
	在Client看来，Leaf和Composite所提供的的接口是一致的



*/



class Component {
public:
	Component(string name) { m_strName = name; }
	virtual ~Component(){}
	virtual void Add(Component * cmpt) = 0;		//添加构件
	virtual void Remove(Component * cmpt) = 0;	//删除构件
	virtual Component* GetChild(int index) = 0;	//获取构件
	virtual void Operation(int indent) = 0;		//显示构件
	virtual string GetName() { return m_strName; }
private:
	Component();	//禁用

protected:
	string m_strName;
};