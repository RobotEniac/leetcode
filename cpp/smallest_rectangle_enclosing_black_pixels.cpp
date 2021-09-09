// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/04/22 17:52:07
// Description: https://leetcode-cn.com/problems/smallest-rectangle-enclosing-black-pixels/

#include <iostream>
#include <vector>
#include <string>
#include <queue>

#include "util.h"

using namespace std;

void show(vector<vector<char>> &image) {
    for (int i = 0; i < image.size(); ++i) {
        for (int j = 0; j < image[i].size(); ++j) {
            printf("%c", image[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int minArea(vector<vector<char>>& image, int x, int y) {
    vector<vector<int>> dir = {
        {0, -1},
        {-1, 0},
        {0, 1},
        {1, 0}
    };
    queue<vector<int>> q;
    vector<int> pos(2, 0);
    pos[0] = x;
    pos[1] = y;
    q.push(pos);
    int xmin = x;
    int ymin = y;
    int xmax = x;
    int ymax = y;
    while (!q.empty()) {
        vector<int> t = q.front();
        q.pop();
        for (int k = 0; k < dir.size(); ++k) {
            int i = t[0] + dir[k][0];
            int j = t[1] + dir[k][1];
            if (i < 0 || i >= image.size()) {
                continue;
            }
            if (j < 0 || j >= image[i].size()) {
                continue;
            }
            if (image[i][j] == '1') {
                if (i < xmin) {
                    xmin = i;
                }
                if (j < ymin) {
                    ymin = j;
                }
                if (i > xmax) {
                    xmax = i;
                }
                if (j > ymax) {
                    ymax = j;
                }
                pos[0] = i;
                pos[1] = j;
                image[i][j] = '2';
                q.push(pos);
            }
        }
    }
    for (int i = 0; i < image.size(); ++i) {
        for (int j = 0; j < image[i].size(); ++j) {
            if (image[i][j] > '1') {
                image[i][j] = '1';
            }
        }
    }
    return (xmax - xmin + 1) * (ymax - ymin + 1);
}

int main(int argc, char *argv[]) {
    vector<string> ms = {
        "1"
    };

    vector<vector<char>> m(ms.size(), vector<char>(ms[0].size()));
    for (int i = 0; i < ms.size(); ++i) {
        for (int j = 0; j < ms[i].size(); ++j) {
            m[i][j] = ms[i][j];
        }
    }
    show(m);
    cout << minArea(m, 0, 2) << endl;;
}
