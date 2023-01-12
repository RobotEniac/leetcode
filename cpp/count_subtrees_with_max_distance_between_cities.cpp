// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2022/11/09 16:12:33
// Description: https://leetcode.cn/problems/count-subtrees-with-max-distance-between-cities/

#include <unistd.h>

#include <iostream>
#include <vector>
#include <string>
#include <queue>

#include "util.h"

using namespace std;

void show(vector<vector<int> >& g) {
    for (int i = 1; i < g.size(); ++i) {
        cout << i << ": ";
        for (int j = 0; j < g[i].size(); ++j) {
            if (j != 0) {
                cout << ", ";
            }
            cout << g[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void depth(vector<vector<int> >& g, int s, int d, int f, int &md) {
    if (g[s].size() == 1 && g[s][0] == f) {
        if (d > md) {
            md = d;
        }
        return;
    }
    for (int i = 0; i < g[s].size(); ++i) {
        if (g[s][i] == f) {
            continue;
        }
        depth(g, g[s][i], d+1, s, md);
    }
}

int width(vector<vector<int> >& g) {
    struct Node {
        int f;
        int p;
    };
    queue<Node> q;
    Node t;
    t.f = 0;
    t.p = 1;
    q.push(t);
    while (!q.empty()) {
        t = q.front();
        q.pop();
        for (int i = 0; i < g[t.p].size(); ++i) {
            if (g[t.p][i] == t.f) {
                continue;
            }
            Node tn;
            tn.f = t.p;
            tn.p = g[t.p][i];
            q.push(tn);
        }
    }
    cout << t.p << endl;
    int w = 0;
    depth(g, t.p, 0, 0, w);
    return w;
}

vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
    vector<int> ret;
    vector<vector<int> > g(n+1, vector<int>());
    for (int i = 0; i < edges.size(); ++i) {
        g[edges[i][0]].push_back(edges[i][1]);
        g[edges[i][1]].push_back(edges[i][0]);
    }
    cout << width(g) << endl;
    return ret;
}

int main(int argc, char *argv[]) {
    vector<vector<int> > e = {{1,2},{2,3},{2,4}};
    // vector<vector<int> > e = {{1,2},{2,4},{1,3}, {1,5}, {5,7}, {7,8}, {4,6}};
    cout << countSubgraphsForEachDiameter(8, e) << endl;
}
