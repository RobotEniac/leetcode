// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/06/09 20:29:24
// Description: https://leetcode-cn.com/problems/closest-binary-search-tree-value/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"
#include "binary_tree.hpp"

using namespace std;

void traverse(TreeNode* root, TreeNode *prep, double target, int *x, int *next) {
    if (root == NULL) {
        return;
    }
    if (target <= root->val) {
        if (root->left == NULL) {
            *x = root->val;
            if (prep != NULL) {
                *next = prep->val;
            }
            return;
        } else {
            traverse(root->left, root, target, x, next);
        }
    } else {
        if (root->right == NULL) {

        }
    }
}

int closestValue(TreeNode* root, double target) {

}

int main(int argc, char *argv[]) {
    cout << "hello world" << endl;
}
