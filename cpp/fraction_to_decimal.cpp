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
    if (denominator == INT_MAX || denominator == INT_MIN) {
        return "0";
    }
    stringstream ss;
    vector<int> res;
    int div = 0;
    int remain = numerator;
    int repeat = -1;
    if (numerator < 0) {
        if (denominator > 0) {
            ss << "-";
        } else {
            denominator = - denominator;
        }
        numerator = -numerator;
    }

    if (numerator > 0 && denominator < 0) {
        ss << "-";
        denominator = -denominator;
    }
    vector<int> ary;
    div = numerator / denominator;
    remain = numerator - denominator * div;
    if (remain == 0) {
        ss << div << ".0";
        return ss.str();
    }
    ss << div << ".";
    while (remain != 0 && repeat < 0) {
        ary.push_back(remain);
        div = remain * 10 / denominator;
        remain = remain * 10 - (div * denominator);
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
}
