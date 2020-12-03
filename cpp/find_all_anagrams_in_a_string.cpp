// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/09/17 22:40:20
// Description: https://leetcode.com/problems/find-all-anagrams-in-a-string/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;
const int LETTER_SIZE = 26;

bool Equal(int c1[], int c2[]) {
    for (int i = 0; i < 26; ++i) {
        if (c1[i] != c2[i]) {
            return false;
        }
    }
    return true;
}

vector<int> findAnagrams(string s, string p) {
    int cp[26] = {0};
    int k = p.size();
    for (int i = 0; i < k; ++i) {
        cp[p[i] - 'a']++;
    }
    vector<int> ret;
    int wp[26] = {0};
    for (int i = 0; i < k; ++i) {
        wp[s[i] - 'a']++;
    }
    if (Equal(cp, wp)) {
        ret.push_back(0);
    }
    for (int i = k; i < s.size(); ++i) {
        wp[s[i-k]-'a']--;
        wp[s[i] - 'a']++;
        if (Equal(wp, cp)) {
            ret.push_back(i-k+1);
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    string s("cbaebabacd");
    string p("abc");
    cout << findAnagrams(s, p) << endl;
}
