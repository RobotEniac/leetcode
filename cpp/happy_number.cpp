// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/03/07 11:57:00
// Description: https://leetcode.com/problems/happy-number/

#include <iostream>
#include <vector>
#include <string>
#include <set>

#include "util.h"

using namespace std;

bool isHappy(int n) {
    if (n == 0) {
        return false;
    }
    if (n == 1) {
        return true;
    }
    set<int> s;
    printf("%d", n);
    s.insert(n);
    while (true) {
        int sum = 0;
        while (n != 0) {
            int r = n % 10;
            sum += r * r;
            n = n / 10;
        }
        printf("->%d", sum);
        if (sum == 1) {
            return true;
        }
        if (s.find(sum) != s.end()) {
            return false;
        }
        n = sum;
        s.insert(n);
    }
    return false;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    for (int i = 1; i <= n; ++i) {
        bool ret = isHappy(i);
        cout << boolalpha << " ..." << ret << endl;
    }
    cout << "hello world" << endl;
}
