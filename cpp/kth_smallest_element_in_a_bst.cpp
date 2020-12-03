// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/11/13 15:02:19
// Description: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

#include <iostream>
#include <vector>
#include <string>

#include "binary_tree.hpp"
#include "util.h"

using namespace std;

int count(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    return count(root->left) + count(root->right) + 1;
}

int kthSmallest(TreeNode* root, int k) {
    if (root == NULL) {
        return 0;
    }
    PrintTreeNode(root, 0);
    cout << "========\n";
    int left = count(root->left);
    if (left == k - 1) {
        return root->val;
    }
    if (left >= k) {
        return kthSmallest(root->left, k);
    }
    return kthSmallest(root->right, k - left - 1);
}

int main(int argc, char *argv[]) {
    vector<int> nums = {3,1};
    TreeNode *t = MakeTree(nums);
    cout << kthSmallest(t, 1) << endl;
}
