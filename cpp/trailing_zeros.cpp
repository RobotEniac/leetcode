// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/02/22
// Description: 

#include <iostream>
#include <string>

using namespace std;

int trailingZeroes(int n) {
    int cnt2 = 0;
    int cnt5 = 0;
    int t = n;
    while (t != 0) {
        cnt5 += t / 5;
        t = t / 5;
    }
    t = n;
    while (t != 0) {
        cnt2 += t / 2;
        t = t / 2;
    }
    return (cnt2 < cnt5 ? cnt2 : cnt5);
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    cout << "zero number of " << n << " is " << trailingZeroes(n) << "\n";
}
