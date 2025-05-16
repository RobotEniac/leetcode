// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2024/05/14 21:01:43
// Description: https://leetcode.cn/problems/minimum-rounds-to-complete-all-tasks/description/?envType=daily-question&envId=2024-05-14

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "util.h"

using namespace std;

int minimum(int a) {
    if (a < 2) {
        return -1;
    }
    if (((a % 3) & 0x1) == 0) {
        return a / 3 + (a % 3) / 2;
    } else {
        return (a - 3) / 3 + ((a % 3) + 3) / 2;
    }
}

int minimumRounds(vector<int>& tasks) {
    map<int, int> m;
    for (int i = 0; i < tasks.size(); ++i) {
        if (m.find(tasks[i]) == m.end()) {
            m[tasks[i]] = 1;
        } else {
            ++m[tasks[i]];
        }
    }
    int ret = 0;
    for (auto it = m.begin(); it != m.end(); ++it) {
        int t = minimum(it->second);
        if (t < 0) {
            return -1;
        }
        ret += t;
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<int> tasks = {2,2,3,3,2,4,4,4,4,4};
    cout << tasks << endl;
    cout << minimumRounds(tasks) << endl;
}
