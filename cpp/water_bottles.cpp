// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/10/11 10:11:38
// Description: https://leetcode.cn/problems/water-bottles/description/?envType=daily-question&envId=2025-09-29

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int numWaterBottles(int numBottles, int numExchange)
{
    int sum = numBottles;
    int c = 0;
    while (numBottles >= numExchange) {
        sum += numBottles / numExchange;
        numBottles = (numBottles / numExchange) + (numBottles % numExchange);
    }
    return sum;
}

int main(int argc, char *argv[]) {
    cout << numWaterBottles(15, 4) << endl;
}
