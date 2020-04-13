#include "../Common/head.h"

class Shape {
public:
	virtual void draw() = 0;
};

class Circle :public Shape {
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

class Color {
public:
	virtual void Fill() = 0;
};

class Red :public Color {
public:
	void Fill() {
		cout << "this is red" << endl;
	}
};

class Blue :public Color {
public:
	void Fill() {
		cout << "this is blue" << endl;
	}
};

//*第三种方案------抽象工厂模式*/
class Factory {
public:
	virtual Shape* CreateShape() = 0;
	virtual Color* FillColor() = 0;
	static Factory* CreateFactory(int type);
};

class CircleRedFactory :public Factory {
public:
	Circle* CreateShape() {
		return new Circle();
	}
	Red* FillColor() {
		return new Red();
	}
};

class SquareBlueFactory :public Factory {
public:
	Square* CreateShape() {
		return new Square();
	}
	Blue* FillColor() {
		return new Blue();
	}
};

Factory * Factory::CreateFactory(int type) {
	switch (type)
	{
	case define::Type::circle: {
		return new CircleRedFactory();
		break;
	}
	case define::Type::square: {
		return new SquareBlueFactory();
		break;
	}
	default:
		break;
	}
	return NULL;
}

int main() {
	Factory* f = Factory::CreateFactory(define::Type::circle);
	Shape* pc = f->CreateShape();
	Color* cc = f->FillColor();
	pc->draw();
	cc->Fill();
	delete pc, cc;
	pc = NULL;
	cc = NULL;

	Factory* bf = Factory::CreateFactory(define::Type::square);
	Shape* ss = bf->CreateShape();
	Color* sc = bf->FillColor();
	ss->draw();
	sc->Fill();
	delete ss, sc;
	ss = NULL;
	sc = NULL;
	system("pause");
	return 0;
}
