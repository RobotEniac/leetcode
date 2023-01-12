// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2022/11/29 16:48:16
// Description: https://leetcode.cn/problems/bitwise-xor-of-all-pairings/submissions/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() & 0x1 == 0 && nums2.size() & 0x1 == 0) {
        return 0;
    }
    if (nums1.size() & 0x1 == 0 && nums2.size() & 0x1 != 0) {
        int ret = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            ret = ret ^ nums1[i];
        }
        return ret;
    }
    if (nums1.size() & 0x1 != 0 && nums2.size() & 0x1 == 0) {
        int ret = 0;
        for (int i = 0; i < nums2.size(); ++i) {
            ret = ret ^ nums2[i];
        }
        return ret;
    }
    int ret;
    for (int i = 0; i < nums1.size(); ++i) {
        ret = ret ^ nums1[i];
    }
    for (int i = 0; i < nums2.size(); ++i) {
        ret = ret ^ nums2[i];
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<int> v1 = {2,1,3};
    vector<int> v2 = {10,2,5,0};
    cout << xorAllNums(v1, v2) << endl;
}
