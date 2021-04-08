// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/01/15 10:26:26
// Description: https://leetcode-cn.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int uniqueLetterString(string s) {
    char buf[26];
    memset(buf, 0, sizeof(buf));
    for (int i = 0; i < s.size(); ++i) {
        buf[s[i] - 'A']++;
    }
    string raw;
    for (int i = 0; i < 26; ++i) {
        if (buf[i] != 0) {
            raw.push_back(i+'A');
            cout << char(i + 'A') << ":" << (int)buf[i] << "\n";
        }
    }
    cout << raw << endl;
    return 0;
}

int main(int argc, char *argv[]) {
    string s(argv[1]);
    cout << s << endl;
    uniqueLetterString(s);
}
