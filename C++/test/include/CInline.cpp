//
// Created by Tokey on 2022/5/15.
//

#include "CInline.h"

#define RAND(x) (((x) > 5 && (x) < 10) ? (x) : 0)

void CInline::DefineError() {
    // ofstream 如果文件不存在 会自动创建文件
    std::ofstream out("macro.out");
    for(int i = 4; i < 11; ++i) {
        int a = i;
        out << "a = " << a << std::endl << '\t';
        out << " RAND(++a) = " << RAND(++a) << std::endl;
        out << "\t a = " << a << std::endl;
    }
}
