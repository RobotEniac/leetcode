// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/11/11 21:42:41
// Description: https://leetcode.com/problems/invert-binary-tree/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"
#include "binary_tree.hpp"

using namespace std;

TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) {
        return root;
    }
    if (root->left == NULL
            && root->right == NULL) {
        return root;
    }
    TreeNode *l = invertTree(root->left);
    TreeNode *r = invertTree(root->right);
    root->left = r;
    root->right = l;
    return root;
}

int main(int argc, char *argv[]) {
    cout << "hello world" << endl;
}
