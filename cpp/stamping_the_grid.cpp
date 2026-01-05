// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/09/19 09:48:06
// Description: https://leetcode.cn/problems/stamping-the-grid/description/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

bool satisfy(vector<vector<int>> &grid, int x, int y, int h, int w) {
    if (x+w > grid[0].size()) {
        return false;
    }
    if (y+h > grid.size()) {
        return false;
    }
    for (int i = y; i < y+h; ++i) {
        for (int j = x; j < x+w; ++j) {
            if (grid[i][j] == 1) {
                return false;
            }
        }
    }
    for (int i = y; i < y + h; ++i)
    {
        for (int j = x; j < x + w; ++j)
        {
            grid[i][j] = 2;
        }
    }
    return true;
}

bool possibleToStamp(vector<vector<int>> &grid, int stampHeight, int stampWidth)
{
    for (int y = 0; y < grid.size(); ++y) {
        if (y + stampHeight > grid.size()) {
            break;
        }
        for (int x = 0; x <grid[0].size(); ) {
            if (x + stampWidth > grid[0].size()) {
                break;
            }
            if (satisfy(grid, x, y, stampWidth, stampHeight))
            {
                if (satisfy(grid, x + stampWidth, y, stampWidth, stampHeight))
                {
                    x += stampWidth;
                }
                else
                {
                    x += 1;
                }
            }
        }
    }
    bool all = true;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == 0) {
                all = false;
                break;
            }
        }
        if (!all) {
            break;
        }
    }
    return all;
}

void show(vector<vector<int>> &g) {
    for (int i = 0; i < g.size(); ++i) {
        for (int j = 0; j < g[0].size(); ++j) {
            printf("%4d", g[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    vector<vector<int>> g = {{1,0,0,0},{1,0,0,0},{1,0,0,0},{1,0,0,0},{1,0,0,0}};
    cout << boolalpha << possibleToStamp(g, 4, 3) << endl;
    show(g);
}
