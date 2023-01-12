// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2022/10/28 16:28:42
// Description: https://leetcode.cn/problems/oPs9Bm/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

vector<int> slice(vector<int> a, int s, int e) {
    vector<int> ret;
    if (s >= a.size()) {
        return ret;
    }
    for (int i = s; i < e; ++i) {
        if (i >= a.size()) {
            return ret;
        }
        ret.push_back(a[i]);
    }
    return ret;
}

void dfs(vector<int> &cap, int k, vector<int>& a, int i, int &cnt) {
    cout << a << endl;
    if (i == cap.size()) {
        if (k == a[0]) {
            ++cnt;
        };
        return;
    }
    if (a[0] > k || a[a.size()-1] < k) {
        return;
    }
    vector<int> s = slice(a, cap[i]-1, a.size() - 1);
    dfs(cap, k, s, i+1, cnt);
    vector<int> q = slice(a, 0, a.size() - cap[i]);
    dfs(cap, k, q, i+1, cnt);
    return;
}

int securityCheck(vector<int>& cap, int k) {
    int n = 0;
    for (int i = 0; i < cap.size(); ++i) {
        n += cap[i];
    }
    ++n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        a[i] = i+1;
    }
    int cnt = 0;
    dfs(cap, k, a, 0, cnt);
    return cnt;
}

int main(int argc, char *argv[]) {
    vector<int> cap = {4,3,2,2};
    cout << securityCheck(cap, 6) << endl;
}
