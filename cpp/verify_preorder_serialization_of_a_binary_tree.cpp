// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2024/04/10 20:30:08
// Description: https://leetcode.cn/problems/verify-preorder-serialization-of-a-binary-tree/?envType=daily-question&envId=2024-04-10

#include "unistd.h"

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

struct TreeNode {
    string v;
    TreeNode *l;
    TreeNode *r;
};

void Split(const string& s, vector<string> &v) {
    size_t pos = 0;
    while (pos < s.size()) {
        size_t e = s.find(",", pos);
        if (e == string::npos) {
            v.push_back(s.substr(pos));
            break;
        }
        v.push_back(s.substr(pos, e-pos));
        pos = e + 1;
    }
}

void show(TreeNode *root) {
    if (root == NULL) {
        cout << "#,";
        return;
    }
    cout << root->v << ",";
    show(root->l);
    show(root->r);
}

TreeNode *make(const string& s, int &cur) {
    if (cur >= s.size()) {
        return NULL;
    }
    size_t e = s.find(",", cur);
    string a;
    if (e == string::npos) {
        a = s.substr(cur);
        cur = s.size();
    } else {
        a = s.substr(cur, e-cur);
        cur = e+1;
    }
    if (a == "#") {
        return NULL;
    }
    TreeNode *ret = new TreeNode;
    ret->v = a;
    ret->l = NULL;
    ret->r = NULL;
    ret->l = make(s, cur);
    ret->r = make(s, cur);
    return ret;
}

bool isValidSerialization(string preorder) {
    int cur = 0;
    TreeNode *root = make(preorder, cur);
    show(root);
    cout << endl;
    return true;
}

int main(int argc, char *argv[]) {
    // std::string s = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    std::string s = "1,#";
    cout << boolalpha << isValidSerialization(s) << endl;
}
