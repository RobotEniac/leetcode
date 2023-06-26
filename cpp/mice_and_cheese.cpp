// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/06/15 18:24:17
// Description: https://leetcode.cn/problems/mice-and-cheese/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

bool next(vector<int>& n, int k) {
    int i = 0;
    while (i < n.size() && n[i] == 0) {
        ++i;
    }
    if (i == n.size()) {
        for (int j = 0; j < k; ++j) {
            n[j] = 1;
        }
        return true;
    }
    while (i < n.size() && n[i] == 1) {
        ++i;
    }
    if (i == n.size()) {
        return false;
    }
    int t = n[i];
    n[i] = n[i-1];
    n[i-1] = t;
    int l = 0;
    int r = i-2;
    while (l < r) {
        t = n[l];
        n[l] = n[r];
        n[r] = t;
        ++l;
        --r;
    }
    return true;
}

int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
    if (reward1.size() != reward2.size()) {
        return 0;
    }
    if (k == 0) {
        int s = 0;
        for (int i = 0; i < reward2.size(); ++i) {
            s += reward2[i];
        }
        return s;
    }
    if (k == reward1.size()) {
        int s = 0;
        for (int i = 0; i < reward1.size(); ++i) {
            s += reward1[i];
        }
        return s;
    }
    vector<int> a(reward1.size(), 0);
    int mm = 0;
    while (next(a, k)) {
        cout << a << endl;
        int sum = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == 1) {
                sum += reward1[i];
            } else {
                sum += reward2[i];
            }
        }
        if (sum > mm) {
            mm = sum;
        }
    }
    return mm;
}

int main(int argc, char *argv[]) {
    // [54,59,94,87,32,10,55,44,21,73,12,70,89,49,13,34,78,20,20,75,90,44,48,74,78,32,70,76,79,49,50,69]
    // [78,43,69,22,32,67,65,38,51,4,21,27,82,61,12,85,62,60,67,16,22,3,5,16,13,35,13,41,72,85,20,54]
    // 17
    vector<int> r1 = {54,59,94,87,32,10,55,44,21,73,12,70,89,49,13,34,78,20,20,75,90,44,48,74,78,32,70,76,79,49,50,69};
    vector<int> r2 = {78,43,69,22,32,67,65,38,51,4,21,27,82,61,12,85,62,60,67,16,22,3,5,16,13,35,13,41,72,85,20,54};
    cout << miceAndCheese(r1, r2, 17) << endl;
}
