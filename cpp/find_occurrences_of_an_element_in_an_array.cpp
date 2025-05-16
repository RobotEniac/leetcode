// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/05/15 14:25:47
// Description: https://leetcode.cn/problems/find-occurrences-of-an-element-in-an-array/description/?envType=daily-question&envId=2025-05-14

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

vector<int> occurrencesOfElement(vector<int>& nums,
                                 vector<int>& queries,
                                 int x)
{
    vector<int> pos;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == x) {
            pos.push_back(i);
        }
    }
    vector<int> ret;
    for (int i = 0; i < queries.size(); ++i) {
        if (queries[i] <= 0 || queries[i] > pos.size()) {
            ret.push_back(-1);
        } else {
            ret.push_back(pos[queries[i]-1]);
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<int> a = {1,3,1,7};
    vector<int> q = {1,3,2,4};
    cout << occurrencesOfElement(a, q, 1) << endl;
}
