// Copyright (c) 2020, Personal Developer
// All rights reserved.
//
// Author: RobotEniac <gethaibo@gmail.com>
// Created: 09/17/20
// Description: https://www.geeksforgeeks.org/find-maximum-minimum-sum-subarray-size-k/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int maxSubarray(vector<int> &a, int k) {
    if (a.size() < k) {
        return 0;
    }
    int sum = 0;
    for (int i = 0; i < a.size() && a < k; ++i) {
        sum += a[i];
    }
    int max_sum = sum;
    for (int i = k; i < a.size(); ++i) {
        sum += a[i] - a[i-k];
        if (sum > max_sum) {
            max_sum = sum;
        }
    }
    return max_sum;
}

int main(int argc, char *argv[]) {
    cout << "hello world" << endl;
}
