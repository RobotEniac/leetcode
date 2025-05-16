#include <string>
#include <vector>
#include <iostream>
#include <map>

struct RadixTreeNode {
    std::vector<RadixTreeNode*> children;
    std::string word;
    bool is_end;
    RadixTreeNode()
        : is_end(false) {}
};

int same_prefix(const std::string &a, const std::string &b) {
    int i = 0;
    while (i < a.size() && i < b.size()) {
        if (a[i] != b[i]) {
            break;
        }
        ++i;
    }
    return i;
}

void InsertRadixTree(RadixTreeNode *root, const std::string &word) {
    if (word.empty()) {
        return;
    }
    if (word == root->word) {
        root->is_end = true;
        return;
    }
    int prefix = same_prefix(root->word, word);
    if (prefix == root->word.size()) {
        std::string remain = word.substr(prefix);
        for (int i = 0; i < root->children.size(); ++i)
        {
            int tmp = same_prefix(root->children[i]->word, remain);
            if (tmp > 0)
            {
                InsertRadixTree(root->children[i], remain);
                return;
            }
        }
        RadixTreeNode *p = new RadixTreeNode();
        p->word = remain;
        p->is_end = true;
        root->children.push_back(p);
        return;
    }

    RadixTreeNode *p = new RadixTreeNode();
    *p = *root;
    p->word = root->word.substr(prefix);
    root->children = std::vector<RadixTreeNode*>(1, p);
    if (prefix == word.size()) {
        root->word = word;
        root->is_end = true;
        return;
    }
    root->word = word.substr(0, prefix);
    root->is_end = false;
    RadixTreeNode *q = new RadixTreeNode();
    q->word = word.substr(prefix);
    q->is_end = true;
    root->children.push_back(q);
}

bool SearchRadixTree(RadixTreeNode *root, const std::string &word) {
    return false;
}

void dfsShow(RadixTreeNode *root, int height) {
    if (root == NULL) {
        return;
    }
    std::string prefix(height * 2, ' ');
    std::cout << prefix;
    if (root->word.empty()) {
        std::cout << "root" << std::endl;
    } else {
        std::cout << root->word << std::endl;
    }
    for (int i = 0; i < root->children.size(); ++i) {
        dfsShow(root->children[i], height+1);
    }
}

int main(int argc, char *argv[]) {
    RadixTreeNode *root = new RadixTreeNode();
    InsertRadixTree(root, "test");
    InsertRadixTree(root, "toster");
    InsertRadixTree(root, "toasting");
    InsertRadixTree(root, "show");
    InsertRadixTree(root, "showme");
    dfsShow(root, 0);
}
