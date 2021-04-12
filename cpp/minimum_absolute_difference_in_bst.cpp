// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/04/09 15:42:13
// Description: https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"
#include "binary_tree.hpp"

using namespace std;

int mid_traverse_min(TreeNode *root, int& prev, int mmin) {
    if (root->left) {
        mmin = mid_traverse_min(root->left, prev, mmin);
    }
    if (prev > 0 && root->val - prev < mmin) {
        mmin = root->val - prev;
    }
    prev = root->val;
    if (root->right) {
        mmin = mid_traverse_min(root->right, prev, mmin);
    }
    return mmin;
}

int getMinimumDifference(TreeNode* root) {
    int prev = -1;
    return mid_traverse_min(root, prev, INT_MAX);
}

int main(int argc, char *argv[]) {
    vector<int> a = {0,null,2236,1277,2776,519};
    TreeNode *r = MakeTree(a);
    cout << getMinimumDifference(r) << endl;
}
