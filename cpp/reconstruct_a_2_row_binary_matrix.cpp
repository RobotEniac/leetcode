// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/06/29 15:48:55
// Description: https://leetcode.cn/problems/reconstruct-a-2-row-binary-matrix/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
    int sum = 0;
    for (int i = 0; i < colsum.size(); ++i) {
        sum += colsum[i];
    }
    if (sum > upper + lower) {
        return vector<vector<int>>();
    }
    vector<int> vu(colsum.size(), 0);
    vector<int> vl(colsum.size(), 0);
    for (int i = 0; i < colsum.size(); ++i) {
        if (colsum[i] == 2) {
            vu[i] = 1;
            vl[i] = 1;
            --upper;
            --lower;
        } else if (colsum[i] == 1) {
            if (upper >= lower) {
                vu[i] = 1;
                --upper;
            } else {
                vl[i] = 1;
                --lower;
            }
        }
        if (upper < 0 || lower < 0) {
            return vector<vector<int>>();
        }
    }
    vector<vector<int>> r(2, vector<int>());
    r[0] = vu;
    r[1] = vl;
    return r;
}

int main(int argc, char *argv[]) {
    vector<int> c = {2,1,2,2,1,1,1};
    vector<vector<int>> r = reconstructMatrix(4, 7, c);
    for (int i = 0; i < r.size(); ++i) {
        cout << r[i] << endl;
    }
}
