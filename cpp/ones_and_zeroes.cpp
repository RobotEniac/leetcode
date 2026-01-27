// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2026/01/19 19:50:34
// Description: https://leetcode.cn/problems/ones-and-zeroes/?envType=daily-question&envId=2026-01-19

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

void dfs(map<int, vector<int>> &mp, int m, int n) {

}

int findMaxForm(vector<string> &strs, int m, int n) {
    map<int, vector<int>> mp;
    for (int i = 0; i < strs.size(); ++i) {
        int c = 0;
        for (int j = 0; j < strs[i].size(); ++i) {
            if (strs[i][j] == '0') {
                ++c;
            }
        }
        if (mp.find(c) == mp.end()) {
            mp[c] = vector<int>(1, strs[i].size() - c);
        } else {
            mp[c].push_back(strs[i].size() - c);
        }
    }
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        sort(it->second.begin(), it->second.end());
    }
}

int main(int argc, char *argv[]) {
    cout << "hello world" << endl;
}
