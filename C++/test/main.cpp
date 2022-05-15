#include <iostream>
#include <stdio.h>
#include "CTest.h"
#include "CConst.h"
#include "CInline.h"


int main() {
    CTest t;
    X x;
    CInline ci;
    ci.DefineError();
    // x.testConst();
    // t.Cast();
    // char ip[65] = {0};
    // t.GetAddrByHost("www.baidu.com", sizeof(ip), ip);
    // std::cout << sizeof(ip) << std::endl;
    // std::cout << ip << std::endl;
    return 0;
}
