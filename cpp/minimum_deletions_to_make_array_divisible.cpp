// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/03/02 17:57:16
// Description: https://leetcode.cn/problems/minimum-deletions-to-make-array-divisible/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int gcd(int a, int b) {
    if (a < b) {
        return gcd(b, a);
    }
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

int pos(vector<int>& num, int s, int e, int target) {
    int l = s;
    int r = s;
    for (int i = s; i < e; ++i) {
        if (num[i] < target) {
            if (l != i) {
                int t = num[l];
                num[l] = num[i];
                num[i] = t;
            }
            ++l;
        }
    }
    if (l == 0) {
        return -1;
    }
    return l - s;
}

int minOperations(vector<int>& nums, vector<int>& numsDivide) {
    int md = numsDivide[0];
    for (int i = 1; i < numsDivide.size(); ++i) {
        md = gcd(md, numsDivide[i]);
    }
    cout << md << endl;
    return pos(nums, 0, nums.size(), md);
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    vector<int> nums = {3,2,6,2,35,5,35,2,5,8,7,3,4};
    vector<int> a = {105,70,70,175,105,105,105};
    cout << pos(nums, 0, nums.size(), n) << endl;
    cout << minOperations(nums, a) << endl;
}
