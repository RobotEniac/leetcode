// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/04/13 11:03:03
// Description: https://leetcode-cn.com/problems/convert-bst-to-greater-tree/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"
#include "binary_tree.hpp"

using namespace std;

int traverse(TreeNode* root, int sum) {
    if (root == NULL) {
        return sum;
    }
    if (root->right != NULL) {
        sum = traverse(root->right, sum);
    }
    root->val = sum + root->val;
    sum = root->val;
    if (root->left != NULL) {
        return traverse(root->left, sum);
    }
    return sum;
}

TreeNode* convertBST(TreeNode* root) {
    traverse(root, 0);
    return root;
}

int main(int argc, char *argv[]) {
    vector<int> v = {4,1,6,0,2,5,7,null,null,null,3,null,null,null,8};
    TreeNode *root = MakeTree(v);
    PrintTreeNode(root, 0);
    convertBST(root);
    cout << "==================================================\n";
    PrintTreeNode(root, 0);
}
