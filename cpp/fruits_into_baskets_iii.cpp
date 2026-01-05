// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/08/06 15:48:03
// Description: https://leetcode.cn/problems/fruits-into-baskets-iii/?envType=daily-question&envId=2025-08-06

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "util.h"

using namespace std;
struct Node
{
    int val;
    Node *left, *right;

    Node(): val(0), left(NULL), right(NULL) {}
};

void build(Node *root, vector<int>& a, int l, int r) {
    if (r == l+1) {
        root->val = a[l];
        return;
    }
    int m = (l + r) / 2;
    root->left = new Node;
    root->right = new Node;
    build(root->left, a, l, m);
    build(root->right, a, m, r);
    root->val = max(root->left->val, root->right->val);
    return;
}

int search(vector<int> tree, int n, int f, int cur) {
    if (cur >= n * 2 || tree[cur] < f) {
        return -1;
    }
    if (cur >= n && cur < n*2) {
        if (tree[cur] > f) {
            int ret = tree[cur];
            tree[n] = 0;
            return ret;
        } else {
            return -1;
        }
    }
    int ret = search(tree, n, f, cur * 2);
    if (ret > 0) {
        tree[cur] = max(tree[cur*2], tree[cur*2+1]);
    } else {
        ret = search(tree, n, f, cur * 2 + 1);
        if (ret > 0) {
            tree[cur] = max(tree[cur * 2], tree[cur * 2 + 1]);
        }
    }
    return ret;
}

int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
{
    int n = baskets.size();
    vector<int> tree(n * 2 + 2, 0);
    for (int i = n; i < n * 2; ++i) {
        tree[i] = baskets[i-n]; 
    }
    for (int i = n-1; i > 0; --i) {
        tree[i] = max(tree[i*2], tree[i*2+1]);
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int ret = search(tree, n, fruits[i], 1);
        if (ret < 0) {
            ++cnt;
        }
    }
    return cnt;
}

int main(int argc, char *argv[]) {
    vector<int> f = {2,3,4,5};
    vector<int> bas = {5,7,4,3};
    cout << numOfUnplacedFruits(f, bas);
}
