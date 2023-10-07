// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/06/26 15:36:00
// Description: https://leetcode.cn/problems/find-the-losers-of-the-circular-game/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

vector<int> circularGameLosers(int n, int k) {
    vector<bool> v(n, false);
    int i = 0;
    int t = 0;
    while (!v[t]) {
        cout << t << ", ";
        v[t] = true;
        ++i;
        t = (t + i * k) % n;
    }
    cout << endl;
    vector<int> ret;
    for (int i = 0; i < n; ++i) {
        if (!v[i]) {
            ret.push_back(i+1);
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    cout << circularGameLosers(n, k) << endl;
}
