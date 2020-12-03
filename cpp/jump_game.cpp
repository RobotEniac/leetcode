// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/09/02 16:26:05
// Description: https://leetcode.com/problems/jump-game/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"
#include "file_util.h"

using namespace std;

bool canJump(vector<int>& nums) {
    if (nums.size() < 2) {
        return true;
    }
    int max_reach = 0;
    for (int i = 0; i < nums.size() && i <= max_reach; ++i) {
        max_reach = max(i + nums[i], max_reach);
        if (max_reach >= nums.size() - 1) {
            break;
        }
    }
    return max_reach >= nums.size()-1;
}

int main(int argc, char *argv[]) {
    vector<int> nums;
    string input = leetcode::ReadAll("/Users/haibo/tmp/in.txt");
    vector<string> vs = leetcode::SplitString(input, ",");
    cout << "input size = " << vs.size() << endl;
    for (size_t i = 0; i < vs.size(); ++i) {
        nums.push_back(leetcode::StringToInt32(vs[i]));
    }
    cout << nums << endl;
    cout << boolalpha << canJump(nums) << "\n";
}
