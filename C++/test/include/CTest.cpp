//
// Created by Tokey on 2022/5/9.
//

#include "CTest.h"

void CTest::GetAddrByHost(const char *host, const int size, char *ip)  {
    struct addrinfo *pAddrinfo, hint;
    // gethostbyname(host)
    ZeroMemory(&hint, sizeof(addrinfo));
    hint.ai_family = AF_UNSPEC;
    hint.ai_socktype = SOCK_STREAM;
    int err = getaddrinfo(host, nullptr, nullptr, &pAddrinfo);
    if (err != 0) {
        printf("getaddrinfo:%d %s \n", GetLastError(), strerror(err));
        return;
    }
    // char str[INET6_ADDRSTRLEN] = {0};
    for (auto res = pAddrinfo; res != nullptr; res = res->ai_next) {
        if (res->ai_family == AF_INET) {
            if (nullptr == inet_ntop(AF_INET, &((struct sockaddr_in*)res->ai_addr)->sin_addr,
                                     ip, size)) {
                err = GetLastError();
                printf("inet_ntop error %d %s\n", err, strerror(err));
                return;
            }
            printf("%s\n", ip);
        }
    }
}

void CTest::Cast() {
    {   //static_cast
        int i = 100;
        double d = (double)i;   //old
        double dd = static_cast<double>(i); //new

        void* vp = &i;
        float* f = (float*)vp;  //old
        float* ff = static_cast<float*>(vp); //new
    }
    {   //const_cast
        const int i = 10;
        int* ii = (int*)&i; //old
        int* iii = const_cast<int*>(&i); //new
        // double* d = const_cast<double*>(&i); //compile error
    }
    {   // reinterpret_cast
        // Not recommended
    }
}

void CTest::Typedef() {
    int* x,y;   //x ->int*  but y ->int
    typedef int* IntPtr;
    IntPtr x1, y1;  //x1 ->int* and y1 ->int*
}
