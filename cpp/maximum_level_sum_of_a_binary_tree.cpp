// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2026/01/06 10:16:18
// Description: https://leetcode.cn/problems/maximum-level-sum-of-a-binary-tree/description/?envType=daily-question&envId=2026-01-06

#include <iostream>
#include <vector>
#include <string>

#include "util.h"
#include "binary_tree.hpp"

using namespace std;

int maxLevelSum(TreeNode *root) {
    queue<TreeNode*> q;
    q.push(NULL);
    q.push(root);
    vector<int> level_sum;
    while (!q.empty()) {
        TreeNode *p = q.front();
        if (p != NULL) {
            q.pop();
            level_sum[level_sum.size()-1] += p->val;
            if (p->left) {
                q.push(p->left);
            }
            if (p->right) {
                q.push(p->right);
            }
        } else {
            q.pop();
            if (!q.empty() && q.front() != NULL) {
                level_sum.push_back(0);
                q.push(NULL);
            }
        }
    }
    cout << level_sum << endl;
    int ret = 0;
    for (int i = 1; i < level_sum.size(); ++i) {
        if (level_sum[i] > level_sum[ret]) {
            ret = i;
        }
    }
    return ret+1;
}

int main(int argc, char *argv[]) {
    vector<int> v = {1,7,0,7,-8,null,null};
    TreeNode *r = MakeTree(v);
    PrintTree(r);
    cout << maxLevelSum(r) << endl;
}
