// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2024/01/19 11:04:28
// Description: https://leetcode.cn/problems/pass-the-pillow/description/?envType=daily-question&envId=2024-01-17

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int passThePillow(int n, int time) {
    int a = n + n-2;
    int r = time % a;
    cout << n << ", " << a << ", " << r << endl;
    if (r < n) {
        return r + 1;
    } else {
        return n+n-r-1;
    }
}

int main(int argc, char *argv[]) {
    cout << passThePillow(4, 5) << endl;
    cout << passThePillow(3, 2) << endl;
    cout << passThePillow(2, 341) << endl;
}
