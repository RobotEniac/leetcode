// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/04/15 16:31:50
// Description: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include "binary_tree.hpp"

#include "util.h"

using namespace std;

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "";
        }
        list<TreeNode*> s;
        s.push_back(root);
        stringstream ss;
        bool start = false;
        while (!s.empty()) {
            TreeNode *p = s.front();
            s.pop_front();
            if (p != NULL) {
                if (start) {
                    ss << ",";
                    start = true;
                }
                ss << p->val;
                start = true;
                s.push_back(p->left);
                s.push_back(p->right);
            } else {
                if (start) {
                    ss << ",";
                }
                ss << "null";
                start = true;
            }
        }
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return NULL;
        }
        vector<int> ary;
        int start = 0;
        int pos = 0;
        while ((pos = data.find(",", start)) != string::npos) {
            string sub = data.substr(start, pos - start);
            if (sub != "null") {
                ary.push_back(atoi(sub.c_str()));
            } else {
                ary.push_back(null);
            }
            start = pos + 1;
        }
        string last = data.substr(start);
        if (last != "null") {
            ary.push_back(atoi(last.c_str()));
        } else {
            ary.push_back(null);
        }
        TreeNode *root = new TreeNode(ary[0]);
        deque<TreeNode**> q;
        q.push_back(&root->left);
        q.push_back(&root->right);
        for (int i = 1; i < ary.size(); ++i) {
            TreeNode **p = q.front();
            q.pop_front();
            if (ary[i] != null) {
                *p = new TreeNode(ary[i]);
                q.push_back(&((*p)->left));
                q.push_back(&((*p)->right));
            }
        }
        return root;
    }
};

int main(int argc, char *argv[]) {
    vector<int> n = {1, 2, 3, null, 4, 5, null, null, null, 6};
    TreeNode *tree = MakeTree(n);
    Codec c;
    string ret = c.serialize(tree);
    cout << "after serialize: " << ret << "\n";
    TreeNode *res = c.deserialize(ret);
    cout << "after deserialize: " << c.serialize(res) << "\n";
}
