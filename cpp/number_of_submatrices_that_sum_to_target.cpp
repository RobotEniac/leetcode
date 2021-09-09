// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/04/26 11:08:40
// Description: https://leetcode-cn.com/problems/number-of-submatrices-that-sum-to-target/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

void show(vector<vector<int>> &m) {
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m[i].size(); ++j) {
            printf("%4d", m[i][j]);
        }
        printf("\n");
    }
    cout << "================================================================================\n";
}

int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    show(matrix);
    vector<vector<int>> sum(matrix.size(), vector<int>(matrix[0].size(), 0));

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (i == 0 && j == 0) {
                sum[0][0] = matrix[0][0];
            } else if (i == 0) {
                sum[i][j] = sum[i][j-1] + matrix[i][j];
            } else if (j == 0) {
                sum[i][j] = sum[i-1][j] + matrix[i][j];
            } else {
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i][j];
            }
        }
    }
    show(sum);
    int ret = 0;
    for (int x = 0; x < matrix.size(); ++x) {
        for (int y = 0; y < matrix[x].size(); ++y) {
            for (int i = x; i < matrix.size(); ++i) {
                for (int j = y; j < matrix[i].size(); ++j) {
                    int s = 0;
                    if (i == x && j == y) {
                        s = matrix[i][j];
                    } else if (i == 0 && j == 0) {
                        s = matrix[0][0];
                    } else if (i == 0) {
                        if (y == 0) {
                            s = sum[i][j];
                        } else {
                            s = sum[i][j] - sum[x][y-1];
                        }
                    } else if (j == 0) {
                        if (x == 0) {
                            s = sum[i][j];
                        } else {
                            s = sum[i][j] - sum[x-1][y];
                        }
                    } else {
                        if (x == 0 && y ==0) {
                            s = sum[i][j];
                        } else if (x == 0) {
                            s = sum[i][j] - sum[i][y-1];
                        } else if (y == 0) {
                            s = sum[i][j] - sum[x-1][j];
                        } else {
                            s = sum[i][j] - sum[x-1][j] - sum[i][y-1] + sum[x-1][y-1];
                        }
                    }
                    if (s == target) {
                        ++ret;
                    }
                }
            }
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<vector<int>> m(4, vector<int>(4, 0));
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m[i].size(); ++j) {
            m[i][j] = rand() % 10;
        }
    }
    vector<vector<int>> m1 = {{1, -1}, {-1, 1}};
    cout << numSubmatrixSumTarget(m1, 0) << endl;
}
