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
            cout << "->";
        }
        cout << (*it)->val;
    }
    cout << "]\n";
}

TreeNode* findNodeVal(TreeNode *root, int val, list<TreeNode*> *path) {
    if (root == NULL) {
        return NULL;
    }
    path->push_back(root);
    if (root->val == val) {
        return root;
    }
    TreeNode* p = findNodeVal(root->left, val, path);
    if (p) {
        return p;
    }
    p = findNodeVal(root->right, val, path);
    if (p) {
        return p;
    }
    path->pop_back();
    return NULL;
}

bool findNode(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode *&res) {
    if (root == NULL) {
        return false;
    }
    int left = 0;
    int right = 0;
    int mid = 0;
    if (p == root || q == root) {
        mid = 1;
    }
    if (findNode(root->left, p, q, res)) {
        left = 1;
    }
    if (findNode(root->right, p, q, res)) {
        right = 1;
    }
    if (left + right + mid >= 2) {
        res = root;
        return true;
    }
    return left + right + mid > 0;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode *res = NULL;
    findNode(root, p, q, res);
    return res;
}

int main(int argc, char *argv[]) {
    vector<int> nums = {3,5,1,6,2,0,8,null,null,7,4};
    TreeNode *root = MakeTree(nums);
    PrintTreeNode(root, 0);
    list<TreeNode*> path;
    TreeNode *p1 = findNodeVal(root, 5, &path);
    show(path);
    path.clear();
    TreeNode* p2 = findNodeVal(root, 4, &path);
    show(path);

    TreeNode *res = lowestCommonAncestor(root, p1, p2);
    if (res == NULL) {
        cout << "NULL" << endl;
        return 1;
    }
    cout << res->val << endl;
}
