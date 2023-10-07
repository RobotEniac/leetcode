// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/07/20 17:30:39
// Description: https://leetcode.cn/problems/valid-square/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int length(vector<int>& x, vector<int>& y) {
    return (x[0] - y[0]) * (x[0] - y[0]) + (x[1] - y[1])*(x[1] - y[1]);
}


bool valid(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    bool b1 = length(p1, p2) == length(p2, p3)
        && length(p1, p2) == length(p3, p4)
        && length(p1, p2) == length(p1, p4);
    bool b2 = (p1[0] - p2[0]) * (p4[1] - p3[1]) == (p1[1] - p2[1]) * (p4[0] - p3[0])
        && (p1[0] - p4[0]) * (p2[1] - p3[1]) == (p1[1] - p4[1]) * (p2[0] - p3[0]);
    bool b3 = (p2[0] - p1[0]) * (p3[0] - p2[0]) == (p2[1] - p1[1]) * (p3[1] - p2[1]) * (-1);
    return b1 && b2 && b3;
}

bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    return valid(p1, p2, p3, p4) || valid(p1, p2, p4, p3) || valid(p1, p3, p2, p4);
}


int main(int argc, char *argv[]) {
    vector<int> p1 = {0, 0};
    vector<int> p2 = {0, 1};
    vector<int> p3 = {1, 1};
    vector<int> p4 = {1, 0};
    cout << boolalpha << validSquare(p1, p3, p2, p4) << endl;
}
