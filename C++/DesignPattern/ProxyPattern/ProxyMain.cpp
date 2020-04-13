#include "ProxySubject.h"

string m_NetType[] = { "CMCC","CUCC","CNET" };

int main() {
	srand((unsigned)time(NULL));
	ProxySubject* p = new ProxySubject();
	for (int i = 0; i < m_NetType->size(); i++) {
		p->Recharge(m_NetType[i], rand() % 100);
	}
	DEL(p);
	system("pause");
	return 0;
}