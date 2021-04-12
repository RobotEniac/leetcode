// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/04/08 15:38:54
// Description: https://leetcode-cn.com/problems/maximum-number-of-consecutive-values-you-can-make/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "util.h"

using namespace std;

int getMaximumConsecutive(vector<int>& coins) {
    qsort(coins.begin(), coins.end());
    int n = 0;
    for (int i = 0; i < coins.size(); ++i) {
        if (coins[i] <= n+1) {
            n += coins[i];
        } else {
            break;
        }
    }
    return n+1;
}

int main(int argc, char *argv[]) {
    vector<int> an = {1,4,10,3,1};
    cout << getMaximumConsecutive(an) << endl;
}
