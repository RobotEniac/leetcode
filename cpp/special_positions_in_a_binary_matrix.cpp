// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/01/08 15:16:31
// Description: https://leetcode-cn.com/problems/special-positions-in-a-binary-matrix/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

void show(vector<vector<int> > &mat) {
    for (int i = 0; i < mat.size(); ++i) {
        if (i != 0) {
            printf("\n");
        }
        for (int j = 0; j < mat[i].size(); ++j) {
            printf("%2d", mat[i][j]);
        }
    }
    printf("\n");
}

int numSpecial(vector<vector<int>>& mat) {
    if (mat.empty()) {
        return 0;
    }
    vector<int> row(mat.size(), 0);
    vector<int> col(mat[0].size(), 0);
    for (int i = 0; i < mat.size(); ++i) {
        for (int j = 0; j < mat[i].size(); ++j) {
            col[j] += mat[i][j];
            row[i] += mat[i][j];
        }
    }
    cout << "row: " << row << endl;
    cout << "col: " << col << endl;
    int ret = 0;
    for (int i = 0; i < mat.size(); ++i) {
        for (int j = 0; j < mat[i].size(); ++j) {
            if (row[i] == 1 && col[j] == 1) {
                ++ret;
            }
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<vector<int>> v = {{1,0,0},{0,0,1},{1,0,0}};
    show(v);
    cout << numSpecial(v) << endl;
}
