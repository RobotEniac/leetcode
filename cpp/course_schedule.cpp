// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/03/07 17:40:32
// Description: https://leetcode.com/problems/course-schedule/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>

#include "util.h"

using namespace std;

void print(vector<vector<int>> &v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << i << ": [";
        for (int j = 0; j < v[i].size(); ++j) {
            if (j != 0) {
                cout << ", ";
            }
            cout << v[i][j];
        }
        cout << "]\n";
    }
}

bool dfs(vector<vector<int>> &g, int n, list<int> &path, set<int> &traversed) {
    cout << path << endl;
    for (auto it = path.begin(); it != path.end(); ++it) {
        if (*it == n) {
            return true;
        }
    }
    if (traversed.find(n) != traversed.end()) {
        return false;
    }
    traversed.insert(n);
    path.push_back(n);
    for (int i = 0; i < g[n].size(); ++i) {
        if (dfs(g, g[n][i], path, traversed)) {
            path.pop_back();
            return true;
        }
    }
    path.pop_back();
    return false;
}

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> g(numCourses, vector<int>());
    for (int i = 0; i < prerequisites.size(); ++i) {
        g[prerequisites[i].first].push_back(prerequisites[i].second);
    }
    print(g);
    list<int> path;
    set<int> traversed;
    for (int i = 0; i < numCourses; ++i) {
        if (traversed.find(i) == traversed.end()) {
            if (dfs(g, i, path, traversed)) {
                return true;
            }
        }
    }
    return false;
}

void insert(vector<pair<int, int>> &vec, int x, int y) {
    vec.push_back(make_pair(x, y));
}

int main(int argc, char *argv[]) {
    vector<pair<int, int>> edge;
    insert(edge, 1, 0);
    insert(edge, 0, 1);

    bool ret = canFinish(2, edge);
    cout << boolalpha << ret << endl;
}
