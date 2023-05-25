// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/05/23 15:33:32
// Description: https://leetcode.cn/problems/minimum-one-bit-operations-to-make-integers-zero/

#include <unistd.h>

#include <iostream>
#include <vector>
#include <string>
#include <bitset>

#include "util.h"

using namespace std;

int flip1(int& n) {
    n = n ^ 1;
    return n;
}

int flip2(int n) {
    int i = 0;
    while ((n & ((1 << i) - 1)) == 0) {
        ++i;
    }
    return n ^ (1 << i);
}

bool dfs(int n, vector<int>& path) {
    cout << n << ", " << path << endl;
    sleep(1);
    if (n == 0) {
        return true;
    }
    if (n == 1) {
        path.push_back(1);
        return true;
    }
    if (path.empty() || path[path.size() - 1] != 1) {
        path.push_back(1);
        if (dfs(flip1(n), path)) {
            return true;
        }
        path.pop_back();
    } else {
        path.push_back(2);
        if (dfs(flip2(n), path)) {
            return true;
        }
        path.pop_back();
    }
    return false;
}

int direct(int n) {
    bitset<32> b(n);
    bitset<32> ret;
    for (int i = 30; i >= 0; --i) {
        ret[i] = b[i+1] ^ b[i];
    }
    return ret.to_ulong();
}

int cal(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    int s = 0;
    int n1 = n;
    int n2 = n;
    while (n1 != 0 && n2 != 0) {
        cout << n1 << ", " << n2 << endl;
        sleep(1);
        if ((s & 1) == 0) {
            n1 = flip1(n1);
            n2 = flip2(n2);
        } else {
            n1 = flip2(n1);
            n2 = flip1(n2);
        }
        ++s;
    }
    return s;
}
int minimumOneBitOperations(int n) {
    return direct(n);
}

int main(int argc, char *argv[]) {
    cout << minimumOneBitOperations(6) << endl;
    cout << minimumOneBitOperations(150291880) << endl;
}
