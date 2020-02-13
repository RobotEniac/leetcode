// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/02/12 18:28:57
// Description: https://leetcode.com/problems/shortest-palindrome/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "util.h"

using namespace std;

string shortestPalindrome(string s) {
    if (s.empty()) {
        return "";
    }
    if (s.size() == 1) {
        return s;
    }
    for (int i = s.size() - 1; i >= 0; --i) {
        // is parlindrome
        int p = 0;
        int q = i;
        while (p < q && s[p] == s[q]) {
            p++; q--;
        }
        if (p >= q) {
            return string(s.rbegin(), s.rend() - i - 1) + s;
        }
    }
    return "";
}

void showVec(vector<int> &v) {
    for (int i = 0; i < v.size(); ++i) {
        printf("%3d", v[i]);
    }
    printf("\n");
}

void showStr(string &s) {
    for (int i = 0; i < s.size(); ++i) {
        printf("%3c", s[i]);
    }
    printf("\n");
}

string shortestPalindrome2(string s) {
    if (s.size() < 2) {
        return s;
    }
    string rev(s.rbegin(), s.rend());
    string tmp = s + "#" + rev;
    vector<int> p(tmp.size(), 0);
    for (int i = 1; i < tmp.size(); ++i) {
        int j = p[i-1];
        while (j > 0 && tmp[i] != tmp[j]) {
            j = p[j-1];
        }
        if (tmp[i] == tmp[j]) {
            p[i] = j+1;
        }
    }
    showStr(tmp);
    showVec(p);
    int index = s.size() - p[p.size() - 1];
    return rev.substr(0, index) + s;
}

int main(int argc, char *argv[]) {
    cout << string(argv[1]) << "\n";
    cout << shortestPalindrome(argv[1]) << "\n";
    cout << shortestPalindrome2(argv[1]) << "\n";
}
