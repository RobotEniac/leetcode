// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/06/13 14:34:24
// Description: https://leetcode.cn/problems/minimize-the-maximum-difference-of-pairs/description/?envType=daily-question&envId=2025-06-13

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int check(vector<int>& a, int s, int m) {
    if (s >= a.size()-1) {
        return 0;
    }
    if (s == a.size() - 2) {
        if (a[s+1] - a[s] <= m) {
            return 1;
        } else {
            return 0;
        }
    }
    if (a[s+1] - a[s] > m) {
        return check(a, s+1, m);
    } else {
        return max(check(a,s+1, m), 1+check(a, s+2, m));
    }
}

int minimizeMax(vector<int>& a, int n) {
    sort(a.begin(), a.end());
    set<int> st;
    for (int i = 0; i < a.size() - 1; ++i) {
        st.insert(a[i+1] - a[i]);
    }
    vector<int> p(st.begin(), st.end());
    cout << p << endl;
    int s = 0;
    int e = p.size();
    int m = (s+e) / 2;
    int cur = p[m];
    while (s < e) {
        int cnt = check(a, 0, cur);
        if (cnt >= n) {
            e = m;
            m = (s+e)/2;
            cur = p[m];
        } else {
            s = m+1;
            m = (s+e)/2;
            cur = p[m];
        }
    }
    return p[m];
}

int main(int argc, char *argv[]) {
    vector<int> a = {19298,19535,79056,10881,40943,75460,8355,66550,25145,90159,22032,42246,42387,83016,63420,2138,94284,25255,60480,56379,82599,74723,40189,45981,81,21612,72536,59520,79903,87560,86538,39283,19191,84764,22306,98550,32332,35576,85418,80598,94329,74601,4583,6489,52187,72236,31341,478};
    vector<int> b = {4,2,1,2};
    cout << minimizeMax(b, 1) << endl;
}
