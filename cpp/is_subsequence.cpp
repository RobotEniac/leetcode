// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2024/02/23 16:30:50
// Description: https://leetcode.cn/problems/is-subsequence/description/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

bool isSubsequence(string s, string t) {
    if (s.size() > t.size()) {
        return false;
    }
    int ti = 0;
    int si = 0;
    while (si < s.size() && ti < t.size()) {
        if (s[si] == t[ti]) {
            ++si;
            ++ti;
        } else {
            ++ti;
        }
    }
    if (si >= s.size()) {
        return true;
    }
    return false;
}

int main(int argc, char *argv[]) {
    cout << boolalpha << isSubsequence("abc", "ahbgdc") << endl;
}
