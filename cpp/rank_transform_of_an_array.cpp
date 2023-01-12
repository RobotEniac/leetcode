// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2022/11/09 14:46:13
// Description: https://leetcode.cn/problems/rank-transform-of-an-array/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

void show(vector<int>& idx, vector<int>& a) {
    for (int i = 0; i < idx.size(); ++i) {
        if (i != 0) {
            cout << ", ";
        }
        cout << a[idx[i]];
    }
    cout << endl;
}

vector<int> arrayRankTransform(vector<int>& arr) {
    vector<int> idx(arr.size(), 0);
    for (int i = 0; i < arr.size(); ++i) {
        idx[i] = i;
    }
    sort(idx.begin(), idx.end(), [&] (int l, int r) { return arr[l] < arr[r]; });
    vector<int> ret(arr.size(), 0);
    int c = 1;
    for (int i = 0; i < idx.size(); ++i) {
        if (i == 0) {
            ret[idx[i]] = c;
        } else if (arr[idx[i]] == arr[idx[i-1]]) {
            ret[idx[i]] = c;
        } else {
            ret[idx[i]] = ++c;
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<int> a = {37,12,28,9,100,56,80,5,12};
    cout << arrayRankTransform(a) << endl;
}
