// =====================================================
//       Filename:  kmp.cpp
//         Author:  wuhaibo <gethaibo@gmail.com>
//        Created:  2017/02/19
//    Description:  
//    Copyright (c) 2017, NONE, All rights reserved. 
// =====================================================

#include <vector>
#include <string>
#include <iostream>

#include "util.h"

using namespace std;

void cal(const string& p, vector<int>* f) {
    f->assign(p.size(), -1);
    vector<int>& fun = *f;
    for (size_t i = 1; i < p.size(); ++i) {
        int t = fun[i-1];
        while (t > 0 && p[i] != p[t+1]) t = fun[t];
        if (p[i] == p[t+1]) fun[i] = t + 1;
        else fun[t] = -1;
    }
}

int kmp(const string& s, const string& p) {
    if (s.empty())
        return -1;
    if (p.empty())
        return 0;
    if (s.size() < p.size()) {
        return -1;
    }

    vector<int> f;
    cal(p, &f);
    int si = 0;
    int pi = 0;
    while (si < s.size() && pi < p.size()) {
        if (s[si] == p[pi]) {
            ++si;
            ++pi;
        } else {
            if (pi > 0) {
                pi = f[pi-1] + 1;
            } else {
                ++si;
            }
        }
    }
    if (pi < p.size()) {
        return -1;
    }
    return si - pi;
}

int main(int argc, char* argv[]) {
    string s = argv[1];
    string p = argv[2];
    cout << s << "\n";
    cout << p << "\n";
    cout << kmp(s, p) << endl;
}

