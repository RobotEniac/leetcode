// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/08/23 14:23:25
// Description: https://leetcode.com/problems/generate-parentheses/

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>

#include "util.h"

using namespace std;

void gen(vector<string> &res, const std::string s, int left, int right) {
    cout << "(" << left << ", " << right << ")\n";
    if (left == 0 && right == 0) {
        res.push_back(s);
    }
    if (left > 0) gen(res, s + "(", left - 1, right);
    if (right > left) gen(res, s + ")", left, right - 1);
}

vector<string> generateParenthesis(int n) {
    vector<string> ret;
    gen(ret, "", n, n);
    return ret;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    vector<string> expected = {
        "(((())))",
        "((()()))",
        "((())())",
        "((()))()",
        "(()(()))",
        "(()()())",
        "(()())()",
        "(())(())",
        "(())()()",
        "()((()))",
        "()(()())",
        "()(())()",
        "()()(())",
        "()()()()"
    };
    vector<string> res = generateParenthesis(n);
    for (auto it = expected.begin(); it != expected.end(); ++it) {
        cout << *it << ", ";
    }
    cout << endl;
    for (auto it = res.begin(); it != res.end(); ++it) {
        cout << *it << ", ";
    }
    cout << endl;
}
