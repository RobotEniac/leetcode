// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/11/04 17:35:46
// Description: https://leetcode.cn/problems/max-difference-you-can-get-from-changing-an-integer/?envType=daily-question&envId=2025-10-29

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int change(int n, int from, int to) {
    int c = 1;
    int ret = 0;
    while (n != 0) {
        int g = n % 10;
        if (g == from) {
            g = to;
        }
        ret += g * c;
        c = c * 10;
        n = n / 10;
    }
    cout << ret << endl;
    return ret;
}

int maxDiff(int num) {
    vector<int> a;
    int t = num;
    while (t != 0) {
        a.push_back(t % 10);
        t = t / 10;
    }
    int h = 0;
    int h_to = 0;
    for (int i = a.size() - 1; i >= 0; --i) {
        if (a[i] != 9) {
            h = a[i];
            h_to = 9;
            break;
        }
    }
    int l = a[a.size() - 1];
    int l_to = 1;
    for (int i = a.size() - 1; i >= 0; --i) {
        if (i == a.size() - 1) {
            if (a[i] != 1) {
                break;
            }
            continue;
        } 
        if (a[i] != 0 && a[i] != a[a.size() - 1]) {
            l = a[i];
            l_to = 0;
            break;
        }
    }
    return change(num, h, h_to) - change(num, l, l_to);
}

int main(int argc, char *argv[]) {
    cout << maxDiff(123456) << endl;
}
