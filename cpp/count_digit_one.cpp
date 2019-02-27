// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/02/23
// Description: 

#include <iostream>
#include <vector>

#include "util.h"

using namespace std;

int countDigitOne(int n) {
    int count = 0;
    for (int64_t i = 1; i <= n; i *= 10) { // 防止n = INT_MAX 时，i溢出
        int a = n / i;
        int b = n % i;
        if (a % 10 == 0) { // e.g. n = 304, i = 10: (0~2)1(0~9)
            count += (a / 10) * i;
        } else if (a % 10 == 1) { // e.g. n = 314, i = 10: (0~2)1(0~9) + (0~4)
            count += (a / 10) * i + b + 1;
        } else { // e.g. n = 324, i = 10: (0~3)1(0~9)
            count += (a / 10 + 1) * i;
        }

        // simplify:
        // count += (a + 8) / 10 * i + (a % 10 == 1) * (b + 1)
    }
    return count;
}

