// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/03/11 14:38:35
// Description: https://leetcode.com/problems/implement-trie-prefix-tree/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

#define MAX_SIZE 26

struct TrieNode {
    bool is_leaf;
    TrieNode* child[MAX_SIZE];

    TrieNode() : is_leaf(false) {
        for (int i = 0; i < MAX_SIZE; ++i) {
            child[i] = NULL;
        }
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie()
        : root(new TrieNode)
    {
    }

    ~Trie() {
        if (root == NULL) {
            return;
        }
        for (int i = 0; i < MAX_SIZE; ++i) {
            delete root->child[i];
            root->child[i] = NULL;
        }
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        if (word.empty()) {
            return;
        }
        TrieNode *p = root;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (p->child[index] == NULL) {
                p->child[index] = new TrieNode;
            }
            p = p->child[index];
        }
        p->is_leaf = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (word.empty()) {
            return true;
        }
        TrieNode *p = root;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (p->child[index]) {
                p = p->child[index];
            } else {
                return false;
            }
        }
        return p->is_leaf;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if (prefix.empty()) {
            return true;
        }
        TrieNode *p = root;
        for (int i = 0; i < prefix.size(); ++i) {
            int index = prefix[i] - 'a';
            if (p->child[index]) {
                p = p->child[index];
            } else {
                return false;
            }
        }
        return true;
    }

private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main(int argc, char *argv[]) {
    Trie obj;
    obj.insert("abc");
    obj.insert("app");
    obj.insert("helloworld");
    cout << boolalpha << obj.search("abc") << endl;
    cout << boolalpha << obj.search("ab") << endl;
    cout << boolalpha << obj.startsWith("a") << endl;
}
