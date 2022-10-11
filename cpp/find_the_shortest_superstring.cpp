// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2022/05/09 17:06:47
// Description: https://leetcode.cn/problems/find-the-shortest-superstring/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

string overlap(const std::string& a, const std::string& b) {
    int ai = b.size() - a.size();
    int bi = 0;
    if (ai < 0) {
        ai = 0;
    }
    while (ai < a.size()) {
        for (int i = 0; i < b.size(); ++i) {
            if (ai + i >= a.size()) {
                return a.substr(ai);
            }
            if (a[ai+i] != b[i]) {
                break;
            }
        }
        ++ai;
    }
    return "";
}

string shortestSuperstring(vector<string>& words) {
    return "";
}

int main(int argc, char *argv[]) {
    cout << overlap("aaa", "aab") << endl;
    cout << overlap("aab", "aaa") << endl;
}
