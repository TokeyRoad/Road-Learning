//
// Created by Tokey on 2022/5/11.
//

#ifndef TEST_CCONST_H
#define TEST_CCONST_H
#include <iostream>

class CConst {
public:
    void Const();
    void ConstPtr();
    void ConstRef();
};

class X {
public:
    X(int ii = 0) { std::cout << ii << std::endl; i = ii;}
    void modify() { i++;}
private:
    int i;
};

#endif //TEST_CCONST_H
