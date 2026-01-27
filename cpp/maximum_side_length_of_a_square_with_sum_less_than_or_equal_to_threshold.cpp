// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2026/01/19 17:20:25
// Description: https://leetcode.cn/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/description/?envType=daily-question&envId=2026-01-19

#include <iostream>
#include <vector>
#include <string>

#include "util.h"
#include "file_util.hpp"

using namespace std;

void show(vector<vector<int>>& m, int l, int r, int x, int y) {
    for (int i = l; i <= x; ++i) {
        for (int j = r; j <=y; ++j) {
            printf("%4d", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int maxSideLength(vector<vector<int>> &mat, int threshold) {
    vector<vector<int>> sm(mat.size()+1, vector<int>(mat[0].size()+1, 0));
    for (int i = 0; i < sm.size(); ++i) {
        for (int j = 0; j < sm[0].size(); ++j) {
            if (i == 0 || j == 0) {
                sm[i][j] = 0;
                continue;
            }
            sm[i][j] = sm[i-1][j] + sm[i][j-1] - sm[i-1][j-1] + mat[i-1][j-1];
        }
    }
    int ml = std::min(mat.size(), mat[0].size());
    for (int l = ml; l >= 1; --l)
    {
        for (int i = 1; i < sm.size(); ++i)
        {
            for (int j = 1; j < sm[0].size(); ++j)
            {
                int x = i + l - 1;
                int y = j + l - 1;
                if (x >= sm.size() || y >= sm[0].size()) {
                    break;
                }
                int s = sm[x][y] - sm[i-1][y] - sm[x][j-1] +sm[i-1][j-1];
                if (s <= threshold) {
                    return l;
                }
            }
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    vector<vector<int>> m =  lc::ReadMatrix("[[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]]");
    cout << maxSideLength(m, 4) << endl;
}
