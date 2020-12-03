// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/02/19 15:05:03
// Description: https://leetcode.com/problems/h-index/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

bool comp(int a, int b) {
    return a >= b;
}

int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    cout << citations << endl;
    int idx = 0;
    for (int i = 0; i < citations.size(); ++i) {
        if (citations[i] >= i+1) {
            idx = i+1;
        }
    }
    return idx;
}

int main(int argc, char *argv[]) {
    vector<int> c = {127,198,132,59,47,107,159,65,180,197,65,16,92,143,157,70,73,31,138,10,202,20,63,80,110,63,52,
        183,97,54,26,70,126,200,233,247,224,50,164,195,117,187,182,94,225,124,157,48,221,250,247,63,7,
        80,75,76,18,102,161,53,116,105,108,14,25,159,180,224,7,18,107,210,178,186,56,163,15,128,22,71};
    cout << hIndex(c) << endl;
    // cout << c << endl;
}
