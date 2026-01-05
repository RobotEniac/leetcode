// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/06/12 20:27:40
// Description: https://leetcode.cn/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/?envType=daily-question&envId=2025-06-12

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int maxAdjacentDistance(vector<int>& a) {
    int mm = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (i == 0) {
            int t = abs(a[i] - a[a.size()-1]);
            if (t > mm) {
                mm = t;
            }
        } else {
            int t = abs(a[i] - a[i-1]);
            if (t > mm) {
                mm = t;
            }
        }
    }
    return mm;
}

int main(int argc, char *argv[]) {
    cout << "hello world" << endl;
}
