// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/04/09 15:01:00
// Description: https://leetcode-cn.com/problems/minesweeper/

#include <stdio.h>

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int bomb_number(vector<vector<char>>& board, int i, int j) {
    int num = 0;
    for (int x = i-1; x <= i+1; ++x) {
        if (x < 0 || x >= board.size()) {
            continue;
        }
        for (int y = j-1; y <= j+1; ++y) {
            if (j < 0 || j >= board[0].size()) {
                continue;
            }
            if (x == i && y == j) {
                continue;
            }
            if (board[x][y] == 'M') {
                ++num;
            }
        }
    }
    return num;
}

void reveal(vector<vector<char>>& board, int i, int j) {
    if (i < 0 || i >= board.size()) {
        return;
    }
    if (j < 0 || j >= board[0].size()) {
        return;
    }
    if (board[i][j] == 'M') {
        board[i][j] = 'X';
        return;
    }
    if (board[i][j] != 'E') {
        return;
    }
    int c = bomb_number(board, i, j);
    if (c > 0) {
        board[i][j] = '0' + c;
    }
    if (c == 0) {
        board[i][j] = 'B';
        for (int x = i-1; x <= i+1; ++x) {
            for (int y = j-1; y <= j+1; ++y) {
                if (x == i && y == j) {
                    continue;
                }
                reveal(board, x, y);
            }
        }
    }
}

vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    reveal(board, click[0], click[1]);
    return board;
}

void show(const vector<vector<char>>& board, bool hide) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            printf("%2c", board[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    vector<vector<char>> board =
    {{'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'M', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'}};
    show(board);
    vector<int> input = {3, 0};

    updateBoard(board, input);
    show(board);
}
