// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/05/06 15:27:27
// Description: https://leetcode-cn.com/problems/insert-into-bits-lcci/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

void bput(uint32_t i) {
    while (i != 0) {
        printf("%2d", i & 0x1);
        i = i >> 1;
    }
    printf("\n");
}

int insertBits(int N, int M, int i, int j) {
    int len = j - i +1;
    unsigned int t = 0;
    while (len > 0) {
        t = (t << 1) | 1;
        --len;
    }
    bput(N);
    bput(t);
    bput(M << i);
    return N & ~(t << i) | (M << i);
}

int main(int argc, char *argv[]) {
    cout << insertBits(1143207437, 1017033, 11, 31) << "\n";
}
