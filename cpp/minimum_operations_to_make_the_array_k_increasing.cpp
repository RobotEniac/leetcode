// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/10/08 21:16:31
// Description: https://leetcode.cn/problems/minimum-operations-to-make-the-array-k-increasing/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

bool check(vector<int>& a, int k, int begin) {
    for (int i = begin; i < a.size()-k; i += k) {
        if (a[i] > a[i+k]) {
            return false;
        }
    }
    return true;
}

int kIncreasing(vector<int>& arr, int k) {
    bool is_ok = true;
    int cnt = 0;
    for (int i = 0; i < k; ++i) {
        cout << arr << endl;
        for (int j = i; j < arr.size() - k; j += k) {
            if (arr[j] > arr[j+k]) {
                int mm = max(arr[j], arr[j+k]);
                if (arr[j+k] != mm) {
                    arr[j+k] = mm;
                    ++cnt;
                }
                is_ok = false;
            }
        }
        cout << arr << endl;
    }
    if (is_ok) {
        return 0;
    }
    return cnt;
}

int main(int argc, char *argv[]) {
    vector<int> a = {12,6,12,6,14,2,13,17,3,8,11,7,4,11,18,8,8,3};
    cout << a.size() << endl;
    cout << kIncreasing(a, 1) << endl;
}
