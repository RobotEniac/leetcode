// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/06/16 14:06:40
// Description: https://leetcode.cn/problems/find-the-lexicographically-largest-string-from-the-box-i/?envType=daily-question&envId=2025-06-13

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

string answerString(string word, int f) {
    if (f == 0) {
        return "";
    }
    if (f == 1) {
        return word;
    }
    vector<vector<int>> v(26, vector<int>());
    for (int i = 0; i < word.size(); ++i) {
        int j = word[i] - 'a';
        v[j].push_back(i);
    }
    vector<int> sp;
    sp.push_back(0);
    for (int i = 25; i >= 0 && sp.size() < f; --i) {
        if (!v[i].empty()) {
            for (int j = 0; j < v[i].size() && sp.size() < f; ++j) {
                sp.push_back(v[i][j]);
            }
        }
    }
    sort(sp.begin(), sp.end());
    vector<string> ret;
    for (int i = 0; i < sp.size(); ++i) {
        if (i == sp.size() - 1) {
            ret.push_back(word.substr(sp[i]));
        } else {
            ret.push_back(word.substr(sp[i-1], sp[i]-sp[i-1]));
        }
    }
    sort(ret.begin(), ret.end());
    cout << ret << endl;
    return ret[ret.size() - 1];
}

int main(int argc, char *argv[]) {
    string s = "dbca";
    cout << answerString(s, 2) << endl;
}
