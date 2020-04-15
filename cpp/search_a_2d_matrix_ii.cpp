// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/02/17 10:31:06
// Description: https://leetcode.com/problems/search-a-2d-matrix-ii/

#include <stdio.h>

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

void show(vector<vector<int>>& m, int x1, int y1, int x2, int y2) {
    printf("===(%d, %d)===\n", x1, y1);
    for (int i = x1; i < x2; ++i) {
        if (i != x1) {
            printf("\n");
        }
        for (int j = y1; j < y2; ++j) {
            printf("%4d", m[i][j]);
        }
    }
    printf("\n===(%d, %d)===\n", x2,y2);
}

bool search(vector<vector<int>> &m, int t, int x1, int y1, int x2, int y2) {
    show(m, x1, y1, x2, y2);
    if (x1 >= x2 || y1 >= y2) {
        return false;
    }
    if (t < m[x1][y1] || t > m[x2-1][y2-1]) {
        return false;
    }
    int xm = (x1 + x2) / 2;
    int ym = (y1 + y2) / 2;
    if (m[xm][ym] == t) {
        return true;
    }
    if (m[xm][ym] > t) {
        return search(m, t, x1, y1, xm, y2) 
            || search(m, t, x1, y1, x2, ym);
    }
    if (m[xm][ym] < t) {
        return search(m, t, xm+1, y1, x2, y2)
            || search(m, t, x1, ym+1, x2, y2);
    }
    return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
        return false;
    }
    return search(matrix, target, 0, 0, matrix.size(), matrix[0].size());
}

bool searchMatrix2(vector<vector<int>> &matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
        return false;
    }
    int m = matrix.size();
    int n = matrix[0].size();
    int i = 0;
    int j = n-1;
    while (i < m && j >= 0) {
        if (matrix[i][j] == target) {
            return true;
        }
        if (matrix[i][j] < target) {
            ++i;
        } else {
            --j;
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
    bool ret = false;
    vector<vector<int>> m = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    cout << boolalpha << searchMatrix2(m, atoi(argv[1])) << endl;;

    vector<vector<int>> m2 = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    vector<vector<int>> m3 = {{-1, 3}};

}
