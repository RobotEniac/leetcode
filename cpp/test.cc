#include <iostream>
#include <vector>
#include <deque>

#include "binary_tree.hpp"

using namespace std;

#define null 0x0f0f0f0f

TreeNode* makeTree(vector<int> ary) {
    if (ary.size() == 0) {
        return NULL;
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

int main(int ac, char *av[]) {
    vector<int> nums = {5,3,6,2,4,null,null,1};
    TreeNode *p = makeTree(nums);
    PrintTreeNode(p, 0);
}

