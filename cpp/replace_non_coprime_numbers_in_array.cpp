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
    int i = 0;
    int e = nums.size();
    while (i < e) {
        if (nums[i] == 1) {
            ++i;
            continue;
        }
        int c = 0;
        while (i+1+c < e && nums[i] == nums[i+1+c]) {
            ++c;
        }
        if (c == 0) {
            ++i;
        }
        else
        {
            for (int j = i + 1; j+c < e; ++j)
            {
                nums[j] = nums[j + c];
            }
            e -= c;
        }
    }
    i = 0;
    while (i < e-1) {
        // cout << i << "~" << e << ":" << nums << endl;
        int64_t t = gcd(nums[i], nums[i+1]);
        if (t == 1) {
            ++i;
        } else {
            int64_t n = (int64_t)nums[i] * (int64_t)nums[i+1] / t;
            nums[i] = n;
            for (int j = i+1; j < e; ++j) {
                nums[j] = nums[j+1];
            }
            --e;
            if (i > 0 && gcd(nums[i], nums[i-1]) != 1) {
                --i;
            }
        }
    }
    vector<int> ret(nums.begin(), nums.begin() + e);
    return ret;
}

int main(int argc, char *argv[]) {
    // vector<int> v = {287,41,49,287,899,23,23,20677,5,825};
    vector<int> v = {2,2,1,1,3,3,3};
    cout << v << endl;
    vector<int> r = replaceNonCoprimes(v);
    cout << v << endl;
    cout << r << endl;
}
