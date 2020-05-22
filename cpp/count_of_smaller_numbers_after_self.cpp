// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/05/09 18:53:47
// Description: https://leetcode.com/problems/count-of-smaller-numbers-after-self/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

vector<int> countSmaller(vector<int>& nums) {
    vector<int> ret(nums.size(), 0);
    for (int i = 0; i < nums.size(); ++i) {
        int cnt = 0;
        for (int j = i+1; j < nums.size(); ++j) {
            if (nums[j] < nums[i]) {
                ++cnt;
            }
        }
        ret[i] = cnt;
    }
    return ret;
}

struct Node {
    int val;
    int height;
    int size;
    Node *left;
    Node *right;

    Node(): val(0), height(0), size(0), left(NULL), right(NULL) {};
    Node(int x): val(x), height(0), size(0), left(NULL), right(NULL) {};
};

int size(Node* p) {
    if (p == NULL) {
        return 0;
    }
    return p->size;
}

int height(Node *p) {
    if (p == NULL) {
        return 0;
    }
    return p->height;
}

Node *Insert(Node *root, int v, int *count) {
    if (root == NULL) {
        Node *n = new Node(v);
        n->size = 1;
        n->height = 1;
        return n;
    }
    if (v <= root->val) {
        root->left = Insert(root->left, v, count);
    } else {
        root->right = Insert(root->right, v, count);
        *count = *count + size(root->left) + 1;
    }
    root->size = size(root->left) + size(root->right) + 1;
    root->height = max(height(root->left), height(root->right)) + 1;
    return root;
}

vector<int> countSmaller2(vector<int>& nums) {
    vector<int> ret(nums.size(), 0);
    Node *root = NULL;
    for (int i = nums.size() - 1; i >= 0; --i) {
        root = Insert(root, nums[i], &ret[i]);
    }
    return ret;
}


int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int r = rand() % 10;
        v.push_back(r);
    }
    cout << v << "\n";
    cout << countSmaller(v) << "\n";
    cout << countSmaller2(v) << "\n";
}
