// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/12/31 10:39:28
// Description: https://leetcode-cn.com/problems/most-profit-assigning-work/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "util.h"

using namespace std;

void swap(vector<int>& a, int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

int biselect(vector<int>& a, vector<int>& b, int s, int e) {
    int p = e - 1;
    int i = s;
    int l = s;
    while (i < p) {
        if (a[i] < a[p]) {
            if (l < i) {
                swap(a, l, i);
                swap(b, l, i);
            }
            ++l;
        }
        ++i;
    }
    swap(a, l, p);
    swap(b, l, p);
    return l;
}

void quick_sort(vector<int>& a, vector<int>& b, size_t s, size_t e) {
    if (e - s < 2) {
        return;
    }
    int m = biselect(a, b, s, e);
    quick_sort(a, b, s, m);
    quick_sort(a, b, m+1, e);
}

void show(std::map<int, int, std::greater_equal<int> > &a) {
    for (auto it = a.begin(); it != a.end(); ++it) {
        if (it != a.begin()) {
            cout << ", ";
        }
        cout << "(" << it->first << ", " << it->second << ")";
    }
    cout << endl;
}

int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
{
    map<int, int, std::greater_equal<int> > d2p;
    for (size_t i = 0; i < difficulty.size(); ++i) {
        auto it = d2p.find(difficulty[i]);
        if (it != d2p.end()) {
            if (profit[i] > it->second) {
                d2p[difficulty[i]] = profit[i];
            }
        } else {
            d2p[difficulty[i]] = profit[i];
        }
    }
    show(d2p);
    for (auto i = d2p.begin(); i!= d2p.end(); ++i) {
        auto tmp = i;
        i++;
        for (auto j = tmp; j != d2p.end(); ++j) {
            if (j->second > tmp->second) {
                tmp->second = j->second;
            }
        }
        --i;
    }
    show(d2p);
    int ret = 0;
    for (size_t i = 0 ; i < worker.size(); ++i) {
        auto low = d2p.lower_bound(worker[i]);
        if (low != d2p.end()) {
            ret += low->second;
        }
    }
    return ret;
}

int main(int argc, char *argv[])
{
    vector<int> d = {68,35,52,47,86};
    vector<int> p = {67,17,1,81,3};
    vector<int> w = {92,10,85,84,82};
    cout << maxProfitAssignment(d, p, w) << endl;
}
