#include <iostream>

struct Foo {
	int a;
	char c;
	float f;
};

struct Empty{};

struct alignas(64) Empty64 {};
//0会被忽略
struct alignas(0) BB {};

struct alignas(1) Double {
	double d;
};

struct Obj {
	char a;
	int b;
};

//alignof 
int s_obj = sizeof(Obj);	//8
int a_obj = alignof(Obj);	//4

void alignInfo() {
	std::cout << "Alignment of" "\n"
		"- char					:" << alignof(char)			<< "\n"		//1
		"- pointer				:" << alignof(int*)			<< "\n"		//8 4
		"- empty class			:" << alignof(Empty)		<< "\n"		//1
		"- class Foo			:" << alignof(Foo)			<< "\n"		//4
		"- alignas(64) Empty	:" << alignof(Empty64)		<< "\n"		//64
		"- alignas(1) Double	:" << alignof(Double)		<< "\n";	//8(WIN下编译报错)
}

#include <iso646.h>
void AND() {
	//and 等价于 &
	int a = 10;
	int b = 20;
	b and_eq a;
	//等价于 b &= a;
	//等价于 b = b & a;
}

void showBitAndor() {
	auto a = 3L;
	auto b = 4;
	auto c = a bitand b;	//等价于 &
	auto d = a bitor b;		//等价于 |
}

int fact(int n) { return n <= 1 ? 1 : (n * fact( n - 1)); }

constexpr int factorial(int n) { return n <= 1 ? 1 : (n * factorial( n - 1)); }

void testConstCast(){
	const int j = 3;	//j is declared const
	//const int*
	int* pj = const_cast<int*>(&j); 
	*pj = 4;			//undefined behavior!
}

struct A { double x;};
void testDecl(){
	const A* a = new A{ 0 };
	auto aa = a->x;
	decltype(a->x) y;		//double
	auto& cc = y;
	decltype((a->x)) z = y;	//double&
}

template<typename T, typename U>
auto add(T a, U b) -> decltype(a+b){
	return a+b;
}

/* error cant compile
 * decltype(a+b) add(T a, U b){
 *		 return a+b;
 * }
 */


void testDecltype(){
	auto cc = add(1,3);			//cc int
	auto dd = add(1.0, 3);		//dd double
}

struct Base{virtual ~Base(){}};

struct Derived : Base {
	virtual void name(){}
};

void TestDyn(){
	Base *b1 = new Base;
	if(Derived *d = dynamic_cast<Derived*>(b1)){		//fail
		std::cout << "downcast from b1 to d successful\n";
		d->name();	//safe to call
	}

	Base *b2 = new Derived;
	if(Derived *d = dynamic_cast<Derived *>(b2)){		//success
		std::cout << "downcast from b2 to d successful\n";
		d->name();	//safe to call
	}

	Base bb;
	//fail throw bad_cast exception
	//Derived& cc = dynamic_cast<Derived&>(bb);
	delete b1;
	delete b2;
}

struct A{
	A(int){}
	A(int,int){}
	operator int() const { return 0;}
};

struct B{
	explicit B(int){}
	explicit B(int,int){}
	explicit operator int() const { return 0;}
};

void TestExpl(){
	A a1 = 1;		// A a1 = A(1);
	// B b1 = 1;	//error
	A a2(2);
	B b2(2);		//OK
	A a3 = {4,5};	// A a3 = A{4,5};  A{4,5};
	// B b3 = {4,5};//error
	int na1 = a1;	//OK
	//int na1 = b2;	//error
	int na2 = static_cast<int>(a1);
	int nb2 = static_cast<int>(b2);
	A a4 = (A)1;
	B b4 = (B)1;
}

template<typename T, typename U>
void func(T t, U u){
	t(u);
}

void nullPointer(int* a){
	std::cout << "i'm a pointer\n'";
}

void testNullPointer(){
	nullPointer(0);
	nullPointer(NULL);	//(void*)0
	nullPointer(nullptr);// std::nullptr_t
	func(nullPointer, nullptr);	//OK
	func(nullPointer, 0);		//error 
	func(nullPointer, NULL);	//error
}

struct AAA{
	int operator &(){
		return 10;
	}
};

void testOperator(){
	AAA a;
	auto address = &a;
}

void testReinter(){
	int a = 1;
	auto p = reinterpret_cast<char*>(&a);
	if(p[0] == 1) std::cout << "the system is little endian\n";
	else std::cout << "the system is big endian\n";
	// reinterpret_cast
	// static_cast
	// const_cast
	// dynamic_cast
	
	// c like cast
	auto pp = (char*)(&a);
	const AAA bb;
	auto pbb = const_cast<AAA*>(&bb);
	auto cbb = (AAA*)(&bb);
	int c = 100;
	auto cc = static_cast<char>(c);
	auto ccc = (char)c;
}

static int globalA = 0;
void printStatic(){
	static int localStatic = 0;
	++localStatic;
	std::cout << localStatic << std::endl;
}

struct S{
	static int s;
};
//sizeof(S) = 1 // S == empty

int S:s = 10;

void testStaticAssert(){
	static_assert((sizeof(int) == 4) && "only work for int for 32 bit");
	int a = 4;
	int b = 5;
	assert(a == b);
}

typedef unsigned long ulong;
class testTypedef{
	typedef std::map<int, ulong> Group;
	Group a;
	void aa(){
		// std::map<int, ulong>::itertor iter = a.find(10);
		// Group::iteator iter = a.find(10);
		auto iter = a.find(10);
	}
};



template <int N>
struct NN{
	void print(){ std::cout << N << std::endl; }
};


int main() {
	//alignInfo();
	auto aa = fact(4);
	auto bb = factorial(4);
	std::cout << aa << "|" << bb << std::endl;
	TestDyn();
	return 0;
}
