#include "../Common/head.h"

class Singleton {
public:
	static Singleton* Instance() {
		if (_single == nullptr) {
			_single = new Singleton();
		}
		return _single;
	}
private:
	Singleton() {}
	~Singleton(){}
	//Singleton(const Singleton&);
	//Singleton& operator=(const Singleton&) = delete;
	static Singleton* _single;
};

Singleton* Singleton::_single = nullptr;

int main() {
	Singleton* p1 = Singleton::Instance();
	Singleton* p2 = Singleton::Instance();
	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;

	system("pause");
	return 0;
}
