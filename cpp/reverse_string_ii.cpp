// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/04/13 14:16:42
// Description: https://leetcode-cn.com/problems/reverse-string-ii/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

void reverse(string& s, int l, int r) {
    while (l < r) {
        char c = s[l];
        s[l] = s[r];
        s[r] = c;
        l++;
        r--;
    }
}

string reverseStr(string s, int k) {
    for (int i = 0; i < s.size(); i = i + 2 * k) {
        if (i + k <= s.size()) {
            reverse(s, i, i+k-1);
        } else {
            reverse(s, i, s.size() - 1);
        }
    }
    return s;
}

int main(int argc, char *argv[]) {
    cout << reverseStr("abcdefg", 2) << endl;
}
