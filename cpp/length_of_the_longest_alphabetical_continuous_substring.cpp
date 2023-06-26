// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/05/29 11:42:16
// Description: https://leetcode.cn/problems/length-of-the-longest-alphabetical-continuous-substring/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int longestContinuousSubstring(string s) {
    int l = 1;
    int mmax = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i-1] + 1) {
            ++l;
        } else {
            if (l > mmax) {
                mmax = l;
            }
            l = 1;
        }
    }
    if (l > mmax) {
        mmax = l;
    }
    return mmax;
}

int main(int argc, char *argv[]) {
    cout << longestContinuousSubstring(argv[1]) << endl;
}
