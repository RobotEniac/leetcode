// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/10/11 10:25:22
// Description: https://leetcode.cn/problems/avoid-flood-in-the-city/description/?envType=daily-question&envId=2025-09-29

#include <iostream>
#include <vector>
#include <string>
#include <set>

#include "util.h"

using namespace std;

vector<int> avoidFlood(vector<int> &rains) {
    vector<int> ret;
    set<int> st;
    int l = 0;
    int r = 0;
    while (l < rains.size() && rains[l] == 0) {
        ++l;
        ret.push_back(-1);
    }
    while (l < rains.size()) {
        while (l < rains.size() && rains[l] != 0) {
            if (st.find(rains[l]) != st.end()) {
                return vector<int>();
            } else {
                st.insert(rains[l]);
                ret.push_back(-1);
            }
            ++l;
        }
        r = l;
        while (r < rains.size() && rains[r] == 0) {
            ++r;
        }
        if (r == l) {
            continue;
        }
        while (r < rains.size() && rains[l] == 0) {
            if (st.find(rains[r]) != st.end()) {
                st.erase(rains[r]);
                ret.push_back(rains[r]);
                ++l;
            }
            ++r;
        }
        while (l < rains.size() && rains[l] == 0) {
            if (!st.empty()) {
                ret.push_back(*st.begin());
                st.erase(st.begin());
            }
            else
            {
                ret.push_back(1);
            }
            ++l;
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<int> r = {3,5,4,0,1,0,1,5,2,8,9};
    cout << avoidFlood(r) << endl;
}
