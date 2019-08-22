// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/08/12 10:23:56
// Description: https://leetcode.com/problems/count-complete-tree-nodes/

#include <math.h>

#include <iostream>
#include <vector>
#include <string>

#include "util.h"
#include "binary_tree.hpp"

using namespace std;

int countNodes(TreeNode* root) {
    int lh = 0;
    int rh = 0;
    TreeNode *p = root;
    while (p != NULL) {
        lh++;
        p = p->left;
    }
    p = root;
    while (p != NULL) {
        rh++;
        p = p->right;
    }
    if (rh == lh) {
        return pow(2, rh) - 1; 
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main(int argc, char *argv[]) {
    cout << "hello world" << endl;
}
