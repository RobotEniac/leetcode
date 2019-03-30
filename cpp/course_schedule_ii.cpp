// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/03/12 12:23:57
// Description: https://leetcode.com/problems/course-schedule-ii/

#include <iostream>
#include <vector>
#include <string>
#include <list>

#include "util.h"

using namespace std;

struct Node {
    list<int> adj;
    int color;
    Node() : color(0) {}
};

bool dfs_visit(vector<Node>& G, int s, vector<int>& path) {
    if (G[s].color == 1) {
        return false;
    }
    if (G[s].color == 2) {
        return true;
    }
    G[s].color = 1;
    for (auto it = G[s].adj.begin(); it != G[s].adj.end(); ++it) {
        if (!dfs_visit(G, *it, path)) {
            return false;
        }
    }
    G[s].color = 2;
    path.push_back(s);
    return true;
}

vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<Node> G(numCourses, Node());
    for (auto it = prerequisites.begin(); it != prerequisites.end(); ++it) {
        G[it->first].adj.push_back(it->second);
    }
    vector<int> path;
    for (int i = 0; i < G.size(); ++i) {
        if (G[i].color == 0) {
            if (!dfs_visit(G, i, path)) {
                return vector<int>();
            }
        }
    }
    return path;
}

int main(int argc, char *argv[]) {
    vector<pair<int, int>> pre;
    pre.push_back(make_pair(1, 0));
    pre.push_back(make_pair(2, 0));
    pre.push_back(make_pair(3, 1));
    pre.push_back(make_pair(3, 2));

    vector<int> res = findOrder(4, pre);
    cout << res << endl;
}
