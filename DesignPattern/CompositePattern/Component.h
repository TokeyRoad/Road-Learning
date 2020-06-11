#pragma once
#include "../Common/head.h"


/*
Component�����󹹼���:ΪҶ�ӹ�������������������ӿڣ����԰����������๲����Ϊ��������ʵ�֣��ڳ��󹹼��У������˷��ʼ������ӹ����Ľӿڣ����磺Add(),Remove(),GetChild()��
Leaf(Ҷ�ӹ���)��Ҷ�ӽڵ�û���ӽڵ㣬��ʵ����Component�ж������Ϊ�����ڷ��ʼ������ӹ����Ľӿڣ�����ͨ���쳣�ȷ�ʽ����
Composite�������������������ڵ�����ӽڵ㣨������Ҷ�ӹ�����Ҳ���������������������ṩ��һ���������ڴ洢Ҷ�ӹ�����ʵ����Componnet�ж������Ϊ���������ʺ͹����ӹ����Ľӿڣ�����ҵ�񷽷��п��Եݹ����Ҷ�ӹ�����ҵ�񷽷�

͸�����ģʽ��
	��Componnet�ж��������ڷ��ʺ͹����ӹ����Ľӿڣ��������ĺô���ȷ�����еĹ����඼������ͬ�Ľӿڡ�
	��Client������Leaf��Composite���ṩ�ĵĽӿ���һ�µ�



*/



class Component {
public:
	Component(string name) { m_strName = name; }
	virtual ~Component(){}
	virtual void Add(Component * cmpt) = 0;		//��ӹ���
	virtual void Remove(Component * cmpt) = 0;	//ɾ������
	virtual Component* GetChild(int index) = 0;	//��ȡ����
	virtual void Operation(int indent) = 0;		//��ʾ����
	virtual string GetName() { return m_strName; }
private:
	Component();	//����

protected:
	string m_strName;
};