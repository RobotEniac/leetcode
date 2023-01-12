// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2022/10/31 11:34:18
// Description: https://leetcode.cn/problems/boolean-evaluation-lcci/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int countEval(const string& s, int result) {
    return cal(s[1], s[0], s[2]) - '0';
}

int main(int argc, char *argv[]) {
    cout << countEval("0^1", 0) << endl;
}
