// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/04/08 10:55:21
// Description: https://leetcode-cn.com/problems/second-largest-digit-in-a-string/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int secondHighest(string& s) {
    int m[10] = {0};
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            m[s[i] - '0']++;
        }
    }
    int c = 0;
    for (int i = 9; i >= 0; --i) {
        if (m[i] > 0) {
            ++c;
        }
        if (c == 2) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {
    cout << "hello world" << endl;
}
