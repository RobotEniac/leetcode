// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/05/06 17:33:06
// Description: https://leetcode-cn.com/problems/bianry-number-to-string-lcci/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

string printBin(double num) {
    int sign = 1;
    if (num < 0) {
        sign = -1;
        num = -num;
    }
    string ret;
    ret.push_back('0');
    ret.push_back('.');
    while (num < 1 && num > 0) {
        if (ret.size() == 32) {
            return "ERROR";
        }
        int b = num * 2;
        if (b >= 1) {
            ret.push_back('1');
            num = num * 2 - 1;
        } else {
            ret.push_back('0');
            num = num * 2;
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    cout << printBin(0.1) << endl;
}
