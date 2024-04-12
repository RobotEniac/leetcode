// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2024/03/28 17:42:06
// Description: https://leetcode.cn/problems/count-odd-numbers-in-an-interval-range/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int countOdds(int low, int high) {
    if (low & 0x1 == 1 && high & 0x1 == 1) {
        return (high-low+1)/2+1;
    }
    return (high-low+1)/2;
}

int main(int argc, char *argv[]) {
    cout << "hello world" << endl;
}
