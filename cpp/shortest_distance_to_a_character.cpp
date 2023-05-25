// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/03/02 18:22:55
// Description: https://leetcode.cn/problems/shortest-distance-to-a-character/

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "util.h"

using namespace std;

vector<int> shortestToChar(string s, char c) {
    vector<int> pm(1, INT_MAX);
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == c) {
            pm.push_back(i);
        }
    }
    pm.push_back(INT_MAX);
    cout << pm << endl;
    vector<int> ret(s.size(), 0);
    int l = 1;
    for (int i = 0; i < s.size(); ++i) {
        if (i != pm[l]) {
            ret[i] = std::min(abs(i - pm[l-1]), pm[l]-i);
        } else {
            ++l;
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    string s = "aaab";
    cout << shortestToChar(s, 'b') << endl;
}
