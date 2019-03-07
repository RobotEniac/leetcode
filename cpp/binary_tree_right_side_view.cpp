// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/03/06 16:20:18
// Description: https://leetcode.com/problems/binary-tree-right-side-view/

#include <iostream>
#include <vector>
#include <string>
#include <list>

#include "util.h"
#include "binary_tree.hpp"

using namespace std;

vector<int> rightSideView(TreeNode* root) {
    vector<int> ret;
    if (root == NULL) {
        return ret;
    }
    struct Node {
        TreeNode *p;
        int height;
    };
    list<Node> queue;
    Node n;
    n.p = root;
    n.height = 0;
    queue.push_back(n);
    int curr = 0;
    ret.push_back(root->val);
    while (!queue.empty()) {
        Node r = queue.front();
        queue.pop_front();
        if (r.height > curr) {
            ret.push_back(r.p->val);
            ++curr;
        }
        if (r.p->right) {
            Node rn;
            rn.p = r.p->right;
            rn.height = r.height + 1;
            queue.push_back(rn);
        }
        if (r.p->left) {
            Node ln;
            ln.p = r.p->left;
            ln.height = r.height + 1;
            queue.push_back(ln);
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    cout << "hello world" << endl;
}
