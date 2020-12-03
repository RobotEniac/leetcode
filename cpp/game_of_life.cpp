// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/02/21 15:37:06
// Description: https://leetcode.com/problems/game-of-life

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;


struct Cord {
    int x;
    int y;
    Cord(): x(0), y(0) {}
    Cord(int x_, int y_) : x(x_), y(y_) {}
};

int check(vector<vector<int>>& board, int i, int j) {
    int cnt = 0;
    for (int p = i-1; p <= i+1; ++p) {
        for (int q = j-1; q <= j+1; ++q) {
            if (p < 0 || p >= board.size()
                    || q < 0 || q >= board[0].size()
                    || (p == i && q == j)) {
                continue;
            }
            cnt = cnt + board[p][q];
        }
    }
    return cnt;
}

void gameOfLife(vector<vector<int>>& board) {
    vector<Cord> v;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            int neighbour = check(board, i, j);
            if (board[i][j] == 0) {
                if (neighbour == 3) {
                    v.push_back(Cord(i, j));
                }
            } else {
                if (neighbour < 2
                        || neighbour > 3) {
                    v.push_back(Cord(i, j));
                }
            }
        }
    }
    for (int i = 0; i < v.size(); ++i) {
        int x = v[i].x;
        int y = v[i].y;
        board[x][y] = board[x][y] ^ 1;
    }
}

void show(vector<vector<int>> &b) {
    cout << "==========\n";
    for (int i = 0; i < b.size(); ++i) {
        if (i != 0) {
            printf("\n");
        }
        for (int j = 0; j < b[i].size(); ++j) {
            printf("%2d", b[i][j]);
        }
    }
    cout << "\n==========\n";
}

int main(int argc, char *argv[]) {
    vector<vector<int>> b = {
        {0,1,0},
        {0,0,1},
        {1,1,1},
        {0,0,0}
    };
    show(b);
    gameOfLife(b);
    show(b);
}
