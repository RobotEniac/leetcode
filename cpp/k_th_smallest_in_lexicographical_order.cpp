// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/10/29 17:34:22
// Description: https://leetcode.cn/problems/k-th-smallest-in-lexicographical-order/?envType=daily-question&envId=2025-10-29

#include <stdlib.h>

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int getStep(int root, int n) {
    if (root > n) {
        return 0;
    }
    int total = 0;
    int first = root;
    int last = root;
    while (first <= n) {
        total += min(last, n) - first + 1;
        first = first * 10;
        last = last * 10 + 9;
    }
    return total;
}

int findKthNumber(int n, int k) {
    int cur = 1;
    int p = 1;
    while (p < k) {
        int step = getStep(cur, n);
        cout << "p = " << p << ", cur = " << cur << ", step = " << step << endl;
        int t = p + step;
        if (t <= k) {
            cur += 1;
            p = t;
        } else if (t > k) {
            cur = cur * 10;
            p = p + 1;
        }
    }
    return cur;
}

int main(int argc, char *argv[]) {
    cout << getStep(1, 2) << endl;
    cout << findKthNumber(10, 3) << endl;
}
