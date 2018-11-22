// =====================================================
//       Filename:  recover_rotated_sorted_array.cpp
//         Author:  wuhaibo <gethaibo@gmail.com>
//        Created:  2017/10/31
//    Description:  
//    Copyright (c) 2017, NONE, All rights reserved. 
// =====================================================

#include "util.h"
#include <iostream>
#include <string>

using namespace std;
void Rotate(vector<int> &nums, int start, int end) {
    for (int i = start, j = end - 1; i < j; ++i, --j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}

void recoverRotatedSortedArray(vector<int> &nums) {
    int idx = 0;
    for (idx = 0; idx < nums.size() - 1; ++idx) {
        if (nums[idx] > nums[idx + 1]) break;
    }
    if (idx == nums.size() - 1) {
        return;
    }
    ++idx;
    Rotate(nums, 0, idx);
    Rotate(nums, idx, nums.size());
    Rotate(nums, 0, nums.size());
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int middle = atoi(argv[2]);
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        a.push_back(i + 1);
    }
    Rotate(a, 0, middle);
    Rotate(a, middle, n);
    Rotate(a, 0, n);
    cout << a << endl;

    recoverRotatedSortedArray(a);
    cout << a << endl;
}

