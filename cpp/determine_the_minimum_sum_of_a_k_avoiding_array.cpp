// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/03/26 15:25:13
// Description: https://leetcode.cn/problems/determine-the-minimum-sum-of-a-k-avoiding-array/description/?envType=daily-question&envId=2025-03-26

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int minimumSum(int n, int k) {
    int t = k / 2;
    if (t >= n) {
        return n * (n+1) / 2;
    } else {
        return (t*(t+1)/2) + (n-t)*(k+k+n-t-1)/2;
    }
}

int main(int argc, char *argv[]) {
    cout << minimumSum(5, 4) << endl;
}
