// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/02/18
// Description: 

#include "util.h"
#include <iostream>
#include <vector>

using namespace std;

int maximumGap(vector<int>& nums) {
    if (nums.size() < 2) {
        return 0;
    }
    int min = INT_MAX;
    int max = INT_MIN;
    for (int i = 0; i < nums.size(); ++i) {
        min = (min <= nums[i]) ? min : nums[i];
        max = (max >= nums[i]) ? max : nums[i];
    }
    if (max == min) {
        return 0;
    }
    int len = (max - min) / nums.size() + 1;
    struct Bucket {
        int low;
        int high;
        Bucket() : low(-1), high(-1) {}
    };
    vector<Bucket> bkts(nums.size() + 1);
    for (int i = 0; i < nums.size(); ++i) {
        int x = (nums[i] - min) / len;
        if (bkts[x].low == -1 && bkts[x].high == -1) {
            bkts[x].low = bkts[x].high = nums[i];
        } else {
            if (bkts[x].low >= nums[i]) {
                bkts[x].low = nums[i];
            }
            if (bkts[x].high <= nums[i]) {
                bkts[x].high = nums[i];
            }
        }
    }
    int max_gap = INT_MIN;
    int prev = 0;
    for (int i = 1; i < bkts.size(); ++i) {
        if (bkts[i].low == -1 && bkts[i].high == -1) {
            continue;
        }
        if (bkts[i].low - bkts[prev].high > max_gap) {
            max_gap = bkts[i].low - bkts[prev].high;
        }
        prev = i;
    }
    return max_gap;
}

int main(int argc, char *argv[]) {
    vector<int> a = {1,1,1,1};
    std::cout << a << endl;
    cout << maximumGap(a) << endl;
}

