// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/04/09 17:13:26
// Description: https://leetcode-cn.com/problems/k-diff-pairs-in-an-array/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int findPairs(vector<int>& nums, int k) {
    int count = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        int j = i;
        int last = -1;
        while (j < nums.size() && nums[j] - nums[i] <= k) {
            if (nums[j] - nums[i] == k &&
                (last < 0 || nums[j] != nums[last])) {
                cout << "(" << nums[i] << ", " << nums[j] << ")\n";
                last = j;
                count++;
            }
            ++j;
        }
    }
    return count;
}

int main(int argc, char *argv[]) {
    vector<int> a = {3,1,4,1,5};
    cout << findPairs(a, 2) << endl;
}
