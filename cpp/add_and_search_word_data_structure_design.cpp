// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/03/25 17:22:10
// Description: https://leetcode.com/problems/add-and-search-word-data-structure-design/

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

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary()
        : root(new TrieNode)
    {
    }

    ~WordDictionary() {
        if (root == NULL) {
            return;
        }
        for (int i = 0; i < MAX_SIZE; ++i) {
            delete root->child[i];
            root->child[i] = NULL;
        }
    }


    /** Adds a word into the data structure. */
    void addWord(string word) {
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

    bool search_recursive(TrieNode *root, const string &word) {
        if (root == NULL) {
            return false;
        }
        if (word.empty()) {
            return root->is_leaf;
        }
        TrieNode *p = root;
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] >= 'a' && word[i] <= 'z') {
                int index = word[i] - 'a';
                if (p->child[index]) {
                    p = p->child[index];
                } else {
                    return false;
                }
            } else if (word[i] == '.') {
                for (int idx = 0; idx < MAX_SIZE; ++idx) {
                    if (p->child[idx]) {
                        if (search_recursive(p->child[idx], word.substr(i+1))) {
                            return true;
                        }
                    }
                }
                return false;
            } else {
                return false;
            }
        }
        return p->is_leaf;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        cout << word << " -> ";
        return search_recursive(root, word);
    }

private:
    TrieNode *root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
/*
 * ["WordDictionary","addWord","addWord","addWord","addWord","search","search","addWord","search","search","search","search","search","search"]
 * [[],               ["at"],["and"],["an"],["add"],["a"],[".at"],["bat"],[".at"],["an."],["a.d."],["b."],["a.d"],["."]]
 */

int main(int argc, char *argv[]) {
    WordDictionary dict;
    dict.addWord("at");
    dict.addWord("and");
    dict.addWord("an");
    dict.addWord("add");
    cout << boolalpha << dict.search("a") << endl;
    cout << boolalpha << dict.search(".at") << endl;
    dict.addWord("bat");
    cout << boolalpha << dict.search(".at") << endl;
    cout << boolalpha << dict.search("an.") << endl;
    cout << boolalpha << dict.search("a.d.") << endl;
    cout << boolalpha << dict.search("b.") << endl;
    cout << boolalpha << dict.search("a.d") << endl;
    cout << boolalpha << dict.search(".") << endl;
}
