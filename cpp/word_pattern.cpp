// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/02/29 23:59:53
// Description: https://leetcode-cn.com/problems/word-pattern/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

void SplitString(string &s, vector<string> *words) {
    size_t i = 0;
    size_t ss = 0;
    bool word_start = false;
    while (i < s.size()) {
        if (s[i] == ' ') {
            if (word_start) {
                words->push_back(s.substr(ss, i - ss));
                word_start = false;
            }
            ++i;
            continue;
        }
        if (!word_start) {
            ss = i;
            word_start = true;
        }
        ++i;
    }
    if (word_start) {
        words->push_back(s.substr(ss));
    }
}

bool wordPattern(string pattern, string str) {
    vector<string> words;
    SplitString(str, &words);
    if (pattern.size() != words.size()) {
        return false;
    }
    map<char, string> m;
    for (size_t i = 0; i < pattern.size(); ++i) {
        auto it = m.find(pattern[i]);
        if (it == m.end()) {
            m[pattern[i]] = words[i];
        } else {
            if (words[i] != it->second) {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    string s = argv[1];
    vector<string> v;
    SplitString(s, &v);
    cout << s << endl;
    cout << v << endl;
}
