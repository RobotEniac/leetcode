// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/05/15 20:54:53
// Description: https://leetcode.cn/problems/valid-palindrome-ii/description/?envType=daily-question&envId=2025-05-14

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

bool validPalindrome(string& s, int l, int r) {
    if (l >= r) {
        return true;
    }
    int i = l;
    int j = r;
    while (i < j) {
        if (s[i] == s[j]) {
            ++i;--j;
        } else {
            return false;
        }
    }
    return true;
}

bool validPalindrome(string s) {
    int i = 0;
    int j = s.size() - 1;
    int c = 0;
    while (i < j) {
        if (s[i] == s[j]) {
            ++i;--j;
        } else if (i+1 == j) {
            ++i;
        } else {
            return validPalindrome(s, i+1, j) || validPalindrome(s, i, j-1);
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    cout << boolalpha << validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga") << endl;
}
