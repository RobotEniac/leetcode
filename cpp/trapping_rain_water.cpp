// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/07/01 14:28:04
// Description: https://leetcode-cn.com/problems/trapping-rain-water/

#include <iostream>
#include <vector>
#include <string>
#include <stack>

#include "util.h"

using namespace std;

int trap(vector<int>& height) {
    int total = 0;
    for (int i = 0; i < height.size(); ++i) {
        int l = i - 1;
        int hl = height[i];
        while (l >= 0) {
            if (height[l] > hl) {
                hl = height[l];
            }
            --l;
        }
        if (hl == height[i]) {
            continue;
        }
        int r = i+1;
        int hr = height[i];
        while (r < height.size()) {
            if (height[r] > hr) {
                hr = height[r];
            }
            ++r;
        }
        if (hr == height[i]) {
            continue;
        }
        total += std::min(hl, hr) - height[i];
    }
    return total;
}

int trap2(vector<int>& height) {
    int total = 0;
    stack<int> s;
    for (int i = 0; i < height.size(); ++i) {
        if (s.empty()) {
            s.push(i);
            continue;
        }
        if (height[i] <= height[s.top()]) {
            s.push(i);
        } else {
            int h = 0;
            while (!s.empty() && height[i] > height[s.top()]) {
                int t = s.top();
                s.pop();
                int hh = min(height[i], height[t]);
                total += (i - t - 1) * (hh - h);
                h = height[t];
            }
            if (!s.empty()) {
                int hh = min(height[i], height[s.top()]);
                total += (i - s.top() - 1) * (hh - h);
            }
            s.push(i);
        }
    }
    return total;
}

int main(int argc, char *argv[]) {
    // vector<int> h = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> h = {4,2,0,3,2,5};
    cout << trap(h) << endl;
    cout << trap2(h) << endl;
}
