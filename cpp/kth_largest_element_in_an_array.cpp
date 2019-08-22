// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/08/06 11:28:38
// Description: https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "util.h"

using namespace std;

void swap(vector<int>& nums, int i, int j) {
    if (i == j) {
        return;
    }
    int t = nums[i];
    nums[i] = nums[j];
    nums[j] = t;
}

int quick(vector<int>& nums, int s, int e, int k) {
    if (e - s <= 1) {
        return nums[s];
    }
    int st = nums[s];
    int l = s;
    for (int i = s+1; i < e; ++i) {
        if (nums[i] >= st) {
            swap(nums, ++l, i);
        }
    }
    swap(nums, s, l);
    if (l-s+1 == k) {
        return nums[l];
    }
    if (l-s+1 < k) {
        return quick(nums, l+1, e, k-(l+1-s));
    }
    if (l+1-s > k) {
        return quick(nums, s, l, k);
    }
    return 0;
}

int findKthLargest(vector<int>& nums, int k) {
    if (k <= 0) {
        return -1;
    }
    return quick(nums, 0, nums.size(), k);
}

int find(vector<int>& nums, int k) {
    if (k <= 0)
        return -1;
    sort(nums.begin(), nums.end(), [](int a, int b) -> bool { return a > b; });
    return nums[k-1];
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    srand(time(NULL));
    vector<int> a = {3,2,1,5,6,4};
    for (int i  = 0; i < n; ++i) {
        // a[i] = rand() % 100;
    }
    cout << "a: " << a << endl;
    vector<int> b = a;
    cout << "quick: " << findKthLargest(b, k) << endl;
    cout << "b: " << b << endl;
    vector<int> c = a;
    cout << "sort: " << find(c, k) << endl;
    cout << "c: " << c << endl;
}
