// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/05/11 19:31:55
// Description: https://leetcode.com/problems/bulb-switcher/

#include <iostream>
#include <vector>
#include <string>
#include <set>

#include "util.h"

using namespace std;

int divends(int x) {
    if (x == 1) {
        return 1;
    }
    set<int> m;
    for (int i = 1; i <= x / 2; ++i) {
        if (x % i == 0) {
            m.insert(i);
            m.insert(x / i);
        }
    }
    cout << x << ": " << m << endl;
    return m.size();
}

int bulbSwitch(int n) {
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += (divends(i) % 2);
    }
    return cnt;
}

int bulbSwitch2(int n) {
    return sqrt(n);
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    cout << bulbSwitch(n) << endl;
}
