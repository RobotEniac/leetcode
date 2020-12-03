// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/02/17 12:47:56
// Description: https://leetcode.com/problems/different-ways-to-add-parentheses/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

vector<int> diffWaysToCompute(string input) {
    vector<int> res;
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == '+'
                || input[i] == '-'
                || input[i] == '*') {
            vector<int> nums1 = diffWaysToCompute(input.substr(0, i));
            vector<int> nums2 = diffWaysToCompute(input.substr(i+1));
            for (int n1 : nums1) {
                for (int n2 : nums2) {
                    switch (input[i]) {
                    case '+':
                        res.push_back(n1 + n2);
                        break;
                    case '-':
                        res.push_back(n1 - n2);
                        break;
                    case '*':
                        res.push_back(n1 * n2);
                    }
                }
            }
        }
    }
    if (res.empty()) {
        res.push_back(atoi(input.c_str()));
    }
}

int main(int argc, char *argv[]) {
}
