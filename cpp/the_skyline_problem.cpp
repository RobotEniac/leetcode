// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/08/06 21:39:02
// Description: https://leetcode.com/problems/the-skyline-problem/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

vector<vector<int> > getSkyline(vector<vector<int> >& buildings) {
    vector<vector<int> > ret;
    if (buildings.empty()) {
        return ret;
    }
    int left = INT_MAX;
    int right = INT_MIN;
    std::map<int, int> m;
    for (int i = 0; i < buildings.size(); ++i) {
        int l = buildings[i][0];
        int r = buildings[i][1];
        int h = buildings[i][2];
        for (int j = l; j < r; ++j) {
            auto it = m.find(j);
            if (it == m.end()) {
                m[j] = h;
            } else {
                if (it->second < h) {
                    m[j] = h;
                }
            }
        }
        if (l < left) {
            left = l;
        }
        if (r > right) {
            right = r;
        }
    }

    int f = left;
    int hf = m[f];
    ret.push_back({f, hf});
    for (int i = left+1; i <= right; ++i) {
        auto it = m.find(i);
        int h = 0;
        if (it != m.end()) {
            h = it->second;
        }
        if (h != hf) {
            f = i;
            hf = h;
            ret.push_back({f, hf});
        }
    }
    return ret;
}

vector<vector<int> > getSkyline2(vector<vector<int> >& buildings) {
    vector<vector<int> > ret;
    if (buildings.empty()) {
        return ret;
    }
    for (int i = 0; i < buildings.size(); ++i) {
        vector<vector<int> > vt;
        for (int ri = 0; ri < ret.size(); ++ri) {
        }
    }
}


void show(vector<vector<int> > &v) {
    cout << "[";
    for (int i = 0; i < v.size(); ++i) {
        if (i != 0) {
            cout << ", ";
        }
        cout << "[";
        for (int j = 0; j < v[i].size(); ++j) {
            if (j != 0) {
                cout << " ";
            }
            cout << v[i][j];
        }
        cout << "]";
    }
    cout << "]\n";
}

int main(int argc, char *argv[]) {
    vector<vector<int> > v = { {2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8} };
    vector<vector<int> > expected = { {2,10}, {3,15}, {7,12}, {12,0}, {15,10}, {20,8}, {24,0} };
    show(v);
    vector<vector<int> > res = getSkyline(v);
    show(expected);
    show(res);
}
