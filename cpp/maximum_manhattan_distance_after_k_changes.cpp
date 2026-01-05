// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/06/20 16:47:18
// Description: https://leetcode.cn/problems/maximum-manhattan-distance-after-k-changes/description/?envType=daily-question&envId=2025-06-20

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

void cal(const string& s, int &x, int &y) {
    for (int i = 0; i < s.size(); ++i) {
        switch (s[i]) {
        case 'N':
            ++y;
            break;
        case 'S':
            --y;
            break;
        case 'E':
            ++x;
            break;
        case 'W':
            --x;
            break;
        default:
            break;
        }
    }
}

int maxDistance(string s, int k) {
    int x = 0;
    int y = 0;
    cal(s, x, y);
    cout << s << ":\n" << x << ", " << y << endl;
    return 0;
}

int main(int argc, char *argv[]) {
    string s = "NWSE";
    cout << maxDistance(s, 1) << endl;
}
