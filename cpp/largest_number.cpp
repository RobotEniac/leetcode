// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/04/26 20:20:26
// Description: https://leetcode.com/problems/largest-number/

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <sstream>

#include "util.h"

using namespace std;

bool comp (int x, int y) {
    int tx = x;
    int ty = y;
    int mx = x == 0 ? 10 : 1;
    int my = y == 0 ? 10 : 1;
    while (tx > 0) {
        mx *= 10;
        tx /= 10;
    }
    while (ty > 0) {
        my *= 10;
        ty /= 10;
    }
    int x_first = x * my + y;
    int y_first = y * mx + x;
    cout << x_first << ", " << y_first << "\n";
    if (x_first > y_first) {
        return true;
    } 
    return false;
}

string largestNumber(vector<int>& nums) {
    std::sort(nums.begin(), nums.end(), comp);
    std::stringstream ss;
    for (int i = 0; i < nums.size(); ++i) {
        ss << nums[i];
    }
    return ss.str();
}

int main(int argc, char *argv[]) {
    vector<int> a = {0,1,2,3,4,5,6,7,8,9};
    cout << a << endl;
    cout << largestNumber(a) << endl;
}
