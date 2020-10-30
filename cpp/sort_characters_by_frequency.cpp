// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/10/23 16:29:15
// Description: https://leetcode-cn.com/problems/sort-characters-by-frequency/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "util.h"

using namespace std;

void foo() {
    for (char i = 'A'; i < 'z'; ++i) {
        cout << i << ":" << (int)i << endl;
    }
}

string frequencySort(string s) {
    vector<int> d(128, 0);
    string t;
    for (int i = 0; i < s.size(); ++i) {
        if (d[s[i]] == 0) {
            t.push_back(s[i]);
        }
        d[s[i]]++;
    }
    sort(t.begin(), t.end(), [&](char c1, char c2) -> bool { return d[c1] > d[c2]; });
    int si = 0;
    for (int i = 0; i < t.size(); ++i) {
        for (int j = 0; j < d[t[i]]; ++j) {
            s[si++] = t[i];
        }
    }
    return s;
}

int main(int argc, char *argv[]) {
    string s(argv[1]);
    cout << s << endl;
    cout << frequencySort(s) << endl;
}
