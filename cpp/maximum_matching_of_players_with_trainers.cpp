// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/08/28 17:36:55
// Description: https://leetcode.cn/problems/maximum-matching-of-players-with-trainers/?envType=daily-question&envId=2025-08-27

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
    sort(players.begin(), players.end());
    sort(trainers.begin(), trainers.end());
    if (trainers[0] >= players[players.size() - 1]) {
        return players.size();
    }
    if (trainers[trainers.size() - 1] < players[0]) {
        return 0;
    }
    int i = 0;
    int j = 0;
    int ret = 0;
    while (i < players.size() && j < trainers.size()) {
        if (players[i] <= trainers[j]) {
            ++ret;
            ++i;
            ++j;
        } else {
            ++j;
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    cout << "hello world" << endl;
}
