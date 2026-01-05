// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/10/30 20:39:36
// Description: https://leetcode.cn/problems/check-if-number-is-a-sum-of-powers-of-three/description/?envType=daily-question&envId=2025-10-29

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

bool checkPowersOfThree(int n) {
    while (n != 0) {
        int r = n % 3;
        if (r > 1) {
            return false;
        }
        n = n / 3;
    }
    return true;
}

int main(int argc, char *argv[]) {
    cout << checkPowersOfThree(21) << endl;
}
