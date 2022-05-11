//
// Created by Tokey on 2022/5/9.
//

#include "CTest.h"

// 错误写法  const想要给外部使用，必须使用extern明确的转为外部连接
// 默认const常量 仅仅是个内部连接并'可能'没有内存空间，声明为extern时就必定会分配内存
extern const int max_index = 100;
// extern const int MAX_SIZE = 100;
// 由于分配了内存 所以编译期 值不可见 所以下面的使用是错误的
// float d[MAX_SIZE];

// 正确写法 非const全局变量 仅需要外部使用时声明extern即可
int max_int = 200;

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
