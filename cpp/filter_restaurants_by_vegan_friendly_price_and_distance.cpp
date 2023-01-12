// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2022/12/07 19:56:24
// Description: https://leetcode.cn/problems/filter-restaurants-by-vegan-friendly-price-and-distance/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

// restaurants[i] = [idi, ratingi, veganFriendlyi, pricei, distancei]

vector<int> filterRestaurants(vector<vector<int>>& restaurants,
                              int veganFriendly, int maxPrice, int maxDistance)
{
    vector<int> ret;
    for (int i = 0; i < restaurants.size(); ++i) {
        if (veganFriendly && !restaurants[i][2]) {
            continue;
        }
        if (restaurants[i][3] > maxPrice) {
            continue;
        }
        if (restaurants[i][4] > maxDistance) {
            return false;
        }
        if (ret.empty()) {
            ret.push_back(i);
            continue;
        }
        int j = ret.size() - 1;
        ret.push_back[i];
        while (j >= 0) {
            if (restaurants[ret[j]][1] > restaurants[i][1]) {

            }
        }
    }
}

int main(int argc, char *argv[]) {
    cout << "hello world" << endl;
}
