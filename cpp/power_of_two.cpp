// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/10/11 14:47:28
// Description: https://leetcode-cn.com/problems/power-of-two/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

bool isPowerOfTwo(int n) {
    if (n < 0) {
        if (n == INT_MIN) {
            return true;
        }
        n = -n;
    }
    if (n < 3) {
        return true;
    }
    while (n >= 3) {
        if (n & 0x1) {
            return false;
        }
        n = n >> 1;
    }
    return true;
}

int main(int argc, char *argv[]) {
    cout << "hello world" << endl;
}
