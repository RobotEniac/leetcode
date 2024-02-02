// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2024/01/17 16:35:54
// Description: https://leetcode.cn/problems/find-maximum-number-of-string-pairs/description/?envType=daily-question&envId=2024-01-17

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "util.h"

using namespace std;

int maximumNumberOfStringPairs(vector<string>& words) {
    map<string, int> m;
    int ret = 0;
    for (int i = 0; i < words.size(); ++i) {
        string r(words[i].rbegin(), words[i].rend());
        if (m.find(words[i]) != m.end()) {
            ret += m[words[i]];
        }
        if (m.find(r) == m.end()) {
            m[r] = 1;
        } else {
            m[r] += 1;
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    // vector<string> v = {"cd","ac","dc","ca","zz"};
    vector<string> v = {"aa", "ab"};
    cout << maximumNumberOfStringPairs(v) << endl;
}
