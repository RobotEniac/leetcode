// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/02/27
// Description: 

#include <stdio.h>

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BTree {
public:
    BTree() : root(NULL) {}

    TreeNode *GetRoot() {
        return root;
    }

    void Insert(int val);

    void Print();

private:
    TreeNode *root;
};


void BTree::Insert(int val) {
    if (root == NULL) {
        root = new TreeNode(val);
        return;
    }
    TreeNode *p = root;
    while (true) {
        if (val < p->val) {
            if (p->left == NULL) {
                p->left = new TreeNode(val);
                break;
            } else {
                p = p->left;
            }
        } else {
            if (p->right == NULL) {
                p->right = new TreeNode(val);
                break;
            } else {
                p = p->right;
            }
        }
    }
}

void Space(int n) {
    for (int i = 0; i < n; ++i) {
        printf("    ");
    }
}

void PrintTreeNode(TreeNode *node, int height) {
    if (node == NULL) {
        Space(height);
        printf("(null)\n");
        return;
    }
    Space(height);
    printf("%d\n", node->val);
    if (node->left == NULL && node->right == NULL) {
        return;
    }
    PrintTreeNode(node->left, height + 1);
    PrintTreeNode(node->right, height + 1);
}

void BTree::Print() {
    PrintTreeNode(GetRoot(), 0);
}

