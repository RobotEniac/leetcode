// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/11/12 14:59:22
// Description: https://leetcode.com/problems/basic-calculator-ii/

#include <iostream>
#include <vector>
#include <string>
#include <stack>

#include "util.h"

using namespace std;

int E(const char *&p);
int E_sub(int first, const char *&p);
int T_sub(int first, const char *&p);

bool is_space(char c) {
    return c == ' ' || c == '\t';
}

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

int to_digit(char c) {
    return c - '0';
}

int to_num(const char *&p) {
    int n = 0;
    while (is_digit(*p)) {
        n = n * 10 + to_digit(*p);
        ++p;
    }
    return n;
}

void jump_space(const char *&p) {
    while (*p && is_space(*p)) {
        ++p;
    }
}

int E(const char *&p) {
    if (*p == 0) {
        return 0;
    }
    int n1 = 0;
    int n2 = 0;
    jump_space(p);
    n1 = to_num(p);
    jump_space(p);
    if (*p == 0) {
        return n1;
    }
    switch (*p) {
    case '+':
        return E_sub(n1, p);
    case '-':
        return E_sub(n1, p);
    case '*':
        n1 = T_sub(n1, p);
        return E_sub(n1, p);
    case '/':
        n1 = T_sub(n1, p);
        return E_sub(n1, p);
    default:
        cerr << __LINE__ << ": invalid input: " << string(p) << "\n";
    }
    return 0;
}

int E_sub(int first, const char *&p) {
    if (*p == 0) {
        return first;
    }
    int second = 0;
    switch (*p) {
    case '+':
        ++p;
        jump_space(p);
        second = to_num(p);
        jump_space(p);
        if (*p == 0) {
            return first + second;
        }
        if (*p == '+' || *p == '-') {
            return E_sub(first+second, p);
        }
        if (*p == '*' || *p == '/') {
            second = T_sub(second, p);
            return E_sub(first + second, p);
        }
        cerr << __LINE__ << ": invalid input: " << string(p) << "\n";
        break;
    case '-':
        ++p;
        jump_space(p);
        second = to_num(p);
        if (*p == 0) {
            return first - second;
        }
        if (*p == '+' || *p == '-') {
            return E_sub(first-second, p);
        }
        if (*p == '*' || *p == '/') {
            second = T_sub(second, p);
            return E_sub(first - second, p);
        }
        cerr << __LINE__ << ": invalid input: " << string(p) << "\n";
        break;
    default:
        cerr << __LINE__ << ": invalid input: " << string(p) << "\n";
    }
    return 0;
}

int T_sub(int first, const char *&p) {
    int second = 0;
    switch (*p) {
    case '*':
        ++p;
        jump_space(p);
        second = to_num(p);
        jump_space(p);
        if (*p == '*' || *p == '/') {
            return T_sub(first * second, p);
        }
        if (*p == 0 || *p == '+' || *p == '-') {
            return first * second;
        }
        cerr << __LINE__ << ": invalid input: " << string(p) << "\n";
        break;
    case '/':
        ++p;
        jump_space(p);
        second = to_num(p);
        jump_space(p);
        if (*p == '*' || *p == '/') {
            return T_sub(first / second, p);
        }
        if (*p == 0 || *p == '+' || *p == '-') {
            return first / second;
        }
        cerr << __LINE__ << ": invalid input: " << string(p) << "\n";
        break;
    default:
        cerr << __LINE__ << ": invalid input: " << string(p) << "\n";
    }
    return 0;
}

int calculate(string s) {
    const char *p = s.c_str();
    return E(p);
}

int main(int argc, char *argv[]) {
    string e(argv[1]);
    cout << e << " = " << calculate(e) << endl;
}
