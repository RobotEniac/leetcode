// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2026/01/05 11:24:32
// Description: https://leetcode.cn/problems/maximum-total-damage-with-spell-casting/description/?envType=daily-question&envId=2026-01-04

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

#include "util.h"

using namespace std;

void show(map<int, int> &m) {
    cout << "{";
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << it->first << ":" << it->second << ", ";
    }
    cout << "}\n";
}

void dfs(map<int, int> &m, vector<int> &d, int start, int64_t &mmax, int64_t sum) {
    if (start >= d.size()) {
        return;
    }
    dfs(m, d, start + 1, mmax, sum);
    sum += d[start] * m[d[start]];
    if (sum > mmax)
    {
        mmax = sum;
    }
    int j = 1;
    while (d[start + j] - d[start] < 3)
    {
        ++j;
    }
    dfs(m, d, start + j, mmax, sum);
}

long long maximumTotalDamage(vector<int> &power) {
    map<int, int> m;
    for (int i = 0; i < power.size(); ++i) {
        if (m.find(power[i]) == m.end()) {
            m[power[i]] = 1;
        } else {
            ++m[power[i]];
        }
    }
    vector<int> d;
    for (auto it = m.begin(); it != m.end(); ++it) {
        d.push_back(it->first);
    }
    vector<int64_t> mem(d.size()+1, 0);
    mem[d.size()-1] = d[d.size()-1] * m[d[d.size()-1]];
    show(m);
    for (int i = d.size() - 2; i >= 0; --i) {
       int j = 1;
        while (i+j < d.size() && d[i+j] <= d[i] + 2) {
            ++j;
        }
        int64_t t = d[i] * m[d[i]];
        mem[i] = std::max(mem[i+1], t + mem[i+j]);
        cout << j << ": " << mem << endl;
    }
    return mem[0];
}

int main(int argc, char *argv[]) {
    vector<int> v = {5,9,2,10,2,7,10,9,3,8};
    cout << maximumTotalDamage(v) << endl;
}
