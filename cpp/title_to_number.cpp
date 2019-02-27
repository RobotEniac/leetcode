// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/02/27
// Description: 

#include "util.h"

#include <string>
#include <iostream>

using namespace std;

int titleToNumber(string s) {
    int sum = 0;
    for (int i = 0; i < s.size(); ++i) {
        int n = s[i] - 'A' + 1;
        sum = sum * 26 + n;
    }
    return sum;
}

string convertToTitle(int n) {
    std::string ret;
    while (n > 0) {
        n = n - 1;
        int dev = n / 26;
        int remain = n % 26;
        ret.push_back('A' + remain);
        n = dev;
    }
    for (int i = 0, j = ret.size() - 1; i < j; ++i, --j) {
        char c = ret[i];
        ret[i] = ret[j];
        ret[j] = c;
    }
    return ret;
}

int main(int argc, char *argv[]) {
    string s(argv[1]);
    cout << "origin: " << s << "\n";
    int i = titleToNumber(s);
    cout << "number = " << i << "\n";
    cout << "reverse: " << convertToTitle(i) << "\n";
}

