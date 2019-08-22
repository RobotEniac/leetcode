// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/08/15 10:18:53
// Description: https://leetcode.com/problems/basic-calculator/

#include <iostream>
#include <vector>
#include <string>
#include <stack>

#include "util.h"

using namespace std;

const int GUARD = INT_MAX;

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

int to_int(const string &s) {
    int t = atoi(s.c_str());
    return t;
}

int calculate(string s) {
    vector<int> number;
    stack<char> sign;
    int start = 0;
    bool success = true;
    while (start < s.size() && success) {
        if (s[start] == ' ' 
                || s[start] == '\t'
                || s[start] == '\n') {
            ++start;
            continue;
        }
        int e = start;
        if (is_digit(s[e])) {
            while(e < s.size() && is_digit(s[e])) {
                ++e;
            }
            string ns = s.substr(start, e-start);
            number.push_back(to_int(ns));
            start = e;
            if (number.size() >=2 && number[number.size() - 2] != GUARD) {
                char op = sign.top();
                sign.pop();
                int x = number[number.size() - 2];
                int y = number[number.size() - 1];
                number.pop_back();
                number.pop_back();
                if (op == '-') {
                    number.push_back(x - y);
                } else if (op == '+') {
                    number.push_back(x + y);
                } else {
                    success = false;
                    break;
                }
            }
        } else if (s[e] == '+' || s[e] == '-') {
            sign.push(s[e]);
            ++start;
        } else if (s[e] == '(') {
            sign.push(s[e]);
            ++start;
            number.push_back(GUARD);
        } else if (s[e] == ')') {
            ++start;
            if (number.size() >= 2 && sign.top() == '(') {
                if (number[number.size() - 2] == GUARD) {
                    int x = number.back();
                    number.pop_back();
                    number.pop_back();
                    sign.pop();
                    number.push_back(x);
                    if (number.size() >=2 && number[number.size() - 2] != GUARD) {
                        char op = sign.top();
                        sign.pop();
                        int x = number[number.size() - 2];
                        int y = number[number.size() - 1];
                        number.pop_back();
                        number.pop_back();
                        if (op == '-') {
                            number.push_back(x - y);
                        } else if (op == '+') {
                            number.push_back(x + y);
                        } else {
                            success = false;
                            break;
                        }
                    }
                }
            } else {
                success = false;
                break;
            }
        } else {
            success = false;
            break;
        }
    }
    if (!success || number.size() != 1) {
        cout << "invalid equation\n";
        return -1;
    }
    return number[0];
}

int main(int argc, char *argv[]) {
    string s(argv[1]);
    cout << s << " = ";
    cout << calculate(s) << endl;
}
