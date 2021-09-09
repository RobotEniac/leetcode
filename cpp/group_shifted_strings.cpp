// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/07/12 12:19:05
// Description: https://leetcode-cn.com/problems/group-shifted-strings/

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "util.h"

using namespace std;

string formalize(const std::string& s) {
    if (s.empty()) {
        return s;
    }
    string ret(s);
    int t = s[0] - 'a';
    for (int i = 0; i < ret[i]; ++i) {
        ret[i] = ret[i] - t;
        if (ret[i] < 'a') {
            ret[i] += 26;
        }
    }
    return ret;
}

vector<vector<string>> groupStrings(vector<string>& strings) {
    vector<vector<string>> ret;
    map<string, vector<string>> m;
    for (int i = 0; i < strings.size(); ++i) {
        string t = formalize(strings[i]);
        if (m.find(t) == m.end()) {
            m[t] = vector<string>(1, strings[i]);
        } else {
            m[t].push_back(strings[i]);
        }
    }
    for (auto it = m.begin(); it != m.end(); ++it) {
        ret.push_back(it->second);
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<string> input = {"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};
    vector<vector<string>> ret = groupStrings(input);
    for (int i = 0; i < ret.size(); ++i) {
        if (i != 0) {
            cout << ", ";
        }
        cout << ret[i];
    }
    cout << "\n";
}
