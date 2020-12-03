// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/10/22 21:05:38
// Description: https://leetcode.com/problems/partition-labels/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

vector<int> partitionLabels(string S) {
    vector<int> b(26, -1);
    for (int i = 0; i < S.size(); ++i) {
        int c = S[i] - 'a';
        if (i > b[c]) {
            b[c] = i;
        }
    }
    vector<int> ret;
    int start = 0;
    int end = -1;
    for (int i = 0; i < S.size(); ++i) {
        int c = S[i] - 'a';
        if (b[c] > end) {
            end = b[c];
        }
        if (end == i) {
            ret.push_back(i+1 - start);
            start = i+1;
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    string s(argv[1]);
    int start = 0;
    auto v = partitionLabels(s);
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << ": " << s.substr(start, v[i]) << "\n";
        start += v[i];
    }
}
