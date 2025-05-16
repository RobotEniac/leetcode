// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/05/14 20:02:09
// Description: https://leetcode.cn/problems/total-characters-in-string-after-transformations-ii/description/?envType=daily-question&envId=2025-05-14

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

string convert(char c, int n) {
    string ret;
    for (int i = 0; i < n; ++i) {
        ret.push_back((((int)(c-'a') + i + 1) % 26) + 'a');
    }
    return ret;
}

int64_t add(int64_t a, int64_t b) {
    const static int64_t M = 1000000007;
    return ((a%M) + (b%M)) % M;
}

int lengthAfterTransformations(string s, int t, vector<int>& nums) {
    if (t == 0) {
        return s.size();
    }
    vector<int64_t> c(26, 0);
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < nums[s[i] - 'a']; ++j) {
            int t = ((int)(s[i]-'a')+j+1) % 26;
            ++c[t];
        }
    }
    for (int i = 1; i < t; ++i) {
        vector<int64_t> temp_count(26, 0);
        for (int j = 0; j < c.size(); ++j) {
            if (c[j] != 0) {
                for (int k = 0; k < nums[j]; ++k) {
                    int t = (j+k+1) % 26;
                    temp_count[t] = add(temp_count[t], c[j]);
                }
            }
        }
        cout << c << endl;
        c = temp_count;
    }
    int64_t ret = 0;
    for (int i = 0; i < c.size(); ++i) {
        ret = add(ret, c[i]);
    }
    return ret;
}

int main(int argc, char *argv[]) {
    cout << add(878415231, 1020369020) << endl;
    cout << 1000000007 << endl;
    vector<int> num = {6,6,8,1,9,9,10,3,9,4,8,5,2,8,10,2,6,8,2,3,3,7,2,6,4,2};
    cout << lengthAfterTransformations("x", 16, num) << endl;
    vector<int> num2 = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2};
    cout << lengthAfterTransformations("abcyy", 2, num2) << endl;
}
