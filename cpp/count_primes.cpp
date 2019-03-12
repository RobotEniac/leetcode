// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/03/07 15:40:52
// Description: https://leetcode.com/problems/count-primes/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

vector<uint8_t> CreateBitMap(int n) {
    vector<uint8_t> ret(n / 8 + 1, 0);
    return ret;
}

void Set(vector<uint8_t> &bits, int n) {
    bits[n/8] = bits[n/8] | (1 << (n%8));
}

int Get(vector<uint8_t> &bits, int n) {
    return (bits[n/8] & (1 << (n%8))) >> (n % 8);
}

void Print(vector<uint8_t> &bits) {
    for (int i = 0; i < bits.size() * 8; ++i) {
        printf("%3d", i);
    }
    printf("\n");
    for (int i = 0; i < bits.size() * 8; ++i) {
        printf("%3d", Get(bits, i));
    }
    printf("\n");
}

int countPrimes(int n) {
    if (n < 2) {
        return 0;
    }
    vector<uint8_t> bits = CreateBitMap(n + 1);
    for (int i = 2; i <= n; ++i) {
        if (Get(bits, i)) {
            continue;
        }
        int t = i + i;
        while (t < n) {
            Set(bits, t);
            t += i;
        }
    }
    int ret = 0;
    for (int i = 2; i < n; ++i) {
        if (Get(bits, i) == 0) {
            ++ret;
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    cout << countPrimes(atoi(argv[1])) << endl;
}
