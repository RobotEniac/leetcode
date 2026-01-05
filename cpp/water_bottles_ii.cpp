// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/11/17 20:59:31
// Description: https://leetcode.cn/problems/water-bottles-ii/description/?envType=daily-question&envId=2025-11-17

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int maxBottlesDrunk(int numBottles, int numExchange) {
    int drink = numBottles;
    int empty = numBottles;
    while (empty >= numExchange) {
        empty = empty - numExchange + 1;
        numExchange += 1;
        drink += 1;
    }
    return drink;
}

int main(int argc, char *argv[]) {
    cout << maxBottlesDrunk(13, 6) << endl;
    cout << maxBottlesDrunk(10, 3) << endl;
}
