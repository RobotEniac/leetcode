// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/02/19 15:22:24
// Description: https://leetcode.com/problems/first-bad-version/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

bool isBadVersion(int version) {
    return version >= 1;
}

int firstBadVersion(int n) {
    int s = 1;
    int e = n;
    int m = -1;
    while (s < e) {
        cout << s << ", " << e << "\n";
        if (e - s == 1
                && isBadVersion(e)
                && !isBadVersion(s)) {
            return e;
        }
        m = (s + e) / 2;
        if (isBadVersion(m)) {
            if (!isBadVersion(m-1)) {
                return m;
            }
            e = m - 1;
        } else {
            if (isBadVersion(m+1)) {
                return m+1;
            }
            s = m + 1;
        }
    }
    return s;
}

int main(int argc, char *argv[]) {
    cout << firstBadVersion(10) << endl;
}
