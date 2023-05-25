// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/05/10 14:35:13
// Description: https://leetcode.cn/problems/even-odd-tree/

#include <iostream>
#include <vector>
#include <string>
#include <deque>

#include "util.h"
#include "binary_tree.hpp"

using namespace std;

bool isEvenOddTree(TreeNode* root) {
    struct Step {
        TreeNode* node;
        int h;
    };
    deque<Step> d;
    Step s;
    s.node = root;
    s.h = 0;
    d.push_back(s);
    while (!d.empty()) {
        Step last;
        last.node = NULL;
        last.h = d.front().h;
        while (d.front().h == last.h) {
            Step tmp = d.front();
            d.pop_front();
            if (tmp.h % 2 ==  tmp.node->val % 2) {
                return false;
            }
            if (last.node != NULL) {
                if (tmp.h % 2 == 0 && last.node->val >= tmp.node->val) {
                    return false;
                }
                if (tmp.h %2 == 1 && last.node->val <= tmp.node->val) {
                    return false;
                }
            }
            last = tmp;
            if (tmp.node->left != NULL) {
                Step l;
                l.node = tmp.node->left;
                l.h = tmp.h + 1;
                d.push_back(l);
            }
            if (tmp.node->right != NULL) {
                Step r;
                r.node = tmp.node->right;
                r.h = tmp.h + 1;
                d.push_back(r);
            }
        }
    }
    return true;;
}

int main(int argc, char *argv[]) {
    vector<int> a = {5,4,2,3,3,7};
    TreeNode *root = MakeTree(a);
    PrintTree(root);
    cout << boolalpha << isEvenOddTree(root) << endl;
}
