// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/02/17 15:59:19
// Description: https://leetcode.com/problems/add-digits

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int addDigits(int num) {
    while (num / 10 > 0) {
        int sum = 0;
        int n = num;
        while (n > 0) {
            sum = sum + (n % 10);
            n = n / 10;
        }
        num = sum;
    }
    return num;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    cout << n << ": " << addDigits(n) << endl;
}
