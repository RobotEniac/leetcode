// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/06/26 15:58:42
// Description: https://leetcode.cn/problems/k-closest-points-to-origin/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int qsort(vector<int64_t>& v, int s, int e, int k) {
    int64_t p = v[e-1];
    int l = s;
    int i = s;
    while (i < e-1) {
        if (v[i] < p) {
            if (i != l) {
                int t = v[l];
                v[l] = v[i];
                v[i] = t;
            }
            ++l;
        }
        ++i;
    }
    v[e-1] = v[l];
    v[l] = p;
    return l+1;
}

void show(const vector<vector<int>> &v) {
    for (int i = 0; i < v.size(); ++i) {
        if (i != 0) {
            cout << ", ";
        }
        cout << "(" << v[i][0] << "," << v[i][1] << ")";
    }
    cout << endl;
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    if (k > points.size()) {
        return points;
    }
    vector<int64_t> vp(points.size(), 0);
    vector<int> idx(points.size(), 0);
    for (int i = 0; i < points.size(); ++i) {
        vp[i] = points[i][0] * points[i][0] + points[i][1] * points[i][1];
        idx[i] = i;
    }
    int s = 0;
    int e = idx.size();
    vector<vector<int>> ret;
    while (s < e) {
        int64_t p = idx[e-1];
        int l = s;
        int i = s;
        while (i < e-1) {
            if (vp[idx[i]] < vp[p]) {
                if (i != l) {
                    int t = idx[l];
                    idx[l] = idx[i];
                    idx[i] = t;
                }
                ++l;
            }
            ++i;
        }
        idx[e-1] = idx[l];
        idx[l] = p;
        ++l;
        cout << idx << ", " << s << " " << l << " " << e << endl;
        if (l-s == k) {
            for (int i = s; i < l; ++i) {
                vector<int> pt(2, 0);
                pt[0] = points[idx[i]][0];
                pt[1] = points[idx[i]][1];
                ret.push_back(pt);
            }
            break;
        } else if (l-s < k) {
            for (int i = s; i < l; ++i) {
                vector<int> pt(2, 0);
                pt[0] = points[idx[i]][0];
                pt[1] = points[idx[i]][1];
                ret.push_back(pt);
            }
            k = k - (l - s);
            s = l;
        } else {
            e = l-1;
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<vector<int>> pts = {{1,3}, {2,-2}, {-2,2}};
    vector<vector<int>> r = kClosest(pts, 2);
    show(r);
}
