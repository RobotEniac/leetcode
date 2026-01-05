// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/05/29 10:46:54
// Description: https://leetcode.cn/problems/maximum-or/description/?envType=daily-question&envId=2025-05-29

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int h1(int x) {
    int n = 0;
    while (x != 0) {
        x = x >> 1;
        ++n;
    }
    return n;
}

long long maximumOr(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    vector<int64_t> pre(nums.size() +1, 0);
    vector<int64_t> suf(nums.size() +1, 0);
    for (int i = 0; i < nums.size(); ++i) {
        pre[i] =
    }
    for (int i = nums.size() - 1; i >= 0; --i) {

    }
}

int main(int argc, char *argv[]) {
    cout << "hello world" << endl;
}
