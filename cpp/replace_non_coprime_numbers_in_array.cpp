// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/09/16 15:09:07
// Description: https://leetcode.cn/problems/replace-non-coprime-numbers-in-array/description/?envType=daily-question&envId=2025-09-16

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int64_t gcd(int a, int b) {
    if (a < b) {
        return gcd(b, a);
    }
    if (b == 1) {
        return 1;
    }
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

vector<int> replaceNonCoprimes(vector<int> &nums)
{
    vector<int> r;
    for (int i = 0; i < nums.size(); ++i) {
        if (r.empty() || nums[i] == 1) {
            r.push_back(nums[i]);
            continue;
        }
        int &a = r[r.size()-1];
        if (a != nums[i]) {
            int t = gcd(a, nums[i]);
            if (t == 1) {
                r.push_back(nums[i]);
            } else {
                nums[i] = a * nums[i] / t;
                r.pop_back();
                --i;
            }
        }
    }
    return r;
}

int main(int argc, char *argv[]) {
    // vector<int> v = {287,41,49,287,899,23,23,20677,5,825};
    vector<int> v = {10,21,11,33,14,5};
    vector<int> r = replaceNonCoprimes(v);
    cout << v << endl;
    cout << r << endl;
}
