// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/02/13 18:24:40
// Description: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"
#include "binary_tree.hpp"

using namespace std;

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL) {
        return NULL;
    }
    if (p == NULL && q == NULL) {
        return NULL;
    }
    if (p == NULL) {
        return q;
    }
    if (q == NULL) {
        return p;
    }

    if (p == q) {
        return p;
    }
    if (p == root) {
        return p;
    }
    if (q == root) {
        return q;
    }
    if (p->val < root->val && q->val > root->val 
            || p->val > root->val && q->val < root->val) {
        return root;
    }
    if (p->val < root->val && q->val < root->val) {
        return lowestCommonAncestor(root->left, p, q);
    }
    if (p->val > root->val && q->val > root->val) {
        return lowestCommonAncestor(root->right, p, q);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    cout << "hello world" << endl;
}
