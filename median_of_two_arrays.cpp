// =====================================================
//       Filename:  median_of_two_arrays.cpp
//         Author:  wuhaibo <gethaibo@gmail.com>
//        Created:  2015/12/27
//    Description:  leetcode problem 4 
//    Copyright (c) 2015, NONE, All rights reserved. 
// =====================================================

#include <iostream>
#include <vector>
#include <climits>
#include "util.h"

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int median_index = (m + n - 1) / 2;
    nums1.push_back(INT_MAX);
    nums2.push_back(INT_MAX);
    if (m == 0) {
        if (n % 2 == 0) {
            return double(nums2[median_index] + nums2[median_index+1]) / 2;
        } else {
            return double(nums2[median_index]);
        }
    }
    if (n == 0) {
        if (m % 2 == 0) {
            return double(nums1[median_index] + nums1[median_index+1]) / 2;
        } else {
            return double(nums1[median_index]);
        }
    }
    int i = 0;
    int mi, ni;
    mi = ni = 0;
    while (i < median_index && mi < m && ni < n) {
        if (nums1[mi] < nums2[ni]) {
            ++mi;
            ++i;
        } else {
            ++ni;
            ++i;
        }
    }
    if (mi == m && i < median_index) {
        while (i < median_index) {
            ++ni;
            ++i;
        }
        if ((m + n) % 2 == 0) {
            return (double(nums2[ni]) + nums2[ni+1]) / 2;
        } else {
            return (double(nums2[ni]));
        }
    }
    if (ni == n && i < median_index) {
        while (i < median_index) {   
            ++mi;
            ++i;
        }
        if ((m + n) % 2 == 0) {
            return (double(nums1[mi]) + nums1[mi+1]) / 2;
        } else {
            return double(nums1[mi]);
        }
    }
    if ((m + n) % 2 == 0) {
        int median1 = nums1[mi] < nums2[ni] ? nums1[mi++] : nums2[ni++];
        int median2 = nums1[mi] < nums2[ni] ? nums1[mi++] : nums2[ni++];
        nums1.pop_back();
        nums2.pop_back();
        return double(median1 + median2) / 2;
    } else {
        int median = nums1[mi] < nums2[ni] ? nums1[mi] : nums2[ni];
        return double(median);
    }
}

int main(int argc, char* argv[]) {
    int ary1[] = {1};
    int ary2[] = {1};
    vector<int> nums1(ary1, ary1 + sizeof(ary1) / sizeof(int));
    vector<int> nums2(ary2, ary2 + sizeof(ary2) / sizeof(int));
    cout << nums1 << "\n" << nums2 << "\n";
    cout << findMedianSortedArrays(nums1, nums2) << "\n";
}
