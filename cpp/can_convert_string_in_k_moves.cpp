// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2022/02/22 20:18:48
// Description: https://leetcode-cn.com/problems/can-convert-string-in-k-moves/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

bool canConvertString(const string &s, const string &t, int k) {
    if (s.size() != t.size()) {
        return false;
    }
    if (s.empty()) {
        return true;
    }
    vector<int> p(26, 0);
    for (int i = 0; i < s.size(); ++i) {
        int tmp = t[i] - s[i];
        if (tmp < 0) {
            tmp += 26;
        }
        p[tmp]++;
    }
    for (int i = 1; i < p.size(); ++i) {
        if (p[i] == 1 && i > k) {
            return false;
        }
        else if (p[i] > 1 && i + (p[i] - 1) * 26 > k) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    cout << boolalpha << canConvertString("abc", "bcd", 10);
}
