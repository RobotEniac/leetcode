// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2022/10/27 17:24:56
// Description: https://leetcode.cn/problems/delete-characters-to-make-fancy-string/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

string makeFancyString(string s) {
    string ret;
    int l = 0;
    int r = 1;
    ret.push_back(s[0]);
    for (; r < s.size(); ++r) {
        if (s[r] == s[l]) {
            if (r - l < 2) {
                ret.push_back(s[r]);
            }
        } else {
            ret.push_back(s[r]);
            l = r;
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    cout << makeFancyString(argv[1]) << endl;
}
