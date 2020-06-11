#include "Composite.h"
#include "Leaf.h"


int main() {
	Component* pRoot = new Composite("World");
	Component* pPartLeft = new Composite("Client");
	pPartLeft->Add(new Leaf("JavaScript"));
	pPartLeft->Add(new Leaf("Html"));
	pRoot->Add(pPartLeft);

	Component* pPartRight = new Composite("Server");
	pPartRight->Add(new Leaf("C++"));
	pPartRight->Add(new Leaf("Java"));
	pPartRight->Add(new Leaf("PHP"));
	pRoot->Add(pPartRight);
	pRoot->Add(new Leaf("All Stack"));
	Leaf* pNLeaf = new Leaf("None");
	pRoot->Add(pNLeaf);

	pRoot->Operation(1);
	cout << "*********************************" << endl;
	pRoot->Remove(pNLeaf);
	pRoot->Operation(1);

	DEL(pRoot);

	system("pause");
	return 0;
}