// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/05/25 10:38:12
// Description: https://leetcode.cn/problems/SsGoHC/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

void show(vector<vector<int>> &v) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << endl;
    }
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [] (vector<int>& l, vector<int>& r) {
         return l[0] < r[0];
         });
    show(intervals);
    vector<vector<int> > ret;
    int i = 0;
    while (i < intervals.size()) {
        int l = intervals[i][0];
        int r = intervals[i][1];
        while (i < intervals.size() && intervals[i][0] == l) {
            r = max(r, intervals[i][1]);
            ++i;
        }
        while (i < intervals.size() && r >= intervals[i][0]) {
            r = max(r, intervals[i][1]);
            ++i;
        }
        vector<int> t(2, 0);
        t[0] = l;
        t[1] = r;
        ret.push_back(t);
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<vector<int> > a = {{1,3},{8,10},{2,6},{15,18}};
    vector<vector<int> > r = merge(a);
    show(r);
}
