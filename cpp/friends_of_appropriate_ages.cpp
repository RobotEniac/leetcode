// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/12/27 17:42:01
// Description: https://leetcode-cn.com/problems/friends-of-appropriate-ages/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int numFriendRequests(vector<int> &ages)
{
    sort(ages.begin(), ages.end());
    int count = 0;
    for (int i = 0; i < ages.size(); ++i) {
        for (int j = 0; j < ages.size() && ages[j] < ages[i]; ++j) {
            if (ages[i] < 100 && ages[j] > 100) {
                continue;
            }
            if (2 * ages[j] - 14 <= ages[i]) {
                continue;
            }
            ++count;
            cout << ages[i] << ", " << ages[j] << endl;
        }
    }
    return count;
}

int main(int argc, char *argv[])
{
    vector<int> a = {20,30,100,110,120};
    cout << numFriendRequests(a) << endl;
}
