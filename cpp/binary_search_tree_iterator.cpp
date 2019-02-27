// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/02/26
// Description: 

#include <stack>
#include <iostream>
#include <string>
#include <vector>

#include "binary_tree.hpp"
#include "util.h"

using namespace std;

class BSTIterator {
public:
    BSTIterator(TreeNode* root)
    {
        TreeNode *p = root;
        while (p) {
            s_.push(p);
            p = p->left;
        }
    }

    /** @return the next smallest number */
    int next() {
        if (s_.empty()) {
            return 0;
        }
        TreeNode *p = s_.top();
        int val = p->val;
        s_.pop();
        p = p->right;
        while (p) {
            s_.push(p);
            p = p->left;
        }
        return val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s_.empty();
    }

private:
    stack<TreeNode*> s_;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main(int argc, char *argv[]) {
int n = atoi(argv[1]);
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        a.push_back(rand() % 100);
    }
    cout << a << endl;
    BTree tree;
    for (int i = 0; i < a.size(); ++i) {
        tree.Insert(a[i]);
    }
    tree.Print();

    BSTIterator it(tree.GetRoot());
    while (it.hasNext()) {
        cout << it.next() << " ";
    }
    cout << endl;
}

