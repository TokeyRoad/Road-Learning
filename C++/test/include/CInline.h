//
// Created by Tokey on 2022/5/15.
//

#ifndef TEST_CINLINE_H
#define TEST_CINLINE_H
#include <iostream>
#include <fstream>

class CInline {
public:
    void DefineError();     // 非内联  内联成员函数定义部分不能放在cpp
    // 隐式内联 定义在class内 不需要声明inline
    void InlineTest_1() {std::cout << "InlineTest1" << std::endl; }
    void InlineTest_2();     // 显式内联 定义前声明inline 且定义在头文件
};

// 这里增加inline 表明内联
inline void CInline::InlineTest_2() { std::cout << "InlineTest2" << std::endl; }

#endif //TEST_CINLINE_H
