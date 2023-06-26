// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/06/26 11:30:39
// Description: https://leetcode.cn/problems/number-of-excellent-pairs/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"
#include "file_util.hpp"

using namespace std;

int cal(int n1, int n2) {
    int ret = 0;
    cout << n1 << ", " << n2;
    while (n1 != 0 || n2 != 0) {
        if ((n1 & 1) == 1 && (n2 & 1) == 1) {
            ret += 2;
        } else if (n1 & 1 != 0 || n2 & 1 != 0) {
            ++ret;
        }
        n1 = n1 >> 1;
        n2 = n2 >> 1;
    }
    cout << "=>" << ret << endl;
    return ret;
}

int remove_dup(vector<int>& a) {
    sort(a.begin(), a.end());
    int l = 0;
    int i = 1;
    while (i < a.size()) {
        if (a[i] != a[l]) {
            ++l;
            if (i != l) {
                int t = a[l];
                a[l] = a[i];
                a[i] = t;
            }
        }
        ++i;
    }
    return l+1;
}

long long countExcellentPairs(vector<int>& nums, int k) {
    int ret = 0;
    int l = remove_dup(nums);
    cout << nums << ", " << l << endl;
    for (int i = 0; i < l; ++i) {
        for (int j = i; j < l; ++j) {
            if (cal(nums[i], nums[j]) >= k) {
                if (nums[i] == nums[j]) {
                    ++ret;
                } else {
                    ret += 2;
                }
            }
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<int> a = lc::ReadArrayInt("ttt");
    cout << countExcellentPairs(a, 56) << endl;
}
