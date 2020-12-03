// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/04/25 12:00:38
// Description: https://leetcode.com/problems/range-sum-query-mutable/

#include <math.h>

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

class NumArray {
public:
    explicit NumArray(vector<int>& nums) 
        : a(nums)
    {
        if (nums.empty()) {
            return;
        }
        int h = (int)ceil(log2(nums.size()));
        int l = 2 * pow(2, h) - 1;
        tree = vector<int>(l, 0);
        build(0, a.size(), 0);
    }

    void update(int i, int val) {
        if (a.empty()) {
            return;
        }
        updateUntil(i, val, 0, a.size(), 0);
    }

    int sumRange(int i, int j) {
        if (a.empty()) {
            return 0;
        }
        return sumUntil(i, j+1, 0, a.size(), 0);
    }

    int mid(int s, int e) { return (s + e) / 2; }

    int build(int as, int ae, int ti);

    int sumUntil(int as, int ae, int ts, int te, int ti);

    void  updateUntil(int i, int val, int ts, int te, int ti);

private:
    vector<int> tree;
    vector<int> a;
};

int NumArray::build(int as, int ae, int ti) {
    if (ae - as == 1) {
        tree[ti] = a[as];
        return a[as];
    }
    int am = mid(as, ae);
    tree[ti] = build(as, am, 2*ti+1) + build(am, ae, 2*ti+2);
    return tree[ti];
}

int NumArray::sumUntil(int as, int ae, int ts, int te, int ti) {
    if (ae <= ts || as >= te) {
        return 0;
    }
    if (as <= ts && ae >= te) {
        return tree[ti];
    }
    int tm = mid(ts, te);
    return sumUntil(as, ae, ts, tm, 2*ti+1) + sumUntil(as, ae, tm, te, 2*ti+2);
}

void NumArray::updateUntil(int i, int val, int ts, int te, int ti) {
    if (i == ts && te - ts == 1) {
        tree[ti] = val;
        return;
    }
    if (i < ts || i >= te) {
        return;
    }
    int tm = mid(ts, te);
    updateUntil(i, val, ts, tm, ti*2+1);
    updateUntil(i, val, tm, te, ti*2+2);
    tree[ti] = tree[ti*2+1] + tree[ti*2+2];
}

int main(int argc, char *argv[]) {
    vector<int> a = {1, 3, 5};
    NumArray na(a);
    cout << na.sumRange(0, 2) << endl;
    na.update(1, 2);
    cout << na.sumRange(0, 2) << endl;
}
