// =====================================================
//       Filename:  two_non_overlaping.cpp
//         Author:  wuhaibo <gethaibo@gmail.com>
//        Created:  2017/11/02
//    Description:  
//    Copyright (c) 2017, NONE, All rights reserved. 
// =====================================================

#include "util.h"

#include <vector>
#include <iostream>

using namespace std;

int subMaxSum(vector<int> &ary, int start, int end) {
    if (start == end) {
        return 0;
    }
    int sum = 0;
    int max_sum = INT_MIN;
    for (int i = start; i < end; ++i) {
        sum += ary[i];
        if (sum > max_sum) {
            max_sum = sum;
        }
        if (sum <= 0) {
            sum = 0;
        }
    }
    return max_sum;
}

int maxTwoSubArrays(vector<int>& ary) {
    int max_sum = INT_MIN;
    int i = 0;
    int left_end = 0;
    int right_start = 0;
    int neg_sum = 0;
    int sum = 0;
    while (i < ary.size() - 1) {
        while (ary[i] > 0 && i < ary.size())
            ++i;
        left_end = i;
        while (ary[i] < 0 && i < ary.size()) {
            neg_sum += ary[i];
            ++i;
        }
        right_start = i;
        if (left_end == 0 && right_start == ary.size()) {
            sum = neg_sum;
        } else {
            int sum_left = subMaxSum(ary, 0, left_end);
            int sum_right = subMaxSum(ary, right_start, ary.size());
            sum = sum_left + sum_right;
        }
        if (sum > max_sum) {
            max_sum = sum;
        }
    }
    return max_sum;
}

int main(int argc, char *argv[]) {
    vector<int> ary;
    srand(time(NULL));
    int n = atoi(argv[1]);
    for (int i = 0; i < n; ++i) {
        ary.push_back(rand() % 20 - 10);
    }
    cout << ary << endl;
    cout << maxTwoSubArrays(ary) << endl;
}

