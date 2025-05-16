// Copyright (c) 2024, Personal Developer
// All rights reserved.
//
// Author: RobotEniac <gethaibo@gmail.com>
// Created: 05/27/24
// Description:

#include "util.h"
#include <iostream>
#include <vector>

using namespace std;

int count(vector<int>& a) {
    int m = 0;
    while (a[m] < 0) {
        ++m;
    }
    int l = m-1;
    int r = m;
    int j = m;
    if (-a[l] < a[r]) {
        j = l;
        l = l - 1;
    } else if (-a[l] >= a[r]) {
        j = m;
        r = r + 1;
    }
    int cnt = 1;
    while (l >= 0 && r < a.size()) {
        int absj = abs(a[j]);
        cout << "(" << a[j] << ", " << cnt << "), ";
        if (-a[l] < a[r]) {
            if (-a[l] == absj) {
                --l;
            } else {
                ++cnt;
                j = l;
                --l;
            }
        } else if (-a[l] > a[r]) {
            if (a[r] == absj) {
                ++r;
            } else {
                ++cnt;
                j = r;
                ++r;
            }
        } else {
            if (a[r] != absj) {
                ++cnt;
                j = r;
            }
            --l;
            ++r;
        }
    }
    while (l >= 0) {
        int absj = abs(a[j]);
        cout << "(" << a[j] << ", " << cnt << "), ";
        if (-a[l] == absj) {
            --l;
        } else {
            ++cnt;
            j = l;
            --l;
        }
    }
    while (r < a.size()) {
        int absj = abs(a[j]);
        cout << "(" << a[j] << ", " << cnt << "), ";
        if (a[r] == absj) {
            ++r;
        } else {
            ++cnt;
            j = r;
            ++r;
        }
    }
    return cnt;
}

int main() {
    vector<int> a = {-13,-10,-9,-6,-5,-1,3,4,6,7,10,11,15,21,42 };
    cout << count(a) << endl;
    map<int, int> m;
    for (int i = 0; i < a.size(); ++i) {
        int absi = abs(a[i]);
        if (m.find(absi) == m.end()) {
            m[absi] = 1;
        } else {
            ++m[absi];
        }
    }
    cout << m.size() << endl;
}
