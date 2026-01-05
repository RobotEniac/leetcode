// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/09/17 09:15:04
// Description: https://leetcode.cn/problems/count-the-number-of-ideal-arrays/?envType=daily-question&envId=2025-09-16

#include <iostream>
#include <vector>
#include <string>
#include <queue>

#include "util.h"

using namespace std;

vector<int> primes(int n) {
    vector<int> ret;
    ret.push_back(1);
    if (n < 2) {
        return ret;
    }
    ret.push_back(2);
    for (int i = 3; i <= n; ++i) {
        bool is_prime = true;
        for (int j = 1; j < ret.size(); ++j) {
            if (i % ret[j] == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            ret.push_back(i);
        }
    }
    return ret;
}

int idealArrays(int n, int maxValue)
{
    struct Node {
        int len;
        int last;
    };
    queue<Node> q;
    for (int i = 1; i <= maxValue; ++i) {
        Node n;
        n.len = 1;
        n.last = i;
        q.push(n);
    }
    while (!q.empty() && q.front().len < n) {
        Node nd = q.front();
        q.pop();
        for (int i = 1; i <= maxValue; ++i) {
            int64_t t = (int64_t)nd.last * (int64_t)i;
            if (t <= maxValue) {
                Node nn;
                nn.len = nd.len+1;
                nn.last = t;
                q.push(nn);
            } else {
                break;
            }
        }
    }
    return q.size();
}

/**
 * @brief 先假设完美数组为: [a_0, a_1, a_2, ..., a_n-1]，令q_i = a_i / a_i-1, 则完美数组的商差为
 * [q_0, q_1, q_2, ..., q_n-1], 且满足条件：
 * 
 * q_0 * q_1 * q_2 *... * q_n-1 = a_0 * a_1/a_0 * a_2/a_1 *... * a_n-1/a_n-2 = a_n-1
 * 从而得出，以a_n-1为结尾的完美数组个数，即不同的商差数组个数。驾驶a_n-1 = 8 = 2*2*2，问题转换为将这3个2放到1~n共n个盒子
 * 里有几种放法
 */

int main(int argc, char *argv[]) {
    cout << idealArrays(2, 5) << endl;
}
