#include "Visitor.h"

void ConcreteVisitorA::VisitConcreteElementA(Element * elm)
{
	std::cout << "i will visit ConcreteElementA..." << std::endl;
}

void ConcreteVisitorA::VisitConcreteElementB(Element * elm)
{
	std::cout << "i will visit ConcreteElementB..." << std::endl;
}

void ConcreteVisitorB::VisitConcreteElementA(Element * elm)
{
	std::cout << "i will visit ConcreteElementA..." << std::endl;
}

void ConcreteVisitorB::VisitConcreteElementB(Element * elm)
{
	std::cout << "i will visit ConcreteElementB..." << std::endl;
}
