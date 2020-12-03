// =====================================================
//       Filename:  max_sub_array.cpp
//         Author:  wuhaibo <gethaibo@gmail.com>
//        Created:  2017/10/31
//    Description:  
//    Copyright (c) 2017, NONE, All rights reserved. 
// =====================================================

#include <time.h>

#include <iostream>
#include <string>

#include "util.h"

using namespace std;

vector<int> maxSubArraySimple(vector<int> &array) {
    vector<int> ret;
    int start = 0;
    int end = 0;
    int sum = 0;
    int max_sum = INT_MIN;
    for (int len = 1; len <= array.size(); ++len) {
        for (int i = 0; i <= array.size() - len; ++i) {
            int sum = 0;
            for (int j = i; j - i < len; ++j) {
                sum += array[j];
            }
            if (sum > max_sum) {
                start = i;
                end = i + len;
                max_sum = sum;
            }
        }
    }
    for (int i = start; i < end && i < array.size(); ++i) {
        ret.push_back(array[i]);
    }
    return ret;
}

vector<int> maxSubArray(vector<int>& array) {
    int sum = 0;
    int max_sum = INT_MIN;
    int max_start = 0;
    int start = 0;
    int end = 0;
    for (int i = 0; i < array.size(); ++i) {
        sum += array[i];
        if (sum > max_sum) {
            max_sum = sum;
            max_start = start;
            end = i;
        }
        if (sum <= 0) {
            start = i + 1;
            sum = 0;
        }
    }
    vector<int> ret;
    for (int i = max_start; i <= end && i < array.size(); ++i) {
        ret.push_back(array[i]);
    }
    return ret;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    vector<int> array;
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        array.push_back(rand() % 10 - 5);
    }
    cout << array << endl;
    cout << maxSubArraySimple(array) << endl;
    cout << maxSubArray(array) << endl;
}

