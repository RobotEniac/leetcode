// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/10/22 22:10:46
// Description: https://leetcode-cn.com/problems/find-right-interval/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "util.h"

using namespace std;

void show(vector<vector<int>> &v) {
    cout << "[";
    for (int i = 0; i < v.size(); ++i) {
        if (i != 0) {
            cout << ", ";
        }
        cout << "(" << v[i][0] << ", " << v[i][1] << ")";
    }
    cout << "]\n";
}

bool comp(const vector<int>& v1, const vector<int>& v2) {
    return v1[0] < v2[0];
}

int find(vector<vector<int>> &m, int e) {
    if (e < m[0][0] || m[m.size() - 1][0] < e) {
        return -1;
    }
    int l = 0;
    int r = m.size();
    int count = 0;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (m[mid][0] == e) {
            return m[mid][1];
        }
        if (m[mid][0] < e) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    if (m[l][0] < e) {
        return m[l+1][1];
    }
    return m[l][1];
}

vector<int> findRightInterval(vector<vector<int>>& intervals) {
    vector<int> ret;
    int is = intervals.size();
    vector<vector<int>> m(is, vector<int>(2, 0));
    for (int i = 0; i < is; ++i) {
        m[i][0] = intervals[i][0];
        m[i][1] = i;
    }
    sort(m.begin(), m.end(), comp);
    for (int i = 0; i < intervals.size(); ++i) {
        ret.push_back(find(m, intervals[i][1]));
    }
    return ret;
}

int main(int argc, char *argv[]) {
    // vector<vector<int> > intervals = {{1,2},{2,3},{0,1},{3,4}};
    vector<vector<int> > intervals = {{1,12},{2,9},{3,10},{13,14},{15,16},{16,17}};
    cout << findRightInterval(intervals) << endl;
}
