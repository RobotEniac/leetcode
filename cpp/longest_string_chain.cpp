// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/04/27 17:22:09
// Description: https://leetcode.cn/problems/longest-string-chain/

#include <iostream>
#include <vector>
#include <string>
#include <set>

#include "util.h"

using namespace std;

int longestStrChain(vector<string>& words) {
    sort(words.begin(), words.end(), [&] (const string& s1, const string& s2) {
         return s1.size() < s2.size();
    });
    set<string> st;
    for (int i = 0; i < words.size(); ++i) {
        st.insert(words[i]);
    }
    vector<int> chain(words.size(), 1);
    for (int i = 0; i < words.size(); ++i) {

    }
}

int main(int argc, char *argv[]) {
    cout << "hello world" << endl;
}
