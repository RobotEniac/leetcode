// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/03/11 23:28:38
// Description: https://leetcode.com/problems/nim-game/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

bool canWinNim(int n) {
    if (n <= 3) {
        return true;
    }
    // 0 for first gamer, 1 for second gamer
    bool a = false;
    bool a_1 = true;
    bool a_2 = true;
    bool a_3 = true;
    for (int i = 4; i <= n; ++i) {
        a = !(a_1 && a_2 && a_3);
        a_3 = a_2;
        a_2 = a_1;
        a_1 = a;
    }
    return a;
}

int main(int argc, char *argv[]) {
    // 1348820612
    int i = atoi(argv[1]);
        cout << boolalpha << i << ":" << canWinNim(i) << endl;
}
