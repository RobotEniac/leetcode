// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/02/19 00:13:16
// Description: https://leetcode.com/problems/integer-to-english-words/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

#include "util.h"

using namespace std;

map<int, string> init() {
    map<int, string> m;
    m[0] = "";
    m[1] = "one";
    m[2] = "two";
    m[3] = "three";
    m[4] = "four";
    m[5] = "five";
    m[6] = "six";
    m[7] = "seven";
    m[8] = "eight";
    m[9] = "nine";
    m[10] = "ten";
    m[11] = "eleven";
    m[12] = "twelve";
    m[13] = "thirteen";
    m[14] = "fourteen";
    m[15] = "fifteen";
    m[16] = "sixteen";
    m[17] = "sevelteen";
    m[18] = "eighteen";
    m[19] = "nineteen";
    m[20] = "twenty";
    m[30] = "thirty";
    m[40] = "forty";
    m[50] = "fifty";
    m[60] = "sixty";
    m[70] = "seventy";
    m[80] = "eighty";
    m[90] = "ninety";
    m[100] = "hundred";
    m[1000] = "thousand";
    m[1000000] = "million";
    m[1000000000] = "billion";
    return m;
}

string lessThenThound(int num, map<int, string> &m) {
    if (num <= 20) {
        return m[num];
    }
    stringstream ss;
    int ten_one = num % 100;
    int one = num % 10;
    int ten = ((num / 10) % 10) * 10;
    int hundred = num / 100;
    if (ten_one == 0) {
        if (hundred != 0) {
            ss << m[hundred] << " hundred";
        } 
    } else {
        if (one == 0) {
            if (hundred == 0) {
                ss << m[ten_one];
            } else {
                ss << m[hundred] << " hundred " << m[ten_one];
            }
        } else {
            if (ten == 0) {
                if (hundred == 0) {
                    ss << m[one];
                } else {
                    ss << m[hundred] << " hundred " << m[one];
                }
            } else {
                if (hundred == 0) {
                    ss << m[ten] << " " << m[one];
                } else {
                    ss << m[hundred] << " hundred " << m[ten] << " " << m[one];
                }
            }
        }
    }
    return ss.str();
}


string numberToWords(int num) {
    map<int, string> m = init();
    string s = lessThenThound(num, m);
    return s;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    cout << n << ": " << numberToWords(n) << endl;
}
