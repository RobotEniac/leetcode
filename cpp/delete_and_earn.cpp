// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2024/06/06 20:54:20
// Description: https://leetcode.cn/problems/delete-and-earn/description/?envType=study-plan-v2&envId=dynamic-programming

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "util.h"

using namespace std;

int deleteAndEarn1(vector<int>& nums) {
    map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
        if (m.find(nums[i]) == m.end()) {
            m[nums[i]] = 1;
        } else {
            ++m[nums[i]];
        }
    }
    int max_sum = INT_MIN;
    for (auto it = m.begin(); it != m.end(); ++it) {
        map<int, int> tm = m;
        int pt = it->first;
        int sum = pt;
        if (it->second == 1) {
            tm.erase(pt);
        } else {
            --tm[pt];
        }
        cout << pt << ", ";
        while (!tm.empty()) {
            auto sub = tm.find(pt-1);
            auto plus = tm.find(pt+1);
            if (sub == tm.end() && plus == tm.end()) {
                if (!tm.empty()) {
                    pt = tm.begin()->first;
                    cout << pt << ", ";
                    if (tm.begin()->second == 1) {
                        tm.erase(pt);
                    } else {
                        --(tm.begin()->second);
                    }
                    sum += pt;
                }
            }
            if (sub != tm.end()) {
                tm.erase(sub);
            }
            if (plus != tm.end()) {
                tm.erase(plus);
            }
        }
        cout << " = " << sum << endl;
        if (sum > max_sum) {
            max_sum = sum;
        }
    }
    return max_sum;
}

int deleteAndEarn(vector<int>& nums) {
    std::map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
        if (m.find(nums[i]) == m.end()) {
            m[nums[i]] = 1;
        } else {
            ++m[nums[i]];
        }
    }
    if (m.size() == 1) {
        return nums[0] * nums.size();
    }
    vector<int> dp(m.size(), 0);
    auto pre_it = m.rbegin();
    auto it = m.rbegin();
    int n = m.size() - 1;
    dp[n] = it->first * it->second;
    ++it;
    dp[n-1] = (pre_it->first - it->first == 1) ? (it->first * it->second) : (dp[n]+it->first * it->second);
    cout << dp << endl;
    n = n-2;
    pre_it = it;
    ++it;
    while (n >= 0) {
        cout << dp << endl;
        if (pre_it->first-it->first == 1) {
            dp[n] = max(dp[n+1], dp[n+2] + it->first * it->second);
        } else {
            dp[n] = dp[n+1] + it->first * it->second;
        }
        --n;
        pre_it = it;
        ++it;
    }
    return dp[0];
}

int main(int argc, char *argv[]) {
    vector<int> v = {2,2,3,3,3,4};
    cout << v << endl;
    cout << deleteAndEarn(v) << endl;
}
