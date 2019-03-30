// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/03/25 17:51:29
// Description: https://leetcode.com/problems/word-search-ii/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

#define  MAX_SIZE 26

bool dfs(const char *word, vector<vector<char>> &board, vector<vector<bool>> &visited, int i, int j) {
    if (*word == '\0') {
        return true;
    }
    if (i < 0
            || j < 0
            || i >= board.size()
            || j >= board[0].size()) {
        return false;
    }
    if (board[i][j] == *word) {
        visited[i][j] = true;
        if (dfs(word+1, board, visited, i-1, j)) {
            return true;
        }
        if (dfs(word+1, board, visited, i, j-1)) {
            return true;
        }
        if (dfs(word+1, board, visited, i+1, j)) {
            return true;
        }
        if (dfs(word+1, board, visited, i, j+1)) {
            return true;
        }
        visited[i][j] = false;
    }
    return false;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> ret;
    if (board.empty()) {
        return ret;
    }
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    for (auto it = words.begin(); it != words.end(); ++it) {
        const char *word = it->c_str();
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (dfs(word, board, visited, i, j)) {
                    ret.push_back(word);
                }
            }
        }
    }
    return ret;
}

struct Point {
    int x, y;
    Point(): x(0), y(0) {}
    Point(int x_, int y_): x(x_), y(y_) {}
};

vector<string> findWords2(vector<vector<char>>& board, vector<string>& words) {
    vector<string> ret;
    return ret;
}

int main(int argc, char *argv[]) {
    cout << "hello world" << endl;
}
