// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/02/27
// Description: 

#include <stdio.h>

#include <iostream>
#include <deque>
#include <vector>

#define null 0x0f0f0f0f

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    ~TreeNode() {
        if (left != NULL) {
            delete left;
            left = NULL;
        }
        if (right != NULL) {
            delete right;
            right = NULL;
        }
    }
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
        return;
    }
    if (node->left) {
        PrintTreeNode(node->left, height + 1);
    }
    Space(height);
    printf("%d\n", node->val);
    if (node->right) {
        PrintTreeNode(node->right, height + 1);
    }
}

void BTree::Print() {
    PrintTreeNode(GetRoot(), 0);
}

TreeNode* MakeTree(vector<int> ary) {
    if (ary.size() == 0) {
        return NULL;
    }
    TreeNode *root = new TreeNode(ary[0]);
    deque<TreeNode**> q;
    q.push_back(&root->left);
    q.push_back(&root->right);
    for (int i = 1; i < ary.size(); ++i) {
        TreeNode **p = q.front();
        q.pop_front();
        if (ary[i] != null) {
            *p = new TreeNode(ary[i]);
            q.push_back(&((*p)->left));
            q.push_back(&((*p)->right));
        }
    }
    return root;
}

