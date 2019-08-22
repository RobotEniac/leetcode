// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/08/06 21:09:34
// Description: https://leetcode.com/problems/contains-duplicate/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

#include "util.h"

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    if (nums.size() < 2) {
        return false;
    }
    unordered_set<int> s(nums.begin(), nums.end());
    if (s.size() < nums.size()) {
        return true;
    }
    return false;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    srand(time(NULL));
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        a.push_back(rand() % 100);
    }
    cout << a << endl;
    cout << boolalpha << containsDuplicate(a) << endl;
    sort(a.begin(), a.end());
    cout << a << endl;
}
