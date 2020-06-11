#pragma once
#include "ConcreteFlyWeight.h"


class PlayerFactory{
public:
	static IPlayer* GetPlayer(string type) {
		if (m_map.find(type) != m_map.end()) {
			return m_map[type];
		}
		else {
			if (type == "T") {
				IPlayer* p = new Terrorist();
				cout << "Terrorist created" << endl;
				m_map.insert(make_pair(type, p));
				return p;
			}
			else if (type == "CT") {
				IPlayer* p = new CounterTerrorist();
				cout << "CounterTerrorist created" << endl;
				m_map.insert(make_pair(type, p));
				return p;
			}
			else {
				cout << "error type" << endl;
				return NULL;
			}
		}
	}
private:
	static map<string, IPlayer*> m_map;
};