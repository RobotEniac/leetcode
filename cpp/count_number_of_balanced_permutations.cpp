// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/05/09 10:54:19
// Description: https://leetcode.cn/problems/count-number-of-balanced-permutations/description/?envType=daily-question&envId=2025-05-09

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

vector<int> cm;
int n = 0;
int64_t total = 0;

void show(const vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == 0) {
            continue;
        }
        cout << i << " * " << v[i] << ",";
    }
    cout << endl;
}

int64_t jiecheng(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    int64_t ret = 1;
    for (int i = 1; i <= n; ++i) {
        ret *= i;
    }
    return ret;
}

int64_t count(vector<int>& res) {
    int tc = 0;
    int tsum = 0;
    for (int i = 0; i < res.size(); ++i) {
        if (res[i] == 0) {
            continue;
        }
        tc += res[i];
        tsum += i * res[i];
    }
    if (tc != n / 2 || tsum != total / 2) {
        return -1;
    }
    int64_t a = jiecheng(n / 2) * jiecheng(n - n / 2);
    int64_t b = 1;
    for (int i = 0; i < res.size(); ++i) {
        if (res[i] == 0) {
            continue;
        }
        b *= jiecheng(res[i]) * jiecheng(cm[i] - res[i]);
    }
    return a/b;
}

void dfs(int idx, int cnt, int sum, vector<int>& res, int64_t& total_num) {
    static int64_t half = total / 2;
    if (sum > half) {
        return;
    }
    if (idx < 0) {
        if (cnt != 0 || sum != half)
        {
            return;
        }
        int64_t ret = count(res);
        if (ret > 0) {
            cout << ret << ":";
            show(res);
            total_num += ret;
        }
        return;
    }
    cout << "idx=" << idx << ", cnt=" << cnt << ", sum=" << sum << endl;
    if (cm[idx] == 0) {
        dfs(idx-1, cnt, sum, res, total_num);
        return;
    }
    for (int i = 0; i <= cm[idx]; ++i) {
        res[idx] = i;
        dfs(idx - 1, cnt - i, sum + i * idx, res, total_num);
        res[idx] = 0;
    }
}


int countBalancedPermutations(string num) {
    int64_t sum = 0;
    cm = vector<int>(10, 0);
    for (int i = 0; i < num.size(); ++i) {
        sum += num[i] - '0';
        cm[num[i] - '0']++;
    }
    if ((sum & 0x01) == 0x01) {
        return 0;
    }
    n = num.size();
    total = sum;
    vector<int> res(10, 0);
    sum = 0;
    dfs(9, n / 2, 0, res, sum);
    return sum;
}

int main(int argc, char *argv[]) {
    cout << countBalancedPermutations("123") << endl;
}
