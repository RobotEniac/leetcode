// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/08/06 16:08:36
// Description: https://leetcode.com/problems/combination-sum-iii/

#include <iostream>
#include <vector>
#include <string>
#include <bitset>

#include "util.h"

using namespace std;

int board[9] = {1,2,3,4,5,6,7,8,9};

vector<int> cal(int k, int n, uint32_t a) {
    vector<int> ret;
    if (k * (k+1) / 2 > n || k * (19 - k) / 2 < n) {
        return ret;
    }
    bitset<9> bs(a);
    if (bs.count() != k) {
        return ret;
    }
    int sum = 0;
    for (int i = 0; i < 9; ++i) {
        sum += bs[i] * board[i];
    }
    if (sum == n) {
        for (int i = 0; i < 9; ++i) {
            if (bs[i]) {
                ret.push_back(board[i]);
            }
        }
    }
    return ret;
}

vector<vector<int> > combinationSum3(int k, int n) {
    vector<vector<int> > ret;
    if (k <= 0 || k > 9) {
        return ret;
    }
    if (k*(k+1)/2 > n || k * (19 - k) / 2 < n) {
        return ret;
    }
    int N = (1 << 9);
    for (int i = 1; i < N; ++i) {
        vector<int> t = cal(k, n, i);
        if (!t.empty()) {
            ret.push_back(t);
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    int k = atoi(argv[1]);
    int n = atoi(argv[2]);
    vector<vector<int> > v = combinationSum3(k, n);
    cout << "combine(" << k << ", " << n << "):\n";
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }
}
