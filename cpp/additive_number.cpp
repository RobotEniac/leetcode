// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/04/26 11:02:12
// Description: https://leetcode.com/problems/additive-number/

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int64_t toNumber(const string& s) {
    if (s.empty()) {
        return -1;
    }
    if (s[0] == '0' && s.size() > 1) {
        return -1;
    }
    return atol(s.c_str());
}

string toString(int64_t i) {
    stringstream ss;
    ss << i;
    return ss.str();
}

bool satisfy(int64_t n1, int64_t n2, string& s, int begin) {
    if (begin == s.size()) {
        return true;
    }
    int64_t sum_int = n1 + n2;
    string sum = toString(sum_int);
    if (sum.size() > s.size() - begin) {
        return false;
    }
    for (int i = 0; i < sum.size(); ++i) {
        if (sum[i] != s[begin+i]) {
            return false;
        }
    }
    return satisfy(n2, sum_int, s, begin + sum.size());
}

bool isAdditiveNumber(string num) {
    for (int i = 1; i <= num.size() / 2; ++i) {
        int64_t n1 = toNumber(num.substr(0, i));
        if (n1 < 0) {
            continue;
        }
        for (int j = i+1; j < num.size(); ++j) {
            int64_t n2 = toNumber(num.substr(i, j - i));
            if (n2 < 0) {
                continue;
            }
            if (satisfy(n1, n2, num, j)) {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
    string n(argv[1]);
    cout << boolalpha << n << ": " << isAdditiveNumber(n) << "\n";
}
