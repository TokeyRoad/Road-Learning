#pragma once
#include "RealSubject.h"

class ProxySubject {
public:
	~ProxySubject(){
		DEL(Cmcc);
		DEL(Cucc);
		DEL(Cnet);
	}
	void Recharge(string type, int money) {
		if (type == "CMCC") {
			if (Cmcc == NULL) {
				Cmcc = new CMCC();
			}
			Cmcc->Recharge(money);
		}
		else if (type == "CUCC") {
			if (Cucc == NULL) {
				Cucc = new CUCC();
			}
			Cucc->Recharge(money);
		}
		else if (type == "CNET") {
			if (Cnet == NULL) {
				Cnet = new CNET();
			}
			Cnet->Recharge(money);
		}
		else {
			cout << "stupid" << endl;
		}
	}
private:
	CMCC* Cmcc;
	CUCC* Cucc;
	CNET* Cnet;
};