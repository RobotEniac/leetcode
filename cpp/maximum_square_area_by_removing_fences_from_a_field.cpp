// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2026/01/16 10:31:16
// Description: https://leetcode.cn/problems/maximum-square-area-by-removing-fences-from-a-field/description/?envType=daily-question&envId=2026-01-16

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>

#include "util.h"

using namespace std;

unordered_set<int> lens(int e, vector<int>& f) {
    unordered_set<int> s;
    sort(f.begin(), f.end());
    for (int i = 0; i < f.size(); ++i) {
        s.insert(f[i]-1);
        for (int j = i+1; j < f.size(); ++j) {
            s.insert(f[j] - f[i]);
        }
    }
    s.insert(e-1);
    for (int i = 0; i < f.size(); ++i) {
        s.insert(e - f[i]);
    }
    return s;
}

int maximizeSquareArea(int m, int n, vector<int> &hFences, vector<int> &vFences) {
    const static int MOD = 1e9+7;
    int64_t area = 0;
    unordered_set<int> hlens = lens(m, hFences);
    unordered_set<int> vlens = lens(n, vFences);
    int ms = 0;
    for (auto it = hlens.begin(); it != hlens.end(); ++it) {
        if (vlens.find(*it) != vlens.end()) {
            if (*it > ms) {
                ms = *it;
            }
        }
    }
    return ms == 0 ? -1 : ((int64_t)ms * ms % MOD);
}

int main(int argc, char *argv[]) {
    vector<int> h = {2};
    vector<int> v = {8,6,5,4};
    cout << maximizeSquareArea(3,9,h,v) << endl;
}
