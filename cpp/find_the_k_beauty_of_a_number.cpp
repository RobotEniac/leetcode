// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/03/26 17:26:13
// Description: https://leetcode.cn/problems/find-the-k-beauty-of-a-number/?envType=daily-question&envId=2025-03-26

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int divisorSubstrings(int num, int k) {
    int i = 0;
    int ret = num  % (int)pow(10, k);
    int c = 0;
    while ((int)pow(10, k+i-1) <= num) {
        cout << ret << endl;
        if (ret != 0 && num % ret == 0) {
            ++c;
        }
        ++i;
        ret = (num / (int)pow(10, i)) % (int)pow(10, k);
    }

    return c;
}

int main(int argc, char *argv[]) {
    cout << divisorSubstrings(240, 2) << endl;
    cout << divisorSubstrings(430043, 2) << endl;
}
