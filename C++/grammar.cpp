/*************************************************************************
	> File Name: grammar.cpp
	> Author: Tokey
	> Mail: TokeyRoad@163.com 
	> Created Time: 2020年03月17日 星期二 11时19分27秒
 ************************************************************************/

#include<iostream>

static void autoValue();
static void autoPointer();

int main(){
	autoValue();
	autoPointer();
	return 0;
}

static void autoValue(){
	auto age = 10;
	auto name = std::string("Yt");
	auto height = 170.0f;
	auto weight = 70.0f;
	std::cout << "age is type " << typeid(age).name() << std::endl;
	std::cout << "name is type " << typeid(name).name() << std::endl;
	std::cout << "height is type " << typeid(height).name() << std::endl;
	std::cout << "weight is type " << typeid(weight).name() << std::endl;
}

static void autoPointer(){
	auto age = new int(10);
	auto name = "Yt";
	// const char* name = "Yt";
	auto height = new float(160.0f);
	auto weight = new double(72.0f);

	std::cout << "age is type " << typeid(age).name() << std::endl;
	std::cout << "name is type " << typeid(name).name() << std::endl;
	std::cout << "height is type " << typeid(height).name() << std::endl;
	std::cout << "weight is type " << typeid(weight).name() << std::endl;

	delete age;
	delete height;
	delete weight;
	
}


