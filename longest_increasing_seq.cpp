// =====================================================
//       Filename:  longest_increasing_seq.cpp
//         Author:  wuhaibo <gethaibo@gmail.com>
//        Created:  2017/11/30
//    Description:  
//    Copyright (c) 2017, NONE, All rights reserved. 
// =====================================================

#include <iostream>
#include <vector>

#include "util.h"

using namespace std;

int longestIncreasingSubsequence(vector<int>& nums) {
    if (nums.size() < 2) {
        return nums.size();
    }
    int n = nums.size();
    vector<int> lis(n, 1);
    vector<int> note(n, -1);
    lis[0] = 1;
    note[0] = -1;
    int max_len = 1;
    int lis_end_index = 0;
    for (int i = 1; i < n; ++i) {
        int tmp_max = 1;
        int tmp_lis_end = -1;
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                if (lis[j] + 1 > tmp_max) {
                    tmp_max = lis[j] + 1;
                    tmp_lis_end = j;
                }
            }
        }
        lis[i] = tmp_max;
        note[i] = tmp_lis_end;
        if (tmp_max > max_len) {
            max_len = tmp_max;
            lis_end_index = i;
        }
    }
    cout << lis << "\n";
    cout << note << "\n";
    list<int> res;
    int prev = lis_end_index;
    while (prev >= 0) {
        res.push_front(nums[prev]);
        prev = note[prev];
    }
    cout << res << "\n";
    return max_len;
}

int LIS(vector<int> &nums) {
    vector<int> memo(nums.size(), 0);
    memo[0] = 1;
    int max_len = 0;
    for (int i = 1; i < nums.size(); ++i) {
        int tmp_max = 1;
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                if (memo[j] + 1 > tmp_max) {
                    tmp_max = memo[j] + 1;
                }
            }
        }
        memo[i] = tmp_max;
        if (memo[i] > max_len) {
            max_len = memo[i];
        }
    }
    return max_len;
}

int CeilIndex(vector<int> &vec, int s, int e, int elem) {
    if (s >= e) {
        return -1;
    }
    for (size_t i = s; i < e; ++i) {
        if (vec[i] >= elem) {
            return i;
        }
    }
    return e;
}

int LIS_2(vector<int> &vec) {
    vector<int> tail(vec.size(), 0);
    int length = 0;
    tail[length++] = vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        int ceil = -1;
        if (vec[i] > tail[length - 1]) {
            tail[length++] = vec[i];
        } else if ( (ceil = CeilIndex(tail, 0, length, vec[i])) > 0) {
            tail[ceil] = vec[i];
        }
    }
    return length;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    srand(time(NULL));
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % 10 + 1;
    }
    cout << a << endl;
    int max_len = longestIncreasingSubsequence(a);
    cout << max_len << endl;
    cout << LIS(a) << endl;
    cout << LIS_2(a) << endl;
}
