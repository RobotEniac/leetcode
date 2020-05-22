// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/05/11 16:47:38
// Description: https://leetcode.com/problems/maximum-product-of-word-lengths/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

bool check(const std::string &s1, const std::string &s2) {
    char letter[26];
    memset(letter, 0, sizeof(letter));
    for (int i = 0; i < s1.size(); ++i) {
        ++letter[s1[i] - 'a'];
    }
    for (int i = 0; i < s2.size(); ++i) {
        if (letter[s2[i] - 'a'] != 0) {
            return false;
        }
    }
    return true;
}

int maxProduct(vector<string>& words) {
    int max_product = 0;
    for (int i = 0; i < words.size(); ++i) {
        for (int j = i+1; j < words.size(); ++j) {
            if (check(words[i], words[j])) {
                int tmp = words[i].size() * words[j].size();
                if (tmp > max_product) {
                    max_product = tmp;
                }
            }
        }
    }
    return max_product;
}

int main(int argc, char *argv[]) {
    vector<string> vec = {"abcw","baz","foo","bar","xtfn","abcdef"};
    cout << maxProduct(vec) << endl;
    vector<string> v2 = {"a","ab","abc","d","cd","bcd","abcd"};
    cout << maxProduct(v2) << endl;
}
