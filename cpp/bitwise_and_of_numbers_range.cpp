// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/03/06 22:09:06
// Description: https://leetcode.com/problems/bitwise-and-of-numbers-range/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int rangeBitwiseAnd(int m, int n) {
    int ret = m;
    for (int i = m; i <= n; ++i) {
        ret = ret & i;
    }
    return ret;
}

int main(int argc, char *argv[]) {
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
    cout << "rangeBitwiseAnd(" << m << ", " << n << ") is " << rangeBitwiseAnd(m, n) << endl;
}
