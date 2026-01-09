// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2026/01/07 15:56:31
// Description: https://leetcode.cn/problems/greatest-sum-divisible-by-three/description/?envType=daily-question&envId=2026-01-07

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int maxSumDivThree(vector<int> &nums) {
    sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });
    vector<int> r1;
    vector<int> r2;
    int t3 = 0;
    int t1 = 0;
    int t2 = 0;
    r1.push_back(t1);
    r2.push_back(t2);
    for (int i = 0; i < nums.size(); ++i) {
        int r = nums[i] % 3;
        if (r == 0) {
            t3 += nums[i];
        } else if (r == 1) {
            t1 += nums[i];
            r1.push_back(t1);
        } else {
            t2 += nums[i];
            r2.push_back(t2);
        }
    }
    int ret = t3;
    for (int l1 = r1.size()-1; l1 >= (int)r1.size()-3; --l1) {
        for (int l2 = r2.size()-1; l2 >= (int)r2.size()- 3; --l2) {
            cout << l1 << ", " << l2 << endl;
            if (l1 <= 0 && l2 <= 0) {
                continue;
            }
            if (l1 <= 0) {
                if (r2[l2] % 3 == 0) {
                    if (t3 + r2[l2] > ret) {
                        ret = t3 + r2[l2];
                    }
                }
            } else if (l2 <= 0) {
                if (r1[l1] % 3 == 0) {
                    if (t3 + r1[l1] > ret) {
                        ret = t3 + r1[l1];
                    }
                }
            } else {
                if ((r1[l1] + r2[l2]) % 3 == 0) {
                    if (t3 + r1[l1] + r2[l2] > ret) {
                        ret = t3 + r1[l1] + r2[l2];
                    }
                }
            }
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<int> v = {3,6,5,1,8};
    cout << maxSumDivThree(v) << endl;
}
