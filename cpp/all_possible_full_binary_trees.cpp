// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2024/05/15 14:55:57
// Description: https://leetcode.cn/problems/all-possible-full-binary-trees/solutions/2713780/suo-you-ke-neng-de-zhen-er-cha-shu-by-le-1uku/?envType=daily-question&envId=2024-05-14

#include <iostream>
#include <vector>
#include <string>

#include "util.h"
#include "binary_tree.hpp"

using namespace std;

vector<TreeNode*> allPossibleFBT(int n) {
    vector<TreeNode*> ret;
    if ((n & 0x1) == 0) {
        return ret;
    }
    if (n == 1) {
        TreeNode n;
        n.val = 0;
        n.left = NULL;
        n.right = NULL;
        ret.push_back(n);
        return ret;
    }
    for (int i = 1; i < n; i += 2) {
        vector<TreeNode*> left = allPossibleFBT(i);
        vector<TreeNode*> right = allPossibleFBT(n-i-1);
        for (int l = 0; l < left.size(); ++l) {
            for (int r = 0; r < right.size(); ++r) {
                TreeNode n;
                n.val = 0;
                n.left = left[l];
                n.right = right[r];
                ret.push_back(n);
            }
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    cout << "hello world" << endl;
}
