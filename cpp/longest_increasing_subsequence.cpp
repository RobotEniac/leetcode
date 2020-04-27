// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/04/23 16:00:28
// Description: https://leetcode.com/problems/longest-increasing-subsequence

#include <iostream>
#include <vector>
#include <string>
#include <list>

#include "util.h"

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    if (nums.size() < 2) {
        return nums.size();
    }
    vector<int> memo(nums.size(), -1);
    vector<int> lis(nums.size(), 0);
    lis[0] = 1;
    int max_len = 0;
    int max_last = -1;
    for (int i = 1; i < nums.size(); ++i) {
        int tmp_max = 1;
        int tmp_last = -1;
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                if (lis[j] + 1 > tmp_max) {
                    tmp_max = lis[j] + 1;
                    tmp_last = j;
                }
            }
        }
        lis[i] = tmp_max;
        memo[i] = tmp_last;
        if (tmp_max > max_len) {
            max_len = tmp_max;
            max_last = i;
        }
    }
    list<int> res;
    for (int i = max_last; i >= 0; ) {
        res.push_front(nums[i]);
        i = memo[i];
    }
    cout << res << endl;
    return max_len;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    vector<int> num;
    for (int i = 0; i < n; ++i) {
        num.push_back(rand() % 100);
    }
    vector<int> b = {10,9,2,5,3,7,101,18};
    cout << b << endl;
    cout << lengthOfLIS(b) << endl;
}
