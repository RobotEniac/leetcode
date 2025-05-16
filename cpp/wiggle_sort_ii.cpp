// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/04/25 17:16:16
// Description: https://leetcode.cn/problems/wiggle-sort-ii/description/?envType=problem-list-v2&envId=greedy

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

void insert(vector<int>& nums, int i, int j) {
    int t = nums[j];
    for (int k = j; k > i; --k) {
        nums[k] = nums[k-1];
    }
    nums[i] = t;
}

void wiggleSort(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int m = (nums.size()-1) / 2;
    for (int i = m+1, j = 1; i < nums.size(); ++i, j += 2) {
        insert(nums, j, i);
    }
}

int main(int argc, char *argv[]) {
    vector<int> v = {4,5,5,6};
    wiggleSort(v);
    cout << v << endl;
}
