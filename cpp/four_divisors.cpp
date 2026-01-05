// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2026/01/04 17:41:31
// Description: https://leetcode.cn/problems/four-divisors/?envType=daily-question&envId=2026-01-04

#include <iostream>
#include <vector>
#include <string>

#include "util.h"
#include "file_util.hpp"

using namespace std;

vector<int> primes(int n) {
    vector<int> a;
    a.push_back(2);
    for (int i = 3; i <= n; ++i) {
        bool is_prime = true;
        for (int j = 0; j < a.size(); ++j) {
            if (i % a[j] == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            a.push_back(i);
        }
    }
    return a;
}

bool find(const vector<int>& v, int x) {
    if (x < v[0] || x > v[v.size()-1]) {
        return false;
    }
    int l = 0;
    int r = v.size();
    int m = (l+r) / 2;
    while (l < r) {
        if (v[m] == x) {
            return true;
        }
        if (v[m] > x) {
            r = m;
            m = (l+r) / 2;
        } else {
            l = m+1;
            m = (l+r) / 2;
        }
    }
    return false;
}

int sumFourDivisors(vector<int> &nums) {
    int mmax = INT_MIN;
    for (int i = 0; i < nums.size(); ++i) {
        if (mmax < nums[i]) {
            mmax = nums[i];
        }
    }
    vector<int> p = primes(mmax / 2);
    int ret = 0;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < p.size(); ++j) {
            if (nums[i] % p[j] == 0) {
                int r = nums[i] / p[j];
                if (r != 1 && r != p[j]) {
                    if (find(p, r) || p[j] * p[j] ==r) {
                        ret += 1 + p[j] + r + nums[i];
                        break;
                    }
                }
            }
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<int> a = lc::ReadArrayInt("in.txt");
    cout << sumFourDivisors(a) << endl;
}
