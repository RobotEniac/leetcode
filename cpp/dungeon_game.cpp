// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/02/28
// Description: https://leetcode.com/problems/dungeon-game/

#include <iostream>
#include <vector>
#include <sstream>
#include <list>

#include "util.h"

using namespace std;

#define INTMAX 0x3f3f3f3f

template<class T>
void show(vector<vector<T>> &v) {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            printf("%4d", v[i][j]);
        }
        printf("\n");
    }
}

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int M = dungeon.size();
    int N = dungeon[0].size();
    vector<vector<int>> hp(M+1, vector<int>(N+1, 1));
    for (int i = M-1; i >= 0; --i) {
        for (int j = N-1; j >= 0; --j) {
            hp[i][j] = std::min(hp[i+1][j], hp[i][j+1]) - dungeon[i][j];
            if (hp[i][j] < 1) {
                hp[i][j] = 1;
            }
        }
    }
    show(hp);
    return hp[0][0];
}

int main(int argc, char *argv[]) {
    vector<vector<int>> d = 
    {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };
    show(d);
    cout << calculateMinimumHP(d) << endl;
}
