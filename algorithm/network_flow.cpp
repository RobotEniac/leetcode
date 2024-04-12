// Copyright (c) 2024, Personal Developer
// All rights reserved.
//
// Author: RobotEniac <gethaibo@gmail.com>
// Created: 02/12/24
// Description:

#include <stdio.h>

#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

struct Edge {
    int s;
    int e;
    int w;
};

bool EdgeComp(const Edge &lhs, const Edge &rhs) {
    return lhs.w > rhs.w;
}

class Graph {
public:
    explicit Graph(int n);

    void add(int s, int e, int w);

    void set(int s, int e, int w);

    void minus(int s, int e, int w);

    Graph residual(Graph &g2);

    void show();

    int size() {
        return g.size() - 1;
    }

    bool dfs(int s, int t, int cur,
             std::set<int>& visited, vector<Edge>& path);

private:
    vector<map<int, Edge>> g;
};

Graph::Graph(int n) {
    g = vector<map<int, Edge>>(n+1, map<int, Edge>());
}

void Graph::add(int s, int e, int w) {
    if (s > g.size() || e > g.size()) {
        cout << "invalid " << s << "->" << e << endl;
        return;
    }
    auto it = g[s].find(e);
    if (it != g[s].end()) {
        it->second.w += w;
    } else {
        Edge eg;
        eg.s = s;
        eg.e = e;
        eg.w = w;
        g[s][e] = eg;
    }
}

void Graph::minus(int s, int e, int w) {
    if (s > g.size() || e > g.size()) {
        cout << "invalid " << s << "->" << e << endl;
        return;
    }
    auto it = g[s].find(e);
    if (it != g[s].end()) {
        it->second.w = std::max(0, it->second.w - w);
    }
}

void Graph::show() {
    for (int i = 1; i < g.size(); ++i) {
        printf("%d:", i);
        for (auto it = g[i].begin(); it != g[i].end(); ++it) {
            if (it != g[i].begin()) {
                printf(",");
            }
            printf("%d-%d->%d", i, it->second.w, it->first);
        }
        printf("\n");
    }
}

void Graph::set(int s, int e, int w) {
    if (s <= 0 || s > g.size()) {
        printf("invalid vertex[%d, %d]\n", s, e);
        return;
    }
    g[s][e].w = w;
}

Graph Graph::residual(Graph &g2) {
    Graph r = *this;
    for (int i = 1; i < g.size(); ++i) {
        for (auto it = g[i].begin(); it != g[i].end(); ++it) {
            Edge &e = it->second;
            if (g2.g[e.s].find(e.e) != g2.g[e.s].end()) {
                r.g[e.s][e.e].w = e.w - g2.g[e.s][e.e].w;
            }
        }
    }
    return r;
}

bool Graph::dfs(int s, int t, int cur,
                std::set<int>& visited, vector<Edge>& path) {
    if (visited.empty()) {
        cur = s;
        visited.insert(s);
    }
    if (cur == t) {
        return true;
    }
    map<int, Edge>& m = g[cur];
    vector<Edge> v;
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it->second.w != 0) {
            v.push_back(it->second);
        }
    }
    sort(v.begin(), v.end(), EdgeComp);
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (visited.find(it->e) != visited.end()) {
            continue;
        }
        if (it->w == 0) {
            continue;
        }
        visited.insert(it->e);
        path.push_back(*it);
        if (dfs(s, t, it->e, visited, path)) {
            return true;
        }
        path.pop_back();
        visited.erase(it->e);
    }
    return false;
}

int MaxFlow(Graph &g, int s, int t) {
    bool path_exists = false;
    Graph res = g;
    do {
        vector<Edge> path;
        std::set<int> visited;
        path_exists = res.dfs(s, t, 0, visited, path);
        if (path_exists) {
            int min_weight = INT_MAX;
            for (auto it = path.begin(); it != path.end(); ++it) {
                if (it->w < min_weight) {
                    min_weight = it->w;
                }
            }
            for (auto it = path.begin(); it != path.end(); ++it) {
                it->w = min_weight;
                res.minus(it->s, it->e, it->w);
                res.add(it->e, it->s, it->w);
            }
        }
    } while (path_exists == true);
    Graph ret = g.residual(res);
    ret.show();
    return 0;
}

void ShowPath(const vector<Edge>& path) {
    if (!path.empty()) {
        printf("%d", path[0].s);
    }
    for (auto it = path.begin(); it != path.end(); ++it) {
        printf(" --> %d ", it->e);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    Graph g(6);
    g.add(1, 2, 4);
    g.add(1, 3, 2);
    g.add(2, 4, 2);
    g.add(2, 5, 4);
    g.add(2, 3, 1);
    g.add(3, 5, 2);
    g.add(4, 6, 3);
    g.add(5, 6, 3);
    g.show();
    MaxFlow(g, 1, 6);
}
