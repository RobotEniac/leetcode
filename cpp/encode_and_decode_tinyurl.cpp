// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/04/09 17:27:35
// Description: https://leetcode-cn.com/problems/encode-and-decode-tinyurl/

#include <map>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

struct TreeNode {
    string val;
    int freq;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : left(NULL), right(NULL) {}
};

typedef map<char, vector<uint8_t>> HuffmanTable;

void show(vector<TreeNode*>& v) {
    for (int i = 0; i < v.size(); ++i) {
        if (i != 0) {
            cout << "\n";
        }
        cout << "(" << v[i]->val << ", " << v[i]->freq << ")";
    }
    cout << endl;
}

void print_table(const HuffmanTable& table) {
    for (auto it = table.begin(); it != table.end(); ++it) {
        printf("%-2c => ", it->first);
        for (int i = 0; i < it->second.size(); ++i) {
            cout << (int)it->second[i];
        }
        cout << "\n";
    }
}

void Space(int n) {
    for (int i = 0; i < n; ++i) {
        printf("    ");
    }
}

void PrintTreeNode(TreeNode *node, int height) {
    if (node == NULL) {
        return;
    }
    if (node->left) {
        PrintTreeNode(node->left, height + 1);
    }
    Space(height);
    if (node->val.empty()) {
        cout << "null\n";
    } else {
        cout << node->val << "\n";
    }
    if (node->right) {
        PrintTreeNode(node->right, height + 1);
    }
}

int find(vector<TreeNode>& v, int start, int len, TreeNode n) {
    int l = start;
    int r = len;
    while (l < r) {
        int m = (l + r) / 2;
        if (v[l].freq < v[m].freq) {
            r = m;
        } else {
            l = m+1;
        }
    }
    if (v[l].freq > n.freq) {
        while (l > start && v[l].freq == v[l-1].freq) {
            --l;
        }
        return l;
    }
    while (l < len-1 && v[l].freq == v[l+1].freq) {
        ++l;
    }
    return l;
}

void insert(vector<TreeNode*>& v, int start, int len, TreeNode n) {
    TreeNode *t(new TreeNode);
    *t = n;
    v.push_back(t);
    int i = len - 1;
    for (; i >= start; --i) {
        if (v[i]->freq > n.freq) {
            v[i+1] = v[i];
        } else {
            break;
        }
    }
    v[i+1] = t;
}

void traverse(TreeNode* root, vector<uint8_t>& path, HuffmanTable& table) {
    if (root->left == NULL && root->right == NULL) {
        table[root->val[0]] = path;
        return;
    }
    if (root->left != NULL) {
        path.push_back(0);
        traverse(root->left, path, table);
        path.pop_back();
    }
    if (root->right != NULL) {
        path.push_back(1);
        traverse(root->right, path, table);
        path.pop_back();
    }
}

void huffman_table(const std::string& s, HuffmanTable *table) {
    char c[256] = {0};
    int total = 0;
    for (int i = 0; i < s.size(); ++i) {
        c[(int)s[i]]++;
        ++total;
    }
    vector<TreeNode*> v;
    for (int i = 0; i < 256; ++i) {
        if (c[i] > 0) {
            TreeNode *n(new TreeNode);
            n->val = (char)i;
            n->freq = c[i];
            v.push_back(n);
        }
    }
    for (int len = 1; len < v.size(); ++len) {
        TreeNode *t = v[len];
        int j = len - 1;
        for (; j >= 0; --j) {
            if (v[j]->freq > t->freq) {
                v[j+1] = v[j];
            }
            else {
                break;
            }
        }
        v[j+1] = t;
    }

    TreeNode t;
    int ss = 0;
    do {
        t.left = v[ss];
        t.right = v[ss+1];
        ss += 2;
        t.freq = t.left->freq + t.right->freq;
        t.val = t.left->val + t.right->val;
        insert(v, ss, v.size(), t);
    } while (t.freq != total);
    vector<uint8_t> path;
    table->clear();
    traverse(v[v.size()-1], path, *table);
    for (int i = 0; i < v.size(); ++i) {
        delete v[i];
    }
}

string code_str(const vector<uint8_t> &c) {
    stringstream ss;
    for (int i = 0; i < c.size(); ++i) {
        ss << (int)c[i];
    }
    return ss.str();
}

// Encodes a URL to a shortened URL.
string encode(string longUrl, HuffmanTable &t) {
    huffman_table(longUrl, &t);
    print_table(t);
    vector<uint8_t> ret;
    for (int i = 0; i < longUrl.size(); ++i) {
        vector<uint8_t> code = t[longUrl[i]];
        for (int j = 0; j < code.size(); ++j) {
            ret.push_back(code[j]);
        }
    }
    cout << code_str(ret) << endl;
    return "";
}

// Decodes a shortened URL to its original URL.
string decode(string shortUrl, HuffmanTable &t) {
    return "";
}

int main(int argc, char *argv[]) {
    std::string s("https://leetcode.com/problems/design-tinyurl");
    HuffmanTable m;
    encode(s, m);
}
