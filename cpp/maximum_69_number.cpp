// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/08/28 17:20:10
// Description: https://leetcode.cn/problems/maximum-69-number/?envType=daily-question&envId=2025-08-27

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int maximum69Number (int num) {
    int i = 0;
    int i6 = -1;
    int a = num;
    while (num != 0) {
        int c = num % 10;
        if (c == 6) {
            i6 = i;
        }
        num /= 10;
        ++i;
    }
    if (i6 != -1) {
        a += 3 * pow(10, i6);
    }
    return a;
}

int main(int argc, char *argv[]) {
    cout << maximum69Number(9669) << endl;
}
