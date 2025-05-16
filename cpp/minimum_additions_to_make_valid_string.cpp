// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2024/02/26 16:07:16
// Description: https://leetcode.cn/problems/minimum-additions-to-make-valid-string/?envType=daily-question&envId=2024-02-26

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int addMinimum(string word) {
    if (word.empty()) {
        return 0;
    }
    int cnt = 1;
    for (int i = 1; i < word.size(); ++i) {
        if (word[i] <= word[i-1]) {
            ++cnt;
        }
    }
    return cnt * 3 - word.size();
}

int main(int argc, char *argv[]) {
    string a = "ababa";
    cout << a << endl;
    cout << addMinimum(a) << endl;
}
