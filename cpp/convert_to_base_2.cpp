// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2024/04/28 17:15:16
// Description: https://leetcode.cn/problems/convert-to-base-2/description/?envType=daily-question&envId=Invalid%20Date

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

string baseNeg2(int n) {
    if (n == 0) {
        return string("0");
    }
    string ret;
    while (n != 0) {
        if ((n & 1) != 0) {
            ret.insert(0, "1");
        } else {
            ret.insert(0, "0");
        }
        n = -(n>>1);
    }
    return ret;
}

int main(int argc, char *argv[]) {
    int i = atoi(argv[1]);
    cout << i << ":" << baseNeg2(i) << endl;
}
