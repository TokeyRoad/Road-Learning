//
// Created by Tokey on 2022/5/11.
//

#ifndef TEST_CCONST_H
#define TEST_CCONST_H
#include <iostream>

class CConst {
public:
    CConst(const int i);
    void Const();
    void ConstPtr();
    void ConstRef();
    void SetInt(int i);
    int GetInt() const;

private:
    int m_int;
    mutable int m_mint;
};

class X {
public:
    X(int ii = 0) { std::cout << ii << std::endl; i = ii;}
    void modify() { i++;}
    void testConst();
private:
    int i;
};

#endif //TEST_CCONST_H
