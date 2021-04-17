// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/04/12 11:30:14
// Description: https://leetcode-cn.com/problems/complex-number-multiplication/

#include <sstream>
#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

inline bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

struct ComplexNumber {
    int real;
    int img;

    ComplexNumber() : real(0), img(0) {}

    string ToString() {
        if (real == 0 && img == 0) {
            return "0";
        }
        stringstream ss;
        if (real == 0) {
            ss << img << "i";
            return ss.str();
        }
        if (img == 0) {
            ss << real;
            return ss.str();
        }
        ss << real << "+" << img << "i";
        return ss.str();
    }
};

ComplexNumber Parse(const string& s) {
    int i = 0;
    ComplexNumber ret;
    while (i < s.size() && (s[i] == ' ' || s[i] == '\t')) ++i;
    if (i == s.size()) {
        return ret;
    }
    int num = 0;
    int sign = 1;
    if (s[i] == '-') {
        sign = -1;
        ++i;
    } else if (s[i] == '+') {
        ++i;
    }
    while (is_digit(s[i])) {
        num = num*10+(s[i] - '0');
        ++i;
    }
    while (i < s.size() && (s[i] == ' ' || s[i] == '\t')) ++i;
    if (i == s.size()) {
        ret.real = sign * num;
        return ret;
    }
    if (s[i] == 'i') {
        ret.img = sign * num;
        return ret;
    }
    ret.real = sign * num;
    if (s[i] == '+') {
        ++i;
        ret.img = 1;
    } else if (s[i] == '-') {
        ++i;
        ret.img = -1;
    }
    while (i < s.size() && (s[i] == ' ' || s[i] == '\t')) ++i;
    if (i == s.size()) {
        return ret;
    }

    num = 0;
    sign = 1;
    if (s[i] == '-') {
        sign = -1;
        ++i;
    } else if (s[i] == '+') {
        ++i;
    }
    while (is_digit(s[i])) {
        num = num*10+(s[i] - '0');
        ++i;
    }
    ret.img = ret.img * sign * num;
    while (i < s.size() && (s[i] == ' ' || s[i] == '\t')) ++i;
    if (i >= s.size() || s[i] != 'i') {
        ret.real = 0;
        ret.img = 0;
        return ret;
    }
    return ret;
}

string complexNumberMultiply(string a, string b) {
    ComplexNumber i1 = Parse(a);
    ComplexNumber i2 = Parse(b);
    cout << i1.ToString() << " * " << i2.ToString() << " = ";
    ComplexNumber res;
    res.real = i1.real * i2.real - i1.img * i2.img;
    res.img = i1.real * i2.img + i1.img * i2.real;
    return res.ToString();
}

int main(int argc, char *argv[]) {
    cout << complexNumberMultiply("1+2i", "3i") << endl;
}
