// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/10/13 16:31:22
// Description: https://leetcode.cn/problems/find-the-k-th-character-in-string-game-i/?envType=daily-question&envId=2025-06-13

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

char kthCharacter(int k) {
    string s(1, 'a');
    while (s.size() < k) {
        string t(s);
        for (int i = 0; i < t.size(); ++i) {
            t[i] += 1;
            if (t[i] > 'z') {
                t[i] = 'a';
            }
        }
        s += t;
    }
    cout << s << endl;
    return s[k];
}

int main(int argc, char *argv[]) {
    cout << kthCharacter(1000) << endl;
}
