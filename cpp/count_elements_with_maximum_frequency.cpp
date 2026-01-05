// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/11/17 21:17:17
// Description: https://leetcode.cn/problems/count-elements-with-maximum-frequency/description/?envType=daily-question&envId=2025-11-17

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

void show(vector<int>& v, map<int, int>& m) {
    for (int i = 0; i < v.size(); ++i) {
        if (i != 0) {
            cout << ", " << v[i] << ":" << m[v[i]];
            continue;
        }
        cout << v[i] << ":" << m[v[i]];
    }
    cout << endl;
}

int maxFrequencyElements(vector<int> &nums) {
    map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
        if (m.find(nums[i]) != m.end()) {
            ++m[nums[i]];
        } else {
            m[nums[i]] = 1;
        }
    }
    int max_freq = 0;
    int ret = 0;
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it->second > max_freq) {
            max_freq = it->second;
            ret = max_freq;
        } else if (it->second == max_freq) {
            ret += max_freq;
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<int> a = {1,2,2,3,1,4};
    cout << maxFrequencyElements(a) << endl;
}
