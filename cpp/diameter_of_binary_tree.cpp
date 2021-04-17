// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/04/16 14:54:33
// Description: https://leetcode-cn.com/problems/diameter-of-binary-tree/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"
#include "binary_tree.hpp"

using namespace std;

void traverse(TreeNode* root, int &height, int &dia) {
    if (root == NULL) {
        height = 0;
        dia = 0;
        return;
    }
    traverse(root->left, height, dia);
    int lh = height;
    traverse(root->right, height, dia);
    int rh = height;
    height = max(lh, rh) +1;
    dia = max(dia, lh + rh + 1);
    cout << root->val << ": " << height << ", " << dia << endl;
    return;
}

int diameterOfBinaryTree(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int height = 0;
    int dia = 0;
    traverse(root, height, dia);
    return dia - 1;
}

int main(int argc, char *argv[]) {
    vector<int> v = {4,-7,-3,null,null,-9,-3,9,-7,-4,null,6,null,-6,-6,null,null,0,6,5,null,9,null,null,-1,-4,null,null,null,-2};
    TreeNode *root = MakeTree(v);
    PrintTree(root);
    cout << diameterOfBinaryTree(root) << endl;
}
