#include "../Common/head.h"

class Shape {
public:
	virtual void draw() = 0;
};

class Circle :public Shape{
public:
	void draw() {
		cout << "draw a circle!" << endl;
	}
};

class Square :public Shape {
public:
	void draw() {
		cout << "draw a square!" << endl;
	}
};
//*第一种方案------简单工厂模式*/
//class Factory {
//public:
//	Shape* CreateShape(int type) {
//		switch (type)
//		{
//		case define::Type::circle: {
//			return new Circle();
//			break;
//		}
//		case define::Type::square: {
//			return new Square();
//			break;
//		}
//		default:
//			break;
//		}
//		return NULL;
//	}
//};

//*第二种方案------工厂模式*/
class Factory {
public:
	virtual Shape* CreateShape() = 0;
};

class CircleFactory :public Factory {
public:
	Circle* CreateShape() {
		return new Circle();
	}
};

class SquareFactory :public Factory {
public:
	Square* CreateShape() {
		return new Square();
	}
};

//int main() {
//
//	Factory f;
//	Shape* c = f.CreateShape(define::Type::circle);
//	c->draw();
//	delete c;
//	c = NULL;
//
//	CircleFactory cf;
//	SquareFactory sf;
//	Circle* c = cf.CreateShape();
//	c->draw();
//	Square* s = sf.CreateShape();
//	s->draw();
//	delete c;
//	c = NULL;
//	delete s;
//	s = NULL;
//
//
//	system("pause");
//	return 0;
//}


