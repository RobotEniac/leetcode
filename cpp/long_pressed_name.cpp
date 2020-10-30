// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/10/21 22:43:31
// Description: https://leetcode.com/problems/long-pressed-name/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

bool check(const char* name, const char *typed, char last) {
    if (*name == 0) {
        while (*typed != 0 && last != 0) {
            if (*typed != last) {
                return false;
            }
            ++typed;
        }
        return true;
    }
    if (*name != 0 && *typed == 0) {
        return false;
    }
    if (*name == *typed) {
        return check(name+1, typed+1, *name);
    }
    if (last != 0 && *typed == last)
        return check(name, ++typed, last);
    return false;
}

bool isLongPressedName(string name, string typed) {
    if (typed.size() < name.size()) {
        return false;
    }
    return check(name.c_str(), typed.c_str(), 0);
}

int main(int argc, char *argv[]) {
    string name(argv[1]);
    string typed(argv[2]);
    cout << boolalpha << isLongPressedName(name, typed) << endl;
}
