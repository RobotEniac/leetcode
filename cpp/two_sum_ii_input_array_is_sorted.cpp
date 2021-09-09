// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/06/28 11:48:16
// Description: https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int find(vector<int>& a, int s, int e, int t) {
    if (e - s == 1) {
        if (a[s] == t) {
            return s;
        }
        return -1;
    }
    while (s < e) {
        int m = (s + e) / 2;
        if (a[m] == t) {
            return m;
        }
        if (a[m] > t) {
            e = m;
        } else {
            s = m + 1;
        }
    }
    return -1;
}

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> ret(2, 0);
    for (int i = numbers.size() - 1; i > 0; --i) {
        int j = find(numbers, 0, i, target - numbers[i]);
        if (j >= 0) {
            ret[0] = j+1;
            ret[1] = i+1;
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<int> a = {-1, 0};
    cout << twoSum(a, -1) << endl;
}
