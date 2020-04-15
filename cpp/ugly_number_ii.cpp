// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/02/18 23:30:42
// Description: https://leetcode.com/problems/ugly-number-ii/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int nthUglyNumber(int n) {
    int i2 = 0;
    int i3 = 0;
    int i5 = 0;
    vector<int> l;
    l.push_back(1);
    while (l.size() < n) {
        int m2 = l[i2] * 2;
        int m3 = l[i3] * 3;
        int m5 = l[i5] * 5;
        int mm = min(m2, min(m3, m5));
        l.push_back(mm);
        if (mm == m2) ++i2;
        if (mm == m3) ++i3;
        if (mm == m5) ++i5;
    }
    cout << l << endl;
    return *l.rbegin();
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    nthUglyNumber(n);
}
