// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/05/06 11:12:10
// Description: https://leetcode.com/problems/minimum-height-trees

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>

#include "util.h"

using namespace std;

int bfs(map<int, vector<int> >& G, int start) {
    int n = G.size();
    std::list<int> q;
    vector<int> visited(n, 0);
    int max_height = 0;
    q.push_back(start);
    visited[start] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();
        vector<int> & e = G[cur];
        for (size_t i = 0; i < e.size(); ++i) {
            if (visited[e[i]] > 0) {
                continue;
            }
            q.push_back(e[i]);
            int height = visited[cur] + 1;
            visited[e[i]] = height;
            if (height > max_height) {
                max_height = height;
            }
        }
    }
    return max_height;
}

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    map<int, vector<int> > G;
    for (size_t i = 0; i < n; ++i) {
        G[i] = vector<int>();
    }
    for (size_t i = 0; i < edges.size(); ++i) {
        vector<int> &e = edges[i];
        G[e[0]].push_back(e[1]);
        G[e[1]].push_back(e[0]);
    }
    vector<int> res(n, 0);
    int min_height = n;
    for (int i = 0; i < n; ++i) {
        int h = bfs(G, i);
        res[i] = h;
        if (h < min_height) {
            min_height = h;
        }
    }
    vector<int> ret;
    for (int i = 0; i < n; ++i) {
        if (res[i] == min_height) {
            ret.push_back(i);
        }
    }
    return ret;
}

void show(map<int, set<int> >& g) {
    cout << "======\n";
    for (auto git = g.begin(); git != g.end(); ++git) {
        cout << git->first << ": ";
        set<int> &edge = git->second;
        for (auto it = edge.begin(); it != edge.end(); ++it) {
            if (it != edge.begin()) {
                cout << ", ";
            }
            cout << *it;
        }
        cout << endl;
    }
    cout << "======\n";
}

vector<int> findMinHeightTrees2(int n, vector<vector<int>>& edges) {
    unordered_map<int, unordered_set<int> > G;
    for (size_t i = 0; i < n; ++i) {
        G[i] = unordered_set<int>();
    }
    for (size_t i = 0; i < edges.size(); ++i) {
        vector<int> &e = edges[i];
        G[e[0]].insert(e[1]);
        G[e[1]].insert(e[0]);
    }
    vector<int> ret;
    while (true) {
        bool find = true;
        for (auto git = G.begin(); git != G.end(); ++git) {
            if (git->second.size() > 1) {
                find = false;
                break;
            }
        }
        if (find) {
            for (auto git = G.begin(); git != G.end(); ++git) {
                ret.push_back(git->first);
            }
            return ret;
        }
        vector<pair<int, int> > rm;
        for (auto it = G.begin(); it != G.end(); ++it) {
            if (it->second.size() == 1) {
                int i = it->first;
                int j = *it->second.begin();
                rm.push_back(pair<int, int>(i, j));
            }
        }
        for (size_t i = 0; i < rm.size(); ++i) {
            int p = rm[i].first;
            int q = rm[i].second;
            G[p].erase(q);
            G[q].erase(p);
            if (G[p].empty()) {
                G.erase(p);
            }
            if (G[q].empty()) {
                G.erase(p);
            }
        }
    }
    return ret;
}

vector<int> MakeEdge(int i, int j) {
    vector<int> ret(2, 0);
    ret[0] = i;
    ret[1] = j;
    return ret;
}

int main(int argc, char *argv[]) {
    cout << "hello world" << endl;
    vector<vector<int> > edge;
    edge.push_back(MakeEdge(0, 3));
    edge.push_back(MakeEdge(1, 3));
    edge.push_back(MakeEdge(2, 3));
    edge.push_back(MakeEdge(4, 3));
    edge.push_back(MakeEdge(5, 4));

    vector<int> ret = findMinHeightTrees2(6, edge);
    cout << ret << endl;
}
