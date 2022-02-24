// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2022/02/16 10:40:09
// Description: https://leetcode-cn.com/problems/kth-missing-positive-number/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    if (arr.empty()) {
        return k;
    }
    if (arr[0] > k) {
        return k;
    }
    int cnt = arr[0] - 1;
    for (int i = 1; i < arr.size(); ++i) {
        cnt += arr[i] - arr[i-1] - 1;
        if (cnt >= k) {
            return k + i;
        }
    }
    return k + arr.size();
}

int main(int argc, char *argv[]) {
    vector<int> a = {1, 3};
    cout << findKthPositive(a, 1) << endl;
}
