// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/09/17 12:10:16
// Description: https://leetcode.com/problems/backspace-string-compare/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int Real(string& s) {
    int l = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[l++] = s[i];
        } else if (s[i] == '#') {
            if (l > 0) {
                --l;
            }
        }
    }
    return l;
}

bool backspaceCompare(string S, string T) {
    int sl = Real(S);
    int tl = Real(T);
    if (sl != tl) {
        return false;
    }
    int i = 0;
    while (i < sl && S[i] == T[i]) ++i;
    return i == sl;
}

int main(int argc, char *argv[]) {
    string s(argv[1]);
    cout << s << "\n" << Real(s) << "\n";
}
