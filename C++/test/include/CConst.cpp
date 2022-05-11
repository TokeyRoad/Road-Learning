//
// Created by Tokey on 2022/5/11.
//

#include "CConst.h"
#include <iostream>

//配合CTest.cpp中一起使用
extern const int max_index;
extern int max_int;

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
    std::cout << max_index << std::endl;
    // std::cout << max_int << std::endl;
}

void CConst::ConstPtr() {
    // int i = 10;
    // const int* v = &i;
    // i = 100;
}
