// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2024/05/27 18:12:50
// Description: https://leetcode.cn/problems/EXvqDp/description/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

/*
 * 直接暴力破解最简单，从一个可行的(x, y, d)开始，小球的可能路径只有一种
 */

vector<vector<int> > d = {{0,-1},{-1,0},{0,1},{1,0}};

void bfs(vector<string>& p, int x, int y, int dir,
         vector<string> visited, vector<vector<int> >& ret) {
    if (x < 0 || x >= p[0].size() || y < 0 || y >= p.size()) {
        vector<int> r(2, 0);
        r[0] = x - d[dir[0]];
        r[1] = y - d[dir[1]];
        ret.push_back(r);
    }
    visited[x][y] = "#";

}

vector<vector<int>> ballGame(int num, vector<string>& plate) {
    vector<vector<int>> ret;

}

int main(int argc, char *argv[]) {
    vector<string> plate = {"..E.",".EOW","..W."};
}
