// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2022/05/09 14:37:05
// Description: https://leetcode.cn/problems/di-string-match/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

vector<int> diStringMatch(string s) {
    int lo = 0;
    int hi = s.size();
    vector<int> ret;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == 'I') {
            ret.push_back(lo++);
        } else {
            ret.push_back(hi--);
        }
    }
    ret.push_back(hi);
    return ret;
}

int main(int argc, char *argv[]) {
    cout << diStringMatch(argv[1]) << endl;
}
