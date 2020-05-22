// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/05/22 10:53:51
// Description: https://leetcode.com/problems/longest-palindromic-substring/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

string longestPalindrome(string s) {
    if (s.empty()) {
        return "";
    }
    if (s.size() == 1) {
        return s;
    }
    size_t ssize = s.size();
    vector<vector<bool> > m(ssize+1, vector<bool>(ssize+1, false));
    for (int i = 0; i < ssize; ++i) {
        m[i][i] = true;
        m[i][i+1] = true;
    }
    int max_len = 1;
    string ret(1, s[0]);
    for (int len = 2; len <= ssize; ++len) {
        for (int i = 0; i < ssize-len+1; ++i) {
            if (s[i] == s[i+len-1] && m[i+1][i+len-1]) {
                m[i][i+len] = true;
                if (len > max_len) {
                    max_len = len;
                    ret = s.substr(i, len);
                }
            }
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    string s(argv[1]);
    cout << s << endl;
    cout << longestPalindrome(s) << endl;
}
