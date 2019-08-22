// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/08/12 11:18:58
// Description: https://leetcode.com/problems/rectangle-area/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int overlap(int x1, int x2, int y1, int y2) {
    cout << "(" << x1 << ", " << x2 << ") (" << y1 << ", " << y2 << ")"; 
    if (y2 <= x1 || y1 >= x2) {
        return 0;
    }
    if (y1 <= x1 && y2 >= x2) {
        return x2 - x1;
    }
    if (y1 <= x1 && y2 <= x2) {
        return y2 - x1;
    }
    if (y1 >= x1 && y2 <= x2) {
        return y2 - y1;
    }
    if (y1 >= x1 && y2 >= x2) {
        return x2 - y1;
    }
    return 0;
}

int area(int x1, int y1, int x2, int y2) {
    return (y2 - y1) * (x2 - x1);
}

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int length = overlap(A, C, E, G);
    int width = overlap(B, D, F, H);
    int64_t s1 = area(A, B, C, D);
    int64_t s2 = area(E, F, G, H);
    return s1 + s2 - length * width;
}

int main(int argc, char *argv[]) {
    int A = 0;
    int B = 0;
    int C = 40000;
    int D = 50000;
    int E = 0;
    int F = 0;
    int G = 40000;
    int H = 50000;
    cout << computeArea(A, B, C, D, E, F, G, H);
}
