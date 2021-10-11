// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/09/09 21:03:42
// Description: https://leetcode-cn.com/problems/remove-invalid-parentheses/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <set>

#include "util.h"

using namespace std;

set<string> rm(string s) {
    cout << s << endl;
    set<string> ret;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ')') {
            string t = s.substr(0, i) + s.substr(i+1);
            ret.insert(t);
        }
    }
    cout << ret << endl;
    return ret;
}

vector<string> removeInvalidParentheses(string s) {
    vector<int> remove;
    stack<int> st;
    vector<string> ret;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
            if (st.empty()) {
                remove.push_back(i);
            } else {
                st.pop();
            }
        }
    }
    while (!st.empty()) {
        remove.push_back(st.top());
        st.pop();
    }
    set<string> ret_set;
    vector<set<string> > vss;
    int start = 0;
    for (int i = 0; i < remove.size(); ++i) {
        set<string> ss = rm(s.substr(start, remove[i] - start + 1));
        vss.push_back(ss);
        start = i+1;
    }
    if (start < s.size()) {
        set<string> ts;
        ts.insert(s.substr(start));
        vss.push_back(ts);
    }
    for (int i = 0; i < vss.size(); ++i) {
        string t;
        for (auto it = vss.start
    }
    return ret;
}

int main(int argc, char *argv[]) {
    string s(argv[1]);
    cout << removeInvalidParentheses(s) << endl;
}
