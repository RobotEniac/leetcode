// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/11/05 20:45:24
// Description: https://leetcode.cn/problems/reordered-power-of-2/?envType=daily-question&envId=2025-10-29

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

string itos(int64_t a) {
    string s;
    while (a != 0) {
        s.push_back(a % 10 + '0');
        a = a / 10;
    }
    cout << s << endl;
    sort(s.begin(), s.end());
    return s;
}

bool reorderedPowerOf2(int n) {
    if (n == 0) {
        return true;
    }
    string ns = itos(n);
    for (int i = 1; i < 32; ++i) {
        if (itos(1<<i) == ns) {
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
    cout << boolalpha << reorderedPowerOf2(1<<30) << endl;
}
