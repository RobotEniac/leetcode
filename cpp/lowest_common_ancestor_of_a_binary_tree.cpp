// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/11/13 22:25:21
// Description: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

#include <iostream>
#include <vector>
#include <string>
#include <list>

#include "util.h"
#include "binary_tree.hpp"

using namespace std;

void show(list<TreeNode*> &l) {
    cout << "[";
    for (auto it = l.begin(); it != l.end(); ++it) {
        if (it != l.begin()) {
            cout << ", ";
        }
        cout << (*it)->val;
    }
    cout << "]\n";
}

bool findNode(TreeNode *root, TreeNode *p, list<TreeNode*> *path) {
    if (root == NULL && p != NULL) {
        return false;
    }
    path->push_back(root);
    if (root == p) {
        return true;
    }
    if (findNode(root->left, p, path)) {
        return true;
    }
    if (findNode(root->right, p, path)) {
    }   return true;
    path->pop_back();
    return false;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    list<TreeNode*> plist;
    list<TreeNode*> qlist;
    if (findNode(root, p, &plist) && findNode(root, q, &qlist)) {
        show(plist);
        show(qlist);
        auto pit = plist.begin();
        auto qit = qlist.begin();
        while (pit != plist.end() && qit != qlist.end()) {
            if (*pit != *qit) {
                --pit;
                return *pit;
            }
            ++pit;
            ++qit;
        }
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    vector<int> nums = {3,5,1,6,2,0,8,null,null,7,4};
    TreeNode *root = MakeTree(nums);
    PrintTreeNode(root, 0);
    TreeNode *p = lowestCommonAncestor(root, root->left, root->right);
    if (p == NULL) {
        cout << "NULL" << endl;
        return 1;
    }
    cout << p->val << endl;
}
