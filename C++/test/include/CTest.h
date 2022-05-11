//
// Created by Tokey on 2022/5/1.
//

#ifndef TEST_CTEST_H
#define TEST_CTEST_H
#include <iostream>
#include <stdio.h>

// #include "winsock.h"
// #include "WinSock2.h"
#include "WS2tcpip.h"
#pragma comment(lib, "ws2_32.lib")


class CTest {
public:
    CTest(){
        WSAData wsaData;
        WSAStartup(MAKEWORD(2,2), &wsaData);
    }
    ~CTest() {
        WSACleanup();
    }

    void GetAddrByHost(const char* host, const int size, OUT char* ip);

    void Cast();

    void Typedef();


private:

};

#endif //TEST_CTEST_H
