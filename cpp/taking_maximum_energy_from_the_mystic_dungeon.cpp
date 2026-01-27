// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2026/01/16 11:29:02
// Description: https://leetcode.cn/problems/taking-maximum-energy-from-the-mystic-dungeon/description/?envType=daily-question&envId=2026-01-16

#include <iostream>
#include <vector>
#include <string>

#include "util.h"
#include "file_util.hpp"

using namespace std;

int maximumEnergy(vector<int> &energy, int k) {
    vector<int> d(energy.size(), 0);
    int mm = INT_MIN;
    for (int i = energy.size() - 1; i >= 0; --i) {
        if (energy.size() - i < k) {
            d[i] = energy[i];
        } else {
            d[i] = energy[i] + d[i+k];
        }
        if (d[i] > mm) {
            mm = d[i];
        }
    }
    return mm;
}

int main(int argc, char *argv[]) {
    vector<int> v = lc::ReadArrayString("[5,2,-10,-5,1]");
    cout << maximumEnergy(v, 3) << endl;
}
