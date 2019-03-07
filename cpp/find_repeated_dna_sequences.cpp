// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/03/01
// Description: https://leetcode.com/problems/repeated-dna-sequences/

#include <stdio.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "util.h"

using namespace std;

void cal(const std::string &s, vector<int>* f) {
    f->assign(s.size(), -1);
    vector<int> &foo = *f;
    for (int i = 1; i < s.size(); ++i) {
        int t = foo[i-1];
        while (t > 0 && s[t+1] != s[i]) {
            t = foo[t];
        }
        if (foo[t+1] == s[i]) {
            foo[i] = t+1;
        }
    }
}

int find(const std::string &s, const std::string &p) {
    if (p.size() > s.size()) {
        return -1;
    }
    if (p.size() == s.size()) {
        if (p == s) {
            return 0;
        }
        return -1;
    }
    vector<int> f;
    cal(s, &f);
    int si = 0, pi = 0;
    while (si < s.size() && pi < p.size()) {
        if (s[si] == p[pi]) {
            ++pi;
        } else if (pi > 0) {
            pi = f[pi] + 1;
        }
        ++si;
    }
    if (pi < p.size()) {
        return -1;
    }
    return si - pi;
}

vector<string> findRepeatedDnaSequences(string s) {
    vector<string> ret;
    if (s.size() < 10) {
        return ret;
    }
    map<string, int> dna_map;
    const int N = 10;
    cout << s.size() << endl;
    for (int i = 0; i < s.size() - N + 1; ++i) {
        string sub = s.substr(i, N);
        auto it = dna_map.find(sub);
        if (it != dna_map.end()) {
            if (it->second == 0) {
                ret.push_back(sub);
            }
            ++(it->second);
        } else {
            dna_map[sub] = 0;
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    string s(argv[1]);
    cout << "seq of " << s << " is " << findRepeatedDnaSequences(s) << endl;
}

