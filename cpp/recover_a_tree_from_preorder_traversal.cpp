// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/04/21 16:04:38
// Description: https://leetcode-cn.com/problems/recover-a-tree-from-preorder-traversal/

#include <iostream>
#include <vector>
#include <string>
#include <stack>

#include "util.h"
#include "binary_tree.hpp"

using namespace std;

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

int digit(char c) {
    return c - '0';
}

TreeNode* recoverFromPreorder(string s) {
    struct Node {
        TreeNode *p;
        int h;
    };
    stack<Node> st;
    int i = 0;
    TreeNode *root = NULL;
    while (i < s.size()) {
        int h = 0;
        while (i < s.size() && s[i] == '-') {
            ++i;
            ++h;
        }
        int num = 0;
        while (i < s.size() && is_digit(s[i])) {
            num = num * 10 + digit(s[i]);
            ++i;
        }
        Node n;
        n.p = new TreeNode(num);
        n.h = h;
        while (!st.empty() && st.top().h >= n.h) {
            st.pop();
        }
        if (st.empty()) {
            root = n.p;
            st.push(n);
            continue;
        }
        TreeNode *t = st.top().p;
        if (t->left == NULL) {
            t->left = n.p;
        } else if (t->right == NULL) {
            t->right = n.p;
        }
        st.push(n);
    }
    return root;
}

int main(int argc, char *argv[]) {
    string s("1-401--349---90--88");
    TreeNode *r = recoverFromPreorder(s);
    PrintTree(r);
}
