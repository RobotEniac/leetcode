// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/08/21 21:47:19
// Description: https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "util.h"

using namespace std;

int lengthOfLongestSubstring(string s) {
    if (s.size() < 2) {
        return s.size();
    }
    int max_len = 0;
    int start = 0;
    for (int i = 1; i < s.size(); ++i) {
        int j = start;
        for (; j < i; ++j) {
            if (s[j] == s[i]) {
                break;
            }
        }
        if (j == i) {
            if (i-start+1 > max_len) {
                max_len = i-start+1;
            }
        } else {
            start = j+1;
        }
    }
    return max_len;
}

int main(int argc, char *argv[]) {
    string s(argv[1]);
    cout << s << endl;
    cout << lengthOfLongestSubstring(s) << endl;
}
