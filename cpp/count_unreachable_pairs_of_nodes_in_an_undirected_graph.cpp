// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/05/30 10:37:12
// Description: https://leetcode.cn/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

void dfs(int s, vector<bool>& visited, vector<vector<int> > &G) {
    if (visited[s]) {
        return;
    }
    vector<int>& d = G[s];
    visited[s] = true;
    for (int i = 0; i < d.size(); ++i) {
        dfs(d[i], visited, G);
    }
}

int count(vector<bool> &v) {
    int cnt = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i]) {
            ++cnt;
        }
    }
    return cnt;
}

long long countPairs(int n, vector<vector<int>>& edges) {
    vector<vector<int> > g(n, vector<int>());
    for (int i = 0; i < edges.size(); ++i) {
        g[edges[i][0]].push_back(edges[i][1]);
        g[edges[i][1]].push_back(edges[i][0]);
    }
    vector<bool> v(n, false);
    vector<int> ret;
    for (int i = 0; i < n; ++i) {
        if (!v[i]) {
            int s = count(v);
            dfs(i, v, g);
            ret.push_back(count(v) - s);
        }
    }
    int r = 0;
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = i+1; j < ret.size(); ++j) {
            r = r + ret[i] * ret[j];
        }
    }
    return r;
}

int main(int argc, char *argv[]) {
    vector<vector<int>> g = {{0,2},{0,5},{2,4},{1,6},{5,4}};
    cout << countPairs(7, g) << endl;
}
