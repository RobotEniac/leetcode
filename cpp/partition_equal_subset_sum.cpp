// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/03/09 21:58:15
// Description: https://leetcode.cn/problems/partition-equal-subset-sum/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

void show(vector<int>& a, vector<bool>& e) {
    cout << e << endl;
    bool start = false;
    for (int i = 0; i < a.size(); ++i) {
        if (e[i]) {
            if (start) {
                cout << ", ";
            }
            cout << a[i];
            start = true;
        }
    }
    cout << endl;
}

bool canAddTo(vector<int>& a, vector<bool>& e, int sum) {
    for (int i = 0; i < a.size(); ++i) {
        if (e[i]) {
            continue;
        }
        if (a[i] == sum) {
            show(a, e);
            return true;
        }
        if (a[i] > sum) {
            return false;
        }
        e[i] = true;
        if (canAddTo(a, e, sum - a[i])) {
            show(a, e);
            return true;
        }
        e[i] = false;
    }
    return false;
}

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
    }
    if (sum % 2 != 0) {
        return false;
    }
    sum = sum / 2;
    vector<bool> e(nums.size(), false);
    return canAddTo(nums, e, sum);
}

int main(int argc, char *argv[]) {
    vector<int> a = {1,5,11,5};
    cout << boolalpha << canPartition(a) << endl;
}
