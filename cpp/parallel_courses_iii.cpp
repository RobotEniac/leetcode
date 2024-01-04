// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/10/07 20:49:15
// Description: https://leetcode.cn/problems/parallel-courses-iii/description/

#include <iostream>
#include <vector>
#include <string>
#include <list>

#include "util.h"

using namespace std;

void insert(list<int>& v, int x, vector<int>& time) {
    auto it = v.begin();
    while (it != v.end() && time[*it] < time[x]) {
        ++it;
    }
    v.insert(it, x);
}

void sub(list<int>& v, int a, vector<int>& time) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        time[*it] = time[*it] - a;
    }
}

int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    vector<int> ind(n+1, 0);
    vector<vector<int> > g(n+1, vector<int>());
    for (int i = 0; i < relations.size(); ++i) {
        g[relations[i][0]].push_back(relations[i][1]);
        ++ind[relations[i][1]];
    }
    time.insert(time.begin(), 0);
    list<int> q;
    for (int i = 1; i <= n; ++i) {
        if (ind[i] == 0) {
            insert(q, i, time);
        }
    }
    int total = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop_front();
        total += time[x];
        sub(q, time[x], time);
        time[x] = 0;
        vector<int> &ev = g[x];
        for (int i = 0; i < ev.size(); ++i) {
            --ind[ev[i]];
            if (ind[ev[i]] == 0) {
                insert(q, ev[i], time);
            }
        }
    }
    return total;
}

int main(int argc, char *argv[]) {
    vector<vector<int>> re = {{1,5},{2,5},{3,5},{3,4},{4,5}};
    vector<int> time = {1,2,3,4,5};
    cout << minimumTime(5, re, time) << endl;
}
