// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/09/16 17:27:57
// Description: https://leetcode.cn/problems/maximum-difference-by-remapping-a-digit/description/?envType=daily-question&envId=2025-09-16

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int minMaxDifference(int num)
{
    vector<int> n;
    int x = num;
    while (x != 0) {
        n.push_back(x % 10);
        x = x / 10;
    }
    int64_t big = 0;
    int64_t small = 0;
    int to9 = -1;
    int to0 = -1;
    for (int i = n.size() -1; i >= 0; --i) {
        if (to9 == -1 && n[i] != 9) {
            to9 = n[i];
        }
        if (to0 == -1 && n[i] != 0) {
            to0 = n[i];
        }
        if (n[i] == to9) {
            big = big * 10 + 9;
        } else {
            big = big * 10 + n[i];
        }
        if (n[i] == to0) {
            small = small * 10 + 0;
        } else {
            small = small * 10 + n[i];
        }
    }
    cout << big << ", " << small << endl;
    return  big - small;
}

int main(int argc, char *argv[]) {
    cout << minMaxDifference(11891) << endl;
}
