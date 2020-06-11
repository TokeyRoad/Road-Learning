#include "FlyWeightFactory.h"

map<string, IPlayer*> PlayerFactory::m_map = map<string, IPlayer*>();

static string s_PlayerType[] = { "T", "CT" };
static string s_Weapon[] = { "AK-47", "M4A1", "AWM", "98k" };

int main() {
	srand((unsigned)time(NULL));

	int TypeCount = CountArray(s_PlayerType);
	int WeaponCount = CountArray(s_Weapon);

	for (int i = 0; i < 10; i++) {
		int TypeIndex = rand() % TypeCount;
		int WeaponIndex = rand() % WeaponCount;

		IPlayer* p = PlayerFactory::GetPlayer(s_PlayerType[TypeIndex]);
		if (p != NULL) {
			p->assignWeapon(s_Weapon[WeaponIndex]);
			p->misson();
		}
	}

	system("pause");
	return 0;
}