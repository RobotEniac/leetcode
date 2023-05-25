// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/04/12 17:16:21
// Description: https://leetcode.cn/problems/checking-existence-of-edge-length-limited-paths/

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "util.h"

using namespace std;

typedef vector<map<int, vector<int> > > Graph;

bool dfs(const Graph &g, int s, int e, int limit, set<int> &visited) {
    if (s == e) {
        return true;
    }
    const map<int, vector<int> > &path = g[s];
    for (auto it = path.begin(); it != path.end(); ++it) {
        if (visited(it->first)) {
            continue;
        }
        const vector<int> &d = it->second;
        for (int j = 0; j < d.size(); ++j) {
            if (d[j] > limit) {
                continue;
            }
            visited.insert(it->first);
            bool ret = dfs(g, it->first, e, limit, visited);
            if (ret) {
                return true;
            }
        }
    }
    return false;
}

vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
    vector<map<int, vector<int> > > G(n, map<int, vector<int> >());
    for (int i = 0; i < edgeList.size(); ++i) {
        int l = edgeList[0];
        int r = edgeList[1];
        int d = edgeList[2];
        if (G[l].find(r) == G[l].end()) {
            G[l][r] = vector<int>(1, d);
        } else {
            G[l][r].push_back(d);
        }
        if (G[r].find(l) == G[r].end()) {
            G[r][l] = vector<int>(1, d);
        } else {
            G[r][l].push_back(d);
        }
    }
    vector<bool> ret(queries.size(), false);
    for (int i = 0; i < queries.size(); ++i) {
        set<int> s;
        s.insert(queries[0]);
        ret[i] = dfs(G, queries[0], queries[1], queries[2], s);
    }
    return ret;
}

int main(int argc, char *argv[]) {

}
