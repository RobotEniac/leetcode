// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/10/20 16:34:20
// Description: https://leetcode.cn/problems/longest-binary-subsequence-less-than-or-equal-to-k/?envType=daily-question&envId=2025-10-17

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

bool le(const vector<int>& lhs, const vector<int>& rhs) {
    int li = lhs.size() - 1;
    int ri = rhs.size() - 1;
    while (li >= 0 && lhs[li] == 0) {
        --li;
    }
    while (ri >= 0 && rhs[ri] == 0) {
        --ri;
    }
    if (li < ri) {
        return true;
    }
    if (li > ri) {
        return false;
    }
    while (li >= 0) {
        if (lhs[li] < rhs[li]) {
            return true;
        } else if (lhs[li] > rhs[li]) {
            return false;
        }
        --li;
    }
    return true;
}

int longestSubsequence(string s, int k) {
    if (s.empty()) {
        return 0;
    }
    vector<int> vm;
    vector<int> vk;
    int tmp = k;
    while (tmp != 0) {
        vk.push_back(tmp & 0x01);
        tmp = tmp >> 1;
    }
    int min_len = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == '0') {
            vm.push_back(0);
        } else if (s[i] == '1') {
            vm.push_back(1);
            if (!le(vm, vk)) {
                vm.pop_back();
            }
        }
    }
    cout << vm << "\n" << vk << endl;
    return vm.size();
}

int main(int argc, char *argv[]) {
    cout << longestSubsequence("1001010", 5) << endl;
    cout << longestSubsequence("00101001", 1) << endl;
}
