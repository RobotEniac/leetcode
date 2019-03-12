// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/03/09 17:12:21
// Description: https://leetcode.com/problems/isomorphic-strings/

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "util.h"

using namespace std;

void print(map<char, char> &m) {
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << it->first << " => " << it->second << "\n";
    }
}

bool isIsomorphic(string &s, string &t) {
    if (s.size() != t.size()) {
        return false;
    }
    char fun[256] = {0};
    char yset[256] = {0};
    for (int i = 0; i < s.size(); ++i) {
        if (fun[s[i]] == 0) {
            if (yset[t[i]] != 0) {
                return false;
            }
            yset[t[i]] = 1;
            fun[s[i]] = t[i];
        } else if (fun[s[i]] != t[i]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    string s1(argv[1]);
    string s2(argv[2]);
    cout << boolalpha << "isIsomorphic(" << s1 << ", " << s2 << ") = " << isIsomorphic(s1, s2) << endl;
}
