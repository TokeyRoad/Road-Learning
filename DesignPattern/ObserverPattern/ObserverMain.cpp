#include "ConcreteSubject.h"
#include "ConcreteObserver.h"

int main() {
	srand((unsigned)time(NULL));
	ConcreteSubject* pSubject = new ConcreteSubject();
	IObserver* pServer1 = new ConcreteObserver("Jack");
	IObserver* pServer2 = new ConcreteObserver("Rose");

	pSubject->Register(pServer1);
	pSubject->Register(pServer2);

	pSubject->SetPrice(11);
	pSubject->Notify();
	cout << "********************" << endl;

	pSubject->Destory(pServer1);
	pSubject->SetPrice(12);
	pSubject->Notify();

	DEL(pSubject);
	DEL(pServer1);
	DEL(pServer2);

	system("pause");
	return 0;
}