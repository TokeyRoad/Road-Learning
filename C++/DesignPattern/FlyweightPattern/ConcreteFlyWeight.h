#pragma once
#include "FlyWeight.h"

class Terrorist :public IPlayer {
public:
	Terrorist() {
		m_task = "Plant a bomb";
	}

	virtual void assignWeapon(string weapon) {
		m_weapon = weapon;
	}
	
	virtual void misson() {
		cout << "Terrorist with weapon " << m_weapon << ",Task is " << m_task << endl;
	}

};

class CounterTerrorist :public IPlayer {
public:
	CounterTerrorist() {
		m_task = "Diffuse bomb";
	}

	virtual void assignWeapon(string weapon) {
		m_weapon = weapon;
	}

	virtual void misson() {
		cout << "CounterTerrorist with weapon " << m_weapon << ",Task is " << m_task << endl;
	}
};