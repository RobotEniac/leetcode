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
        for (int i = 0; i < word.size(); ++i) {
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {

    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {

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
    cout << "hello world" << endl;
}
