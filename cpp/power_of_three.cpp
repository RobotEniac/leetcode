// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/12/13 10:51:57
// Description: https://leetcode-cn.com/problems/power-of-three/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

bool isPowerOfThree(int n)
{
    while (n && n % 3 == 0) {
        n = n / 3;
    }
    return n == 1;
}

int main(int argc, char *argv[]) {
    cout << boolalpha << isPowerOfThree(atoi(argv[1])) << endl;
}
