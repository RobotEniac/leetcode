// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/02/17 16:26:27
// Description: https://leetcode.com/problems/ugly-number/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

bool isUgly(int num) {
    while (num > 1) {
        int c = 0;
        if (num % 2 == 0) {
            num = num / 2;
            ++c;
        } 
        if (num % 3 == 0) {
            num = num / 3;
            ++c;
        }
        if (num % 5 == 0) {
            num = num / 5;
            ++c;
        }
        if (c == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    cout << boolalpha << n << ": " << isUgly(n) << endl;
}
