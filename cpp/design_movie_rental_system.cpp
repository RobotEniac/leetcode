// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2026/01/13 10:10:45
// Description: https://leetcode.cn/problems/design-movie-rental-system/description/?envType=daily-question&envId=2026-01-07

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

#include "prettyprint.hpp"
#include "file_util.hpp"

using namespace std;
using namespace pretty_print;

class MovieRentingSystem {
public:
    MovieRentingSystem(int n, vector<vector<int>> &entries)
        : shop_size(n),
          tb(entries),
          dirty(true)
    {
        for (int i = 0; i < tb.size(); ++i) {
            tb[i].push_back(0);
            vector<int> k(tb[i].begin(), tb[i].begin()+2);
            index[k] = i;
        }
    }

    vector<int>* get(const vector<int>& k) {
        auto it = index.find(k);
        if (it != index.end()) {
            return &tb[it->second];
        }
        return NULL;
    }

    vector<int> search(int movie) {
        auto comp = [&](int lhs, int rhs) {
            if (tb[lhs][2] == tb[rhs][2]) {
                return tb[lhs][0] < tb[rhs][0];
            }
            return tb[lhs][2] < tb[rhs][2];
        };
        vector<int> unrent;
        if (!dirty) {
            unrent = top_5_unrent_cache;
        }
        else
        {
            for (int i = 0; i < tb.size(); ++i)
            {
                if (tb[i][1] == movie && tb[i][3] == 0)
                {
                    int j = 0;
                    for (; j < unrent.size() && j < 5; ++j)
                    {
                        if (!comp(unrent[j], i))
                        {
                            break;
                        }
                    }
                    unrent.insert(unrent.begin() + j, i);
                    if (unrent.size() > 5)
                    {
                        unrent.pop_back();
                    }
                }
            }
            top_5_unrent_cache = unrent;
        }
        vector<int> ret;
        for (int i = 0; i < unrent.size() && i < 5; ++i) {
            ret.push_back(tb[unrent[i]][0]);
        }
        return ret;
    }

    void rent(int shop, int movie)
    {
        vector<int> k(2, 0);
        k[0] = shop;
        k[1] = movie;
        auto it = index.find(k);
        if (it != index.end()) {
            tb[it->second][3] = 1; // tb[##rent] = rent
            dirty = true;
        }
    }

    void drop(int shop, int movie)
    {
        vector<int> k(2, 0);
        k[0] = shop;
        k[1] = movie;
        auto it = index.find(k);
        if (it != index.end()) {
            tb[it->second][3] = 0; // tb[##rent] = !rent
            dirty = true;
        }
    }

    vector<vector<int>> report() {
        auto comp = [&](int lhs, int rhs) {
            if (tb[lhs][2] == tb[rhs][2]) {
                if (tb[lhs][0] == tb[rhs][0]) {
                    return tb[lhs][1] < tb[rhs][1];
                }
                return tb[lhs][0] < tb[rhs][0];
            }
            return tb[lhs][2] < tb[rhs][2];
        };
        vector<int> r;
        for (int i = 0; i < tb.size(); ++i) {
            if (tb[i][3] == 1) {
                r.push_back(i);
           }
        }
        sort(r.begin(), r.end(), comp);
        vector<vector<int>> ret;
        for (int i = 0; i < r.size() && i < 5; ++i) {
            vector<int> t(2, 0);
            t[0] = tb[r[i]][0];
            t[1] = tb[r[i]][1];
            ret.push_back(t);
        }
        return ret;
    }

private:
    int shop_size;
    vector<vector<int>> tb; // shop, movie, price, rent
    map<vector<int>, int> index;
    bool dirty;
    vector<int> top_5_unrent_cache;
};

int main(int argc, char *argv[]) {
    // ["MovieRentingSystem","search","rent","rent","report","drop","search"]
    // [[3,[[0,1,5],[0,2,6],[0,3,7],[1,1,4],[1,2,7],[2,1,5]]],[1],[0,1],[1,2],[],[1,2],[2]]
    // ["MovieRentingSystem","rent","report","rent","report","rent","report","rent","rent","rent","report"]
    // [[1,[[0,1,3],[0,5,3],[0,7,3],[0,6,3],[0,2,3],[0,3,3],[0,4,3],[0,8,3]]],
    // [0,1],[],[0,4],[],[0,3],[],[0,2],[0,6],[0,7], []]
    vector<vector<int>> vv = lc::ReadMatrix("[[0,1,3],[0,5,3],[0,7,3],[0,6,3],[0,2,3],[0,3,3],[0,4,3],[0,8,3]]");
    MovieRentingSystem s(1, vv);
    s.rent(0, 1);
    cout << s.report();
    s.rent(0, 4);
    cout << s.report();
    s.rent(0,3);
    cout << s.report();
    s.rent(0,2);
    s.rent(0,6);
    s.rent(0,7);
    cout << s.report();
    cout << endl;

    vector<int> a = {1,3,5,7,9};
    int i = 0;
    for (; i < a.size(); ++i) {
        if (a[i] > 2) {
            break;
        }
    }
    a.insert(a.begin()+i, 2);
    cout << a << endl;
}
