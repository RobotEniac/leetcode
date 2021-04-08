// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/04/01 10:56:10
// Description: https://leetcode-cn.com/problems/clumsy-factorial/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

typedef std::function<int64_t(int64_t, int64_t)> CalFun;

int pri[4] = {1, 1, 0, 0};

int64_t cal(int N, CalFun fun[], int64_t res, int64_t curr) {
    if (curr == 0) {
        return res;
    }
    int idx = (N-1-curr)%4;
    int next = (N-curr) % 4;
    if (pri[idx] >= pri[next]) {
        return cal(N, fun, fun[idx](res, curr), curr-1);
    }
    int i = N - curr;
    int64_t tmp = curr;
    while (i < N-1 && pri[idx] < pri[i%4]) {
        --curr;
        tmp = fun[i%4](tmp, curr);
        ++i;
    }
    return cal(N, fun, fun[idx](res, tmp), curr-1);
}

int clumsy(int N) {
    CalFun fun[4];
    int pri[4] = {1, 1, 0, 0};
    fun[0] = [](int64_t a, int64_t b) -> int64_t {
        return a * b;
    };
    fun[1] = [](int64_t a, int64_t b) -> int64_t {
        return a / b;
    };
    fun[2] = [](int64_t a, int64_t b) -> int64_t {
        return a + b;
    };
    fun[3] = [](int64_t a, int64_t b) -> int64_t {
        return a - b;
    };

    int64_t res = N;
    int64_t curr = N - 1;
    while (curr > 0) {
        int idx = (N-1-curr) % 4;
        int next = (N-curr) % 4;
        if (pri[idx] >= pri[next]) {
            res = fun[idx](res, curr);
            --curr;
        } else {
            int64_t tmp = curr;
            while (curr > 1 && pri[idx] < pri[next]) {
                tmp = fun[next](tmp, curr-1);
                --curr;
                next = (N - curr) % 4;
            }
            res = fun[idx](res, tmp);
            --curr;
        }
    }
    return res;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    cout << clumsy(n) << endl;
}
