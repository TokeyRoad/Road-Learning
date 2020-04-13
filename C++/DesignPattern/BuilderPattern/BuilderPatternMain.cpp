#include "Director.h"
#include "ConcreteBuild.h"

int main() {
	Director* pDir = new Director();
	MacBuilder* pMac = new MacBuilder();
	ASUSBuilder* pAsus = new ASUSBuilder();
	pDir->Create(pMac);
	pDir->Create(pAsus);

	Computer* Mac = pMac->GetResult();
	Computer* Asus = pAsus->GetResult();

	cout << "-------MAC---------" << endl;
	cout << Mac->GetCPU() << endl;
	cout << Mac->GetRam() << endl;
	cout << Mac->GetMainBoard() << endl;
	cout << Mac->GetVideoCard() << endl;

	cout << "-------ASUS---------" << endl;
	cout << Asus->GetCPU() << endl;
	cout << Asus->GetRam() << endl;
	cout << Asus->GetMainBoard() << endl;
	cout << Asus->GetVideoCard() << endl;

	DEL(pDir);
	DEL(pMac);
	DEL(pAsus);
	DEL(Mac);
	DEL(Asus);

	system("pause");
	return 0;
}