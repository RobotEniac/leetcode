// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/02/29 22:08:18
// Description: https://leetcode.com/problems/find-median-from-data-stream/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

 class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
        v.push_back(num);
        int i = v.size() - 2;
        while (i >= 0 && v[i] > num) {
            v[i+1] = v[i];
            --i;
        }
        v[i+1] = num;
    }

    double findMedian() {
        if (v.empty()) {
            return 0;
        }
        int l = v.size();
        int mid = l / 2;
        if (l % 2 == 0) {
            return ((double)v[mid] + v[mid-1]) / 2;
        }
        return (double)v[mid];
    }

    vector<int> data() {
        return v;
    }

private:
    std::vector<int>  v;
};

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    if (argc > 2) {
        uint64_t seed = atoi(argv[2]);
        srand(seed);
    }
    MedianFinder f;
    for (int i = 0; i < n; ++i) {
        int r = rand() % 100;
        f.addNum(r);
        cout << r << ", ";
        cout << f.data() << ", ";
        cout << f.findMedian() << endl;
    }
}
