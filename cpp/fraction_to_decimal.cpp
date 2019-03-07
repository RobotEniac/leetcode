// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/02/18
// Description: 

#include <stdlib.h>

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "util.h"

using namespace std;

string fractionToDecimal(int numerator, int denominator) {
    if (denominator == 0) {
        return "";
    }
    stringstream ss;
    vector<int> res;
    int64_t div = 0;
    int64_t remain = numerator;
    int64_t d = 0;
    int repeat = -1;
    if ((remain > 0 && denominator < 0)
            || (remain < 0 && denominator > 0)) {
        ss << "-";
    }
    remain = remain > 0 ? remain : -remain;
    d = denominator > 0 ? denominator : -(long)denominator;
    vector<int> ary;
    div = remain / d;
    remain = remain - d * div;
    if (remain == 0) {
        ss << div;
        return ss.str();
    }
    ss << div << ".";
    while (remain != 0 && repeat < 0) {
        ary.push_back(remain);
        div = (remain * 10) / d;
        remain = (remain * 10)  % d;
        res.push_back(div);
        for (int i = 0; i < ary.size(); ++i) {
            if (remain == ary[i]) {
                repeat = i;
                break;
            }
        }
        if (repeat > 0) {
            break;
        }
    }

    for (int i = 0; i < res.size(); ++i) {
        if (repeat >= 0 && i == repeat) {
            ss << "(";
        }
        ss << res[i];
    }
    if (repeat >= 0) {
        ss << ")";
    }
    return ss.str();
}

int main(int argc, char *argv[]) {
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    std::cout << fractionToDecimal(a, b) << endl;

    long x = 1000000000;
    long y = 2147483648;
    std::cout << x * 10 / y << endl;
}
