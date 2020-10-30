// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/10/22 13:59:39
// Description: https://leetcode.com/problems/numbers-at-most-n-given-digit-set/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int count(vector<int>& d, vector<int>& a, int ae) {
    if (ae == 0) {
        return 0;
    }
    int j = 0;
    int ds = d.size();
    while (j < ds && d[j] < a[ae - 1]) {
        ++j;
    }
    if (ae == 1) {
        if (d[j] == a[ae-1]) {
            return j+1;
        }
        return j;
    }
    int64_t res = (pow(ds, ae) - ds) / (ds - 1) * (j+1);
    if (d[j] != a[ae - 1]) {
        return res;
    }
    --ae;
    if (a[ae-1] != 0) {
        return res + count(d, a, ae-1);
    }
    while (ae > 0 && a[ae - 1] == 0) --ae;
    return res + count(d, a, ae);
}

int atMostNGivenDigitSet(vector<string>& digits, int n) {
    if (n == 0) {
        return 0;
    }
    vector<int> a;
    vector<int> d(digits.size(), 0);
    int t = n;
    while (t != 0) {
        a.push_back(t % 10);
        t = t / 10;
    }
    for (int i = 0; i < digits.size(); ++i) {
        d[i] = digits[i][0] - '0';
    }
    int end = a.size() - 1;
    int64_t res = 0;
    int ds = d.size();
    while (end >= 0) {
        int i = 0;
        while (i < ds && d[i] < a[end]) ++i;
        if (end == 0) {
            if (i < ds && d[i] == a[end]) {
                ++i;
            }
            res += i;
            --end;
        } else {
            if (i == ds
                || d[i] > d[end]
                || i == 0) {
                res += (i+1) * (pow(ds, end+1) - ds) / (ds - 1);
                break;
            } else {
                --end;
                if (a[end] == 0) {
                    while (end >= 0 && a[end] == 0) --end;
                }
            }
        }
    }
    return (int)res;
}

int main(int argc, char *argv[]) {
    vector<string> digits = { "1", "4", "9" };
    // vector<string> digits = { "7"};
    int n = 1000000000;
    cout << atMostNGivenDigitSet(digits, n) << endl;
}
