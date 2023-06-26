// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/05/29 11:49:16
// Description: https://leetcode.cn/problems/reverse-odd-levels-of-binary-tree/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"
#include "binary_tree.hpp"

using namespace std;

void show(vector<TreeNode*> &v) {
    for (int i = 0; i < v.size(); ++i) {
        if (i != 0) {
            cout << ", ";
        }
        cout << v[i]->val;
    }
    cout << endl;
}

TreeNode* reverseOddLevels(TreeNode* root) {
    vector<TreeNode*> q;
    q.push_back(root);
    int i = 0;
    while (i < q.size()) {
        if (q[i]->left) {
            q.push_back(q[i]->left);
        }
        if (q[i]->right) {
            q.push_back(q[i]->right);
        }
        ++i;
        show(q);
    }
    int l = 0;
    int r = 0;
    int h = 0;
    while (r <= q.size()) {
        if ((h & 1) != 0) {
            int i = l;
            int j = r < q.size() ? r : (q.size() - 1);
            while (i < j) {
                int t = q[i]->val;
                q[i]->val = q[j]->val;
                q[j]->val = t;
                ++i;--j;
            }
        }
        l = l * 2 + 1;
        r = r * 2 + 2;
        ++h;
    }
    return root;
}

int main(int argc, char *argv[]) {
    vector<int> a = {0,1,2,0,0,0,0,1,1,1,1,2,2,2,2};
    TreeNode *t = MakeTree(a);
    PrintTree(t);
    PrintTree(reverseOddLevels(t));
}
