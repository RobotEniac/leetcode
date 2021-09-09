// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/07/12 17:14:03
// Description: https://leetcode-cn.com/problems/count-univalue-subtrees/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"
#include "binary_tree.hpp"

using namespace std;

int dfs(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    int l = 0;
    if (root->left && dfs
}

int countUnivalSubtrees(TreeNode* root) {
}

int main(int argc, char *argv[]) {
    cout << "hello world" << endl;
}
