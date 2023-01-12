// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2022/10/24 16:42:33
// Description: https://leetcode.cn/problems/word-subsets/

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "util.h"

using namespace std;

bool subset(string& s1, string& s2) {
    vector<int> m1(256, 0);
    vector<int> m2(256, 0);
    for (int i = 0; i < s2.size(); ++i) {
        m2[(int)s2[i]]++;
    }
    for (int i = 0; i < s1.size(); ++i) {
        m1[(int)s1[i]]++;
    }
    for (int i = 0; i < 256; ++i) {
        if (m2[i] != 0) {
            if (m1[i] < m2[i]) {
                return false;
            }
        }
    }
    return true;
}

vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    vector<string> ret;
    for (int j = 0; j < words1.size(); ++j) {
        bool ok = true;
        for (int i = 0; i < words2.size(); ++i) {
            if (!subset(words1[j], words2[i])) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ret.push_back(words1[j]);
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<string> words1 = {"amazon","apple","facebook","google","leetcode"}, words2 = {"lo","eo"};
    cout << wordSubsets(words1, words2) << endl;
}
