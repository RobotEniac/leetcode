// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/05/09 18:37:10
// Description: https://leetcode.com/problems/super-ugly-number/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<int> index(primes.size(), 0);
    int count = 0;
    vector<int> res;
    int64_t num = 1;
    res.push_back(num);
    while (count < n - 1) {
        int min_num = INT_MAX;
        for (int i = 0; i < index.size(); ++i) {
            int64_t cur = res[index[i]] * primes[i];
            if (cur < min_num) {
                min_num = cur;
            }
        }
        for (int i = 0; i < index.size(); ++i) {
            int64_t cur = res[index[i]] * primes[i];
            if (cur == min_num) {
                index[i]++;
            }
        }
        num = min_num;
        res.push_back(num);
        ++count;
    }
    return num;
}

int main(int argc, char *argv[]) {
    vector<int> p = {2, 7, 13, 19};
    cout << nthSuperUglyNumber(12, p) << endl;
}
