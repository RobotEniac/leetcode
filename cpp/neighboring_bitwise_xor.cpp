// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/10/30 20:19:20
// Description: https://leetcode.cn/problems/neighboring-bitwise-xor/?envType=daily-question&envId=2025-10-29

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

bool doesValidArrayExist(vector<int> &derived) {
    int a = 0;
    for (int i = 0; i < derived.size() - 1; ++i) {
        a = a ^ derived[i];
    }
    return a == derived[derived.size() - 1];
}

int main(int argc, char *argv[]) {
    vector<int> d = {1,1};
    cout << boolalpha << doesValidArrayExist(d) << endl;
}
