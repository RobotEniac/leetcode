// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/02/21
// Description: 

#include <vector>
#include <sstream>
#include <iostream>

#include "util.h"

using namespace std;

string convertToTitle(int n) {
    vector<int> num;
    std::string ret;
    while (n >= 0) {
        n = n / 26 - 1;
        int remain = n % 26;
        num.push_back(remain);
        ret.push_back('A' + remain);
    }
    return ret;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    cout << "n = " << n << ", col: " << convertToTitle(n) << "\n";
}

