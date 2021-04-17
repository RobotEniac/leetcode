// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/04/13 11:14:56
// Description: https://leetcode-cn.com/problems/minimum-time-difference/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "util.h"

using namespace std;

struct TP {
    int hh;
    int mm;

    TP(): hh(0), mm(0) {}

    string ToString() {
        char buf[8];
        sprintf(buf, "%02d:%02d", hh, mm);
        return string(buf);
    }
};

TP ParseTP(const std::string& s) {
    TP ret;
    sscanf(s.c_str(), "%d:%d", &ret.hh, &ret.mm);
    return ret;
}

int diff(const TP& lhs, const TP& rhs) {
    return lhs.hh * 60 + lhs.mm - (rhs.hh * 60 + rhs.mm);
}

bool compare(const TP& lhs, const TP& rhs) {
    return lhs.hh * 60 + lhs.mm < rhs.hh * 60 + rhs.mm;
}

int findMinDifference(vector<string>& timePoints) {
    vector<TP> v;
    for (size_t i = 0; i < timePoints.size(); ++i) {
        TP t = ParseTP(timePoints[i]);
        v.push_back(t);
    }
    sort(v.begin(), v.end(), compare);
    int mmin = 24 * 60;
    for (size_t i = 1; i < v.size(); ++i) {
        int d = diff(v[i], v[i-1]);
        if (d < mmin) {
            mmin = d;
        }
    }
    int dt = diff(v[0], v.back()) + 24 * 60;
    if (dt < mmin) {
        mmin = dt;
    }
    return mmin;
}

inline int to_num(const string& a) {
    int x = (a[0] - '0') * 10 + a[1] - '0';
    x = x * 60 + (a[3] - '0') * 10 + a[4] - '0';
    return x;
}

int diff(const string& a, const string& b) {
    int ta = to_num(a);
    int tb = to_num(b);
    return ta - tb;
}

int findMinDifference2(vector<string>& timePoints) {
    sort(timePoints.begin(), timePoints.end());
    int mmin = 24 * 60;
    for (size_t i = 1; i < timePoints.size(); ++i) {
        int d = diff(timePoints[i], timePoints[i-1]);
        if (d < mmin) {
            mmin = d;
        }
    }
    int dt = diff(timePoints[0], timePoints.back()) + 24 * 60;
    if (dt < mmin) {
        mmin = dt;
    }
    return mmin;
}

int main(int argc, char *argv[]) {
    vector<string> vs = {"00:00","23:59","00:00"};
    cout << findMinDifference2(vs) << endl;
}
