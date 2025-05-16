// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/05/12 16:49:19
// Description: https://leetcode.cn/problems/finding-3-digit-even-numbers/description/?envType=daily-question&envId=2025-05-12

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

void dfs(vector<int>& d, int left, int num, vector<int>& ret) {
    cout << num << ", " << left << ": " << d << endl;
    if (left < 0) {
        if ((num & 0x1) == 0) {
            ret.push_back(num);
        }
        return;
    }
    for (int i = 0; i < 10; ++i) {
        if (d[i] > 0) {
            --d[i];
            dfs(d, left-1, num*10+i, ret);
            ++d[i];
        }
    }
}

vector<int> findEvenNumbers(vector<int>& digits) {
    vector<int> d(10, 0);
    vector<int> ret;
    for (int i = 0; i < digits.size(); ++i) {
        ++d[digits[i]];
    }
    for (int i = 1; i < 10; ++i) {
        if (d[i] > 0) {
            --d[i];
            dfs(d, 1, i, ret);
            ++d[i];
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<int> digits = {1,2,3,0};
    vector<int> ret = findEvenNumbers(digits);
    cout << ret << endl;
}
