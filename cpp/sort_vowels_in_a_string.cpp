// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/09/17 09:04:22
// Description: https://leetcode.cn/problems/sort-vowels-in-a-string/?envType=daily-question&envId=2025-09-16

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

bool isVowel(char c) {
    switch (c) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        return true;
    default:
        return false;
    }
}

string sortVowels(string s)
{
    string vs;
    for (int i = 0; i < s.size(); ++i) {
        if (isVowel(s[i])) {
            vs.push_back(s[i]);
        }
    }
    sort(vs.begin(), vs.end());
    int j = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (isVowel(s[i])) {
            s[i] = vs[j];
            ++j;
        }
    }
    return s;
}

int main(int argc, char *argv[]) {
    cout << sortVowels("lEetcOde") << endl;
}
