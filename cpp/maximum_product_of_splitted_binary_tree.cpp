// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2026/01/07 14:33:19
// Description: https://leetcode.cn/problems/maximum-product-of-splitted-binary-tree/description/?envType=daily-question&envId=2026-01-07

#include <iostream>
#include <vector>
#include <string>

#include "util.h"
#include "binary_tree.hpp"
#include "file_util.hpp"

using namespace std;

TreeNode* dfs(TreeNode *root, int *sum) {
    if (root == NULL) {
        *sum = 0;
        return NULL;
    }
    TreeNode *p = new TreeNode;
    int l = 0;
    p->left = dfs(root->left, &l);
    int r = 0;
    p->right = dfs(root->right, &r);
    p->val = l + r + root->val;
    *sum = p->val;
    return p;
}

int64_t mul(int64_t x, int64_t y) {
    // cout << x << " x " << y << endl;
    return x * y;
}

void cal(TreeNode *root, int total, int64_t *mmax) {
    if (root == NULL) {
        return;
    }
    int64_t t = mul(root->val, total - root->val);
    if (t > *mmax) {
        *mmax = t;
    }
    cal(root->left, total, mmax);
    cal(root->right, total, mmax);
}

int maxProduct(TreeNode *root) {
    const static int a = 1e9 + 7;
    int total = 0;
    TreeNode *sum_tree = dfs(root, &total);
    int64_t ret = 0;
    cal(sum_tree, total, &ret);
    return ret % a;
}

int main(int argc, char *argv[]) {
    vector<int> v = lc::ReadArrayInt("in.txt");
    int sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] != null) {
            sum += v[i];
        }
    }
    cout << sum << endl;
    TreeNode *r = MakeTree(v);
    cout << maxProduct(r) << endl;
}
