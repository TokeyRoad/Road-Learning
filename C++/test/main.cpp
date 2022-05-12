#include <iostream>
#include <stdio.h>
#include "CTest.h"
#include "CConst.h"


int main() {
    CTest t;
    CConst ct;
    ct.ConstRef();
    // t.Cast();
    // char ip[65] = {0};
    // t.GetAddrByHost("www.baidu.com", sizeof(ip), ip);
    // std::cout << sizeof(ip) << std::endl;
    // std::cout << ip << std::endl;
    return 0;
}
