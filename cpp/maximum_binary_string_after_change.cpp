// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2024/04/10 16:52:36
// Description: https://leetcode.cn/problems/maximum-binary-string-after-change/description/?envType=daily-question&envId=2024-04-10

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

// 00 => 10
// 10 => 01

string maximumBinaryString(string binary) {
    if (binary.size() < 2) {
        return binary;
    }
    for (int i = 0; i < binary.size(); ++i) {
        if (binary[i] == '1') {
            continue;
        }
        if (binary[i] == '0') {
            if (i+1 < binary.size() && binary[i+1] == '0') {
                binary[i] = '1';
                binary[i+1] = '0';
            } else {
                int j = i+1;
                while (j < binary.size() && binary[j] == '1') {
                    ++j;
                }
                if (j < binary.size()) {
                    binary[i] = '1';
                    binary[i+1] = '0';
                    binary[j] = '1';
                }
            }
        }
    }
    return binary;
}

string func(string b) {
    if (b.size() < 2) {
        return b;
    }
    int c0 = 0;
    for (int i = 0; i < b.size(); ++i) {
        if (b[i] == '0') {
            ++c0;
        }
    }
    if (c0 == b.size()) {
        b = string(b.size(), '1');
        b[b.size()-1] = '0';
        return b;
    }
    int f0 = 0;
    for (int i = 0; i < b.size(); ++i) {
        if (b[i] == '0') {
            f0 = i;
            break;
        }
    }
    for (int i = 0; i < b.size(); ++i) {
        if (i == f0 + c0 - 1) {
            b[i] = '0';
        } else {
            b[i] = '1';
        }
    }
    return b;
}

int main(int argc, char *argv[]) {
    string s = "1111111";
    cout << s << endl;
    cout << maximumBinaryString(s) << endl;
    cout << func(s) << endl;
}
