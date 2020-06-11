#include "Element.h"
#include "Visitor.h"

int main() {
	Visitor* vis = new ConcreteVisitorA();
	Element* elm = new ConcreteElementA();

	elm->Accept(vis);

	DEL(elm);
	DEL(vis);

	system("pause");
	return 0;
}