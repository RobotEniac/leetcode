// =====================================================
//       Filename:  majority_number.cpp
//         Author:  wuhaibo <gethaibo@gmail.com>
//        Created:  2017/11/17
//    Description:  
//    Copyright (c) 2017, NONE, All rights reserved. 
// =====================================================

#include "util.h"
#include <time.h>

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int majorityNumber(vector<int> &nums) {
    map<int, int> count_map;
    int max_count = INT_MIN;
    for (size_t i = 0; i < nums.size(); ++i) {
        map<int, int>::iterator it = count_map.find(nums[i]);
        if (it != count_map.end()) {
            count_map[nums[i]] += 1;

        } else {
            count_map[nums[i]] = 1;
        }
        if (count_map[nums[i]] > nums.size() / 2) {
            return nums[i];
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    vector<int> a;
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        a.push_back(rand() % 3);
    }
    cout << a << endl;
    cout << majorityNumber(a) << endl;
}

