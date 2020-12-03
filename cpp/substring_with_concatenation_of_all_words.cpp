// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/05/21 20:42:43
// Description: https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "util.h"

using namespace std;

void show(const map<string, int> &m) {
    cout << "{";
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it != m.begin()) {
            cout << ", ";
        }
        cout << it->first << ":" << it->second;
    }
    cout << "}\n";
}

vector<int> fn(const string &p) {
    vector<int> f(p.size(), -1);
    for (int i = 1; i < p.size(); ++i) {
        int l = f[i-1];
        while (l > 0 && p[l+1] != p[i]) l = f[l];
        if (p[l+1] == p[i]) {
            f[i] = l+1;
        }
    }
    return f;
}

int find(const string &s, int start, const string &p) {
    vector<int> f = fn(p);
    int si = start;
    int pi = 0;
    while (si < s.size() && pi < p.size()) {
        if (s[si] == p[pi]) {
            ++si;
            ++pi;
        } else if (pi == 0) {
            ++si;
        } else {
            pi = f[pi-1]+1;
        }
    }
    if (pi == p.size()) {
        return si - p.size();
    }
    return -1;
}

vector<int> findAll(const string &s, const string &p) {
    vector<int> ret;
    string ss = s;
    int t = 0;
    while (t >= 0) {
        t = find(s, t, p);
        if (t >= 0) {
            ret.push_back(t);
            t = t+1;
        }
    }
    return ret;
}

bool equalMap(map<string, int> &m1, map<string, int> &m2) {
    for (auto it = m1.begin(); it != m1.end(); ++it) {
        auto it2 = m2.find(it->first);
        if (it2 == m2.end()) {
            return false;
        }
        if (it->second != it2->second) {
            return false;
        }
    }
    return true;
}

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> ret;
    if (words.empty()) {
        return ret;
    }
    int ws = words[0].size();
    int wsize = ws * words.size();
    if (wsize > s.size()) {
        return ret;
    }
    map<string, int> wc;
    for (size_t i = 0; i < words.size(); ++i) {
        auto it = wc.find(words[i]);
        if (it == wc.end()) {
            wc[words[i]] = 1;
        } else {
            ++it->second;
        }
    }
    show(wc);
    for (int i = 0; i < s.size() - wsize + 1; ++i) {
        map<string, int> m;
        for (int j = i; j < i+wsize; j+=ws) {
            string sub = s.substr(j, ws);
            auto it = m.find(sub);
            if (it == m.end()) {
                m[sub] = 1;
            } else {
                ++it->second;
            }
        }
        show(m);
        if (equalMap(wc, m)) {
            ret.push_back(i);
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    string s = "barfoothefoobarman";
    vector<string> words = {"foo","bar"};
    vector<int> r = findSubstring(s, words);
    cout << r << endl;
}
