// =====================================================
//       Filename:  partition_array.cpp
//         Author:  wuhaibo <gethaibo@gmail.com>
//        Created:  2017/11/16
//    Description:  
//    Copyright (c) 2017, NONE, All rights reserved. 
// =====================================================

#include "util.h"
#include <iostream>
#include <vector>

using namespace std;

int partitionArray(vector<int> &num, int k) {
    int left = 0;
    int right = 0;
    while (right < num.size()) {
        if (num[right] < k) {
            int t = num[left];
            num[left] = num[right];
            num[right] = t;
            ++left;
        } 
        ++right;
    }
    return left;
}

int partitionBetween(vector<int> &num, int start, int end, int p) {
    int left = start;
    int right = start;
    while (right < end) {
        if (num[right] < p) {
            int t = num[left];
            num[left] = num[right];
            num[right] = t;
            ++left;
        }
        ++right;
    }
    return left;
}

void sortBetween(vector<int> &num, int start, int end) {
    if (end - start < 2) {
        return;
    }
    int p = num[end - 1];
    int r = partitionBetween(num, start, end - 1, p);
    num[end - 1] = num[r];
    num[r] = p;
    sortBetween(num, start, r);
    sortBetween(num, r + 1, end);
}
void sort(vector<int> &nums) {
    sortBetween(nums, 0, nums.size());
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        a.push_back(rand() % 10);
    }
    cout << a << endl;
    sort(a);
    cout << a << endl;
}

