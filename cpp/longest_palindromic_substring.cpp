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

string extend(string &s, int l, int r) {
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
        --l;
        ++r;
    }
    return s.substr(l+1, r - l-1);
}

string longestPalindrome2(string &s) {
    if (s.empty()) {
        return "";
    }
    int max_len = 1;
    string ret(1, s[0]);
    for (int i = 0; i < s.size() - 1; ++i) {
        string l1 = extend(s, i, i);
        string l2 = extend(s, i, i+1);
        if (l1.size() > max_len) {
            max_len = l1.size();
            ret = l1;
        }
        if (l2.size() > max_len) {
            max_len = l2.size();
            ret = l2;
        }
    }
    return ret;
}

string longestPalindrome3(string str) {
    if (str.size() < 2)
        return str;
    int start = 0;
    int sz = str.size();
    int left, right;
    int maxlen = 0, maxstart = 0;
    for (start = 0; start < sz && start + maxlen/2 < sz; ++start) {
        left = right = start;
        while (right < sz - 1 && str[right] == str[right+1])
            ++right;
        while (left > 0 && right < sz-1 && str[left-1] == str[right+1]) {
            --left; ++right;
        }
        if (right - left + 1 > maxlen) {
            maxstart = left;
            maxlen = right-left+1;
        }
    }
    return str.substr(maxstart, maxlen);
}

int main(int argc, char *argv[]) {
    string s(argv[1]);
    cout << s << endl;
    cout << longestPalindrome(s) << endl;
    cout << longestPalindrome2(s) << endl;
}
