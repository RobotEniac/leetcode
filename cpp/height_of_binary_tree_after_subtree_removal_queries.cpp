// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2024/11/21 10:27:13
// Description: https://leetcode.cn/problems/height-of-binary-tree-after-subtree-removal-queries/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "binary_tree.hpp"

#include "util.h"

using namespace std;

struct Node {
    int h;
    TreeNode *f;
};

void show(map<int, Node>& h) {
    for (auto it = h.begin(); it != h.end(); ++it) {
        if (it != h.begin()) {
            cout << ", ";
        }
        cout << it->first << ":" << it->second.h;
    }
    cout << endl;
}

int dfs(TreeNode* root, map<int, Node>& h, TreeNode *f) {
    if (root == NULL) {
        return -1;
    }
    Node n;
    n.h = max(dfs(root->left, h, root), dfs(root->right, h, root)) + 1;
    if (f != NULL) {
        n.f = f;
    }
    h[root->val] = n;
    return n.h;
}

vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
    vector<int> ret;
    map<int, Node> height;
    if (root == NULL) {
        return ret;
    }
    Node n;
    n.h = dfs(root, height, NULL);
    height[root->val] = n;
    show(height);
    for (int i = 0; i < queries.size(); ++i) {
        TreeNode *f = height[queries[i]].f;
        if (f->left != NULL && queries[i] == f->left->val) {
            int rh = f->right !=NULL ? height[f->right->val].h : 0;
            ret.push_back(rh+1);
        } else {
            int lh = f->left != NULL ? height[f->left->val].h : 0;
            ret.push_back(lh+1);
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<int> a = {5,8,9,2,1,3,7,4,6};
    TreeNode *t = MakeTree(a);
    PrintTree(t);
    vector<int> q = {3,2,4,8};
    auto ret = treeQueries(t, q);
    cout << ret << endl;
}
