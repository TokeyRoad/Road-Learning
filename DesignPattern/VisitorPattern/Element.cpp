#include "Element.h"

void ConcreteElementA::Accept(Visitor * vis)
{
	vis->VisitConcreteElementA(this);
	std::cout << "visiting ConcreteElementA..." << std::endl;
}

void ConcreteElementB::Accept(Visitor * vis)
{
	vis->VisitConcreteElementB(this);
	std::cout << "visiting ConcreteElementA..." << std::endl;
}
