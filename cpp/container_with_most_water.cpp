// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/08/06 16:15:26
// Description: https://leetcode-cn.com/problems/container-with-most-water/

#include <iostream>
#include <vector>
#include <string>
#include <stack>

#include "util.h"

using namespace std;

int maxArea(vector<int>& height) {
    int l = 0;

        if (height[l] <= height[r]) {
            int a = height[l] * (r - l);
            if (amax < a) {
                amax = a;
            }
            ++l;
        } else {
            int a = height[r] * (r - l);
            if (amax < a) {
                amax = a;    int r = height.size() - 1;
    int amax = 0;
    while (l < r) {
        if (height[l] <= height[r]) {
            int a = height[l] * (r - l);
            if (amax < a) {
                amax = a;
            }
            ++l;
        } else {
            int a = height[r] * (r - l);
            if (amax < a) {
                amax = a;
            }
            --r;
        }
    }
    return amax;
}

int main(int argc, char *argv[]) {
    vector<int> h = {1,8,6,2,5,4,8,3,7};
    cout << h << "\n";
    cout << "maxArea = " << maxArea(h) << "\n";
}
