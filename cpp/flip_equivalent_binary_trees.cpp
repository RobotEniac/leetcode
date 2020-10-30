// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/10/28 20:08:47
// Description: https://leetcode-cn.com/problems/flip-equivalent-binary-trees/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"
#include "binary_tree.hpp"

using namespace std;

bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    if (root1 == NULL || root2 == NULL) {
        return false;
    }
    if (root1->val != root2->val) {
        return false;
    }
    if (flipEquiv(root1->left, root2->left)
        && flipEquiv(root1->right, root2->right)) {
        return true;
    }
    return flipEquiv(root1->left, root2->right)
        && flipEquiv(root1->right, root2->left);
}


int main(int argc, char *argv[]) {
    vector<int> a1 = {1,2,3,4,5,6,null,null,null,7,8};
    vector<int> a2 = {1,3,2,null,6,4,5,null,null,null,null,8,7};
    TreeNode *root1 = MakeTree(a1);
    TreeNode *root2 = MakeTree(a2);
    cout << boolalpha << flipEquiv(root1, root2) << endl;
}
