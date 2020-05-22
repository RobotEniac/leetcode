// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/05/11 21:24:37
// Description: https://leetcode.com/problems/create-maximum-number/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

vector<int> maxArray2(vector<int>& num, int k) {
    if (num.size() == k) {
        return num;
    }
    if (num[0] < num[1]) {
        vector<int> sub(num.begin()+1, num.end());
        return maxArray2(sub, k);
    }
    int p = 0;
    while (p < num.size()-1 && num[p] > num[p+1]) {
        ++p;
    }
    vector<int> sub;
    for (int i = 0; i < num.size(); ++i) {
        if (i != p) {
            sub.push_back(num[i]);
        }
    }
    return maxArray2(sub, k);
}


vector<int> maxArray(vector<int>& num, int k) {
    vector<int> ret(k, 0);
    for (int i = 0, j = 0; i < num.size(); ++i) {
        if (j == 0) {
            ret[j++] = num[i];
            continue;
        }
        while (j > 0 && ret[j-1] < num[i] && num.size() - i > k - j) {
            --j;
        }
        if (j < k) {
            ret[j++] = num[i];
        }
    }
    return ret;
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> ret;
    return ret;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        v.push_back(rand() % 10);
    }
    cout << v << endl;
    cout << maxArray(v, k) << endl;
    cout << maxArray2(v, k) << endl;
}
