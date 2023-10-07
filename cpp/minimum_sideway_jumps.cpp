// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/07/31 11:14:24
// Description: https://leetcode.cn/problems/minimum-sideway-jumps/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int dfs(vector<int>& ob, int s, int cur) {
    int ret = 0;
    while (s < ob.size() && (ob[s] == 0 || ob[s] != cur)) {
        ++s;
    }
    if (s == ob.size()) {
        return 0;
    }
    if (ob[s] == 1) {
        if (ob[s-1] == 0) {
            return min(1+dfs(ob, s-1, 2), 1+dfs(ob, s-1, 3));
        }
        if (ob[s-1] == 2) {
            return 1 + dfs(ob, s-1, 3);
        }
        if (ob[s-1] == 3) {
            return 1 + dfs(ob, s-1, 2);
        }
    }

    if (ob[s] == 2) {
        if (ob[s-1] == 0) {
            return min(1+dfs(ob, s-1, 1), 1+dfs(ob, s-1, 3));
        }
        if (ob[s-1] == 1) {
            return 1 + dfs(ob, s-1, 3);
        }
        if (ob[s-1] == 3) {
            return 1 + dfs(ob, s-1, 1);
        }
    }

    if (ob[s] == 3) {
        if (ob[s-1] == 0) {
            return min(1+dfs(ob, s-1, 1), 1+dfs(ob, s-1, 2));
        }
        if (ob[s-1] == 1) {
            return 1 + dfs(ob, s-1, 2);
        }
        if (ob[s-1] == 2) {
            return 1 + dfs(ob, s-1, 1);
        }
    }
    // will never reach
    return 0;
}

int minSideJumps(vector<int>& obstacles) {
    vector<vector<int> > m = vector<vector<int>>(3, vector<int>(obstacles.size()));
    vector<int>& o = obstacles;
    int n = o.size();
    int i = n-2;
    while (i >= 0 && o[i] == 0) {
        --i;
    }

    while (i >= 0) {
        for (int cur = 0; cur < 3; ++cur) {
            if (cur == o[i]-1) {
                m[cur][i] = n;
                continue;
            }
            if (m[cur][i+1] != n) {
                m[cur][i] = m[cur][i+1];
            } else {
                int mt = n;
                for (int j = 0; j < 3; ++j) {
                    if (j != o[i]-1 && m[j][i+1] < mt) {
                        mt = m[j][i+1];
                    }
                }
                m[cur][i] = mt+1;
            }
        }
        --i;
    }
    cout << m[0] << endl;
    cout << m[1] << endl;
    cout << m[2] << endl;
    return m[1][0];
}

int main(int argc, char *argv[]) {
    vector<int> ob = {0,1,2,3,0};
    cout << minSideJumps(ob);
}
