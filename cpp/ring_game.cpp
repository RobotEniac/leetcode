// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2022/11/22 15:56:37
// Description: https://leetcode.cn/problems/K8GULz/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

uint64_t score(vector<uint64_t>& cha, int left, int right, uint64_t s) {
    if (left == right) {
        return s;
    }
    int ll = left == 0 ? cha.size() - 1 : left - 1;
    int rr = (right+1) % cha.size();
    int ret = -1;
    if (cha[ll] <= s) {
        ret = score(cha, ll, right, s | cha[ll]);
    }
}

long long ringGame(vector<long long>& challenge) {
    return 0;
}

int main(int argc, char *argv[]) {
    vector<uint64_t> cha = {5,4,6,2,7};
    cout << ringGame(cha) << endl;
}
