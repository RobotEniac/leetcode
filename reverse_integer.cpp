// =====================================================
//       Filename:  reverse_integer.cpp
//         Author:  roboteniac <>
//        Created:  2017/05/03
//    Description:  
//    Copyright (c) 2017, roboteniac, All rights reserved. 
// =====================================================

#include <stdlib.h>
#include <iostream>

int reverse(int x) {
    if (x == 0) {
        return x;
    }
    int sign = x > 0 ? 1 : -1;
    x = x * sign;
    int ret = 0;
    while (x > 0) {
        if (ret * 10 / 10 != ret) {
            return 0;
        }
        ret = ret * 10 + x % 10;
        x = x / 10;
    }
    return ret * sign;
}

int main(int argc, char *argv[]) {
    int x = atoi(argv[1]);
    std::cout << "x = " << x << ", reverse(x) = "
        << reverse(x) << std::endl;
}

