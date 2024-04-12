// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2024/02/23 16:16:34
// Description: https://leetcode.cn/problems/ransom-note/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    char m[26] = {0};
    for (int i = 0; i < magazine.size(); ++i) {
        ++m[magazine[i]-'a'];
    }
    for (int i = 0; i < ransomNote.size(); ++i) {
        if (--m[ransomNote[i]-'a'] < 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    // string s1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    // string s2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    string s1 = "aaa";
    string s2 = "aaa";
    cout << boolalpha << canConstruct(s1, s2) << endl;
}
