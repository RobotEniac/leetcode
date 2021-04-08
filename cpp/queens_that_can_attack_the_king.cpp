// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/01/08 16:08:47
// Description: https://leetcode-cn.com/problems/queens-that-can-attack-the-king/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
    int i = king[0], j = king[1];
    vector<vector<int>> ret;
    vector<vector<int>> dir = {
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0, -1},
        {0, 1},
        {1, -1},
        {1, 0},
        {1, 1}
    };
    vector<bool> check(dir.size(), false);
    for (int l = 1; l < 8; ++l) {
        for (int k = 0; k < dir.size(); ++k) {
            i = king[0] + l * dir[k][0];
            j = king[1] + l * dir[k][1];
            if (i >= 0 && i < 8
                && j >= 0 && j < 8) {
                bool found = false;
                for (int qi = 0; qi < queens.size(); ++qi) {
                    if (queens[qi][0] == i && queens[qi][1] == j) {
                        if (!check[k]) {
                            vector<int> vt(2, 0);
                            vt[0] = i;
                            vt[1] = j;
                            ret.push_back(vt);
                            check[k] = true;
                        }
                    }
                }
            }
        }
    }
    return ret;
}

void show(const vector<vector<int>> &v) {
    for (int i = 0; i < v.size(); ++i) {
        if (i != 0) {
            cout << ",";
        }
        cout << "[" << v[i][0] << ", " << v[i][1] << "]";
    }
    cout << "\n";
}

int main(int argc, char *argv[]) {
    vector<vector<int>> queens = {{0,1},{1,0},{4,0},{0,4},{3,3},{2,4}};
    vector<int> king = {0,0};
    show(queensAttacktheKing(queens, king));
}
