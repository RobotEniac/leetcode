// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/02/17 15:52:15
// Description: https://leetcode.com/problems/valid-anagram/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

int main(int argc, char *argv[]) {
    string s(argv[1]);
    string t(argv[2]);
    cout << boolalpha << s << ", " << t << " = "<< isAnagram(s, t) << endl;
}
