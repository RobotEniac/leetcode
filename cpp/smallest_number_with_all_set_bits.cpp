// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/10/29 17:25:20
// Description: https://leetcode.cn/problems/smallest-number-with-all-set-bits/description/?envType=daily-question&envId=2025-10-29

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int smallestNumber(int n) {
    int ret = 0;
    while (n != 0) {
        n = n >> 1;
        ret = (ret << 1) | 0x1;
    }
    return ret;
}

int main(int argc, char *argv[]) {
    cout << smallestNumber(5) << endl;
}
