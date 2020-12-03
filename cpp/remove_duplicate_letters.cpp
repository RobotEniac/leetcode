// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/05/10 23:59:25
// Description: https://leetcode.com/problems/remove-duplicate-letters/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

void show(vector<vector<int> >& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        char c = i + 'a';
        cout << c << ": ";
        cout << v[i] << "\n";
    }
}

string removeDuplicateLetters(string s) {
    int letter_size = 'z' - 'a' + 1;
    vector<int> m(letter_size, 0);
    vector<int> visited(letter_size, 0);
    string res = "0";
    for (size_t i = 0; i < s.size(); ++i) {
        ++m[s[i]-'a'];
    }
    for (size_t i = 0; i < s.size(); ++i) {
        int k = s[i] - 'a';
        --m[k];
        if (visited[k]) 
            continue;
        while (s[i] < res.back() && m[res.back() - 'a'] > 0) {
            visited[res.back() - 'a'] = 0;
            res.pop_back();
        }
        res.push_back(s[i]);
        visited[k] = 1;
    }
    return res.substr(1);
}

int main(int argc, char *argv[]) {
    string s(argv[1]);
    cout << removeDuplicateLetters(s) << endl;
}
