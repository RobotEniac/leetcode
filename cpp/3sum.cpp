// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/05/16 14:23:45
// Description: https://leetcode-cn.com/problems/3sum/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "util.h"
#include "string.hpp"

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int> > ret;
    if (nums.size() < 3) {
        return ret;
    }
    sort(nums.begin(), nums.end(), std::less<int>());
    for (size_t i = 0; i < nums.size(); ++i) {
        if (nums[i] > 0) {
            break;
        }
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        int two_sum = -nums[i];
        int l = i+1;
        int r = nums.size() - 1;
        while (l < r) {
            if (nums[l] + nums[r] < two_sum) {
                ++l;
            } else if (nums[l] + nums[r] > two_sum) {
                --r;
            } else {
                vector<int> tmp;
                tmp.push_back(nums[i]);
                tmp.push_back(nums[l]);
                tmp.push_back(nums[r]);
                ret.push_back(tmp);
                while (l < r && nums[l] == nums[l+1]) ++l;
                while (l < r && nums[r] == nums[r-1]) --r;
                ++l;
                --r;
            }
        }
    }
    return ret;
}

void show(vector<vector<int> > &vv) {
    for (size_t i = 0; i < vv.size(); ++i) {
        cout << vv[i] << "\n";
    }
}

int main(int argc, char *argv[]) {
    string s(argv[1]);
    s = TrimString(s, "[ ]");
    vector<string> vs = SplitString(s, ",");
    vector<int> vi;
    for (size_t i = 0; i < vs.size(); ++i) {
        vi.push_back(StringToInt(vs[i]));
    }
    cout << vi << endl;
    vector<vector<int>> ret = threeSum(vi);
    cout << "result:\n";
    show(ret);
}
