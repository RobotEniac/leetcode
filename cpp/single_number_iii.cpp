// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/02/17 16:13:57
// Description: https://leetcode.com/problems/single-number-iii

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    int x = 0;
    for (int n : nums) {
        x = x ^ n;
    }
    int i = 1;
    while ((x & i) == 0) {
        i = i << 1;
    }
    int x1 = 0;
    int x2 = 0;
    for (int n : nums) {
        if ((n & i) == 0) {
            x1 = x1 ^ n;
        } else {
            x2 = x2 ^ n;
        }
    }
    vector<int> res;
    res.push_back(x1);
    res.push_back(x2);
    return res;
}

int main(int argc, char *argv[]) {
    vector<int> n = {1,2,1,3,2,5};
    cout << singleNumber(n);
}
