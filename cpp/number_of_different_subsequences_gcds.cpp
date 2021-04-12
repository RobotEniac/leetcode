// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/04/09 11:55:48
// Description: https://leetcode-cn.com/problems/number-of-different-subsequences-gcds/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void cal(const vector<int>& a, std::set<int>& s) {
    bool flag = false;
    for (int i = 0; i < a.size(); ++i) {
        for (int j = i+1; j < a.size(); ++j) {
            int r = gcd(a[i], a[j]);
            if (s.find(r) == s.end()) {
                flag = true;
                s.insert(r);
            }
        }
    }
    if (flag) {
        cal(vector<int>(s.begin(), s.end()), s);
    }
}

int countDifferentSubsequenceGCDs(vector<int>& nums) {
    std::set<int> s;
    cal(nums, s);
    for (int i = 0; i < nums.size(); ++i) {
        s.insert(nums[i]);
    }
    return s.size();
}

int countDifferentSubsequenceGCDs2(vector<int>& nums) {
    int c = *max_element(nums.begin(), nums.end());
    vector<int> g(c + 1);

    for (int x: nums) {
        for (int y = 1; y * y <= x; ++y) {
            if (x % y == 0) {
                if (!g[y]) {
                    g[y] = x;
                }
                else {
                    g[y] = gcd(g[y], x);
                }
                if (y * y != x) {
                    int z = x / y;
                    if (!g[z]) {
                        g[z] = x;
                    }
                    else {
                        g[z] = gcd(g[z], x);
                    }
                }
            }
        }
    }
    cout << g << endl;

    int ans = 0;
    for (int i = 1; i <= c; ++i) {
        if (g[i] == i) {
            ++ans;
        }
    }
    return ans;
}


int main(int argc, char *argv[]) {
    vector<int> an = {5,15,40,5,6};
    cout << countDifferentSubsequenceGCDs2(an) << endl;
}
