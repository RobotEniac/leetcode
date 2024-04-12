// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2024/02/26 15:55:42
// Description: https://leetcode.cn/problems/range-sum-of-bst/?envType=daily-question&envId=2024-02-26

#include <iostream>
#include <vector>
#include <string>

#include "util.h"
#include "binary_tree.hpp"

using namespace std;

int rangeSumBST(TreeNode* root, int low, int high) {
    if (root == NULL) {
        return 0;
    }
    if (root->val < low) {
        return rangeSumBST(root->right, low, high);
    }
    if (root->val > high) {
        return rangeSumBST(root->left, low, high);
    }
    int l = rangeSumBST(root->left, low, high);
    int r = rangeSumBST(root->right, low, high);
    return l + r + root->val;
}

int main(int argc, char *argv[]) {
    cout << "hello world" << endl;
}
