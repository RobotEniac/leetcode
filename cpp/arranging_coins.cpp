// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2024/02/23 21:05:10
// Description: https://leetcode.cn/problems/arranging-coins/

#include <math.h>

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int arrangeCoins(int n) {
    int x = sqrt(n*2);
    if (x * (x+1)/2 > n) {
        return x - 1;
    }
    return x;
}

int main(int argc, char *argv[]) {
    for (int i = 0; i < 100; ++i) {
        cout << i << ":" << arrangeCoins(i) << endl;
    }
}
