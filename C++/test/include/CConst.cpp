//
// Created by Tokey on 2022/5/11.
//

#include "CConst.h"

#define Print(A) std::cout << #A << ":" << (A) << std::endl

//配合CTest.cpp中一起使用
extern const int max_index;
extern int max_int;

X f5() { return X(2); }
const X f6() { return X(); }
void f7(X& x) { x.modify(); }

const int* const w() {
    static int is = 10;
    return &is;
}

void CConst::Const() {
    const int c = 10;   //不会分配内存，直接保存到符号表
    float fc[c];
    //由于这里是个数组（聚合），所以编译器会分配内存，编译期 值不可见，所以值不能作为常量使用
    const int a[] = {1, 2, 3, 4};
    //所以这里定义数组不合法 编译错误
    // float f[a[2]];   //illegal
    //由于这里是个聚合，所以编译器会分配内存，编译期 值不可见，所以值不能作为常量使用
    struct S {int i; int j;};
    const S s[] = {{1,2}, {3,4}};
    // double d[s[1].j];
    // std::cout << max_index << std::endl;
    Print(max_index);
    // std::cout << max_int << std::endl;
    Print(max_int);
}

void CConst::ConstPtr() {
    int d1 = 100;
    int d2 = 200;
    const int* p1;   //p1是一个指向 const int的指针：指针可变 指向的数据（*p1）不可变
    p1 = &d1;
    p1 = &d2;        //指针p1本身不是const 可变
    // *p1 = 12;     //illegal
    Print(*p1);
    // const int 的指针 不能通过*p1修改数据 但是可以通过内存修改数据
    memset((void*)p1, 1, sizeof(int));    //以字节为单位set
    // memset(&d2, 1, sizeof(int));    //以字节为单位set
    // 0000 0001 0000 0001 0000 0001 0000 0001 = 16843009
    Print(*p1);

    int d3 = 300;
    int d4 = 400;
    int const* p2;  //与p1读法一致 含义也完全相同
    /// 所以 const int* p1 等价于 int const* p1 更推荐第一种写法
    p2 = &d3;
    p2 = &d4;
    // *p2 = 350;   //illegal

    int d5 = 500;
    int d6 = 600;
    int* const p3 = &d5;    //p3是一个指向int的const指针,必须在定义的时候完成初始化：指针不可变，指向的数据（*p3）可变
    // p3 = &d6;    //illegal
    Print(*p3);
    *p3 = 550;
    Print(*p3);

    const int d7 = 700;
    // int* p4 = (int*)&d7;    //legal 不推荐 这样相当于破坏了const 后面可以直接用*p4修改d7
    // *p4 = 750;

    char* p5 = "hello 123!";    //这两种写法生成效果一致，但是平时推荐第二种写法
    char p6[] = "hello 123!";
    Print(sizeof(p5));  //这里打印的是指针的大小
    Print(strlen(p5));
    Print(sizeof(p6));  //这里打印的是char数组的大小 含结束符
    Print(strlen(p6));

    int d8 = 800;
    const int * const p7 = w();
    const int * p8 = w();   //legal 只有当w()作为左值的时候 第二个const才会生效（illegal）
    // w() = &d8;       //illegal
}

void CConst::ConstRef() {
    f5() = X(1);  //legal 但是有错误 cout:1 2
    f5().modify();
    // f7(f5());    //warning
    // f7(f6);      //illegal

}
