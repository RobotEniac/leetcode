// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2024/01/24 20:37:02
// Description: https://leetcode.cn/problems/operations-on-tree/?envType=daily-question&envId=2024-01-17

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

class LockingTree {
public:
    LockingTree(vector<int>& parent)
        : parrent_(parrent),
        tree_(vector<int>(), parrent.size()),
        lock_(-1, parrent.size())
    {
        for (int i = 0; i < parrent.size(); ++i) {
            if (parrent[i] != -1) {
                tree_[parrent[i]].push_back(i);
            }
        }
    }

    bool lock(int num, int user) {
        if (lock_[num] == -1) {
            lock[num] = user;
            return true;
        }
        return false;
    }

    bool unlock(int num, int user) {
        if (lock_[num] == -1) {
            return false;
        }
        lock_[num] = -1;
        return true;
    }

    bool upgrade(int num, int user) {
        if (lock_[num] != -1) {
            return false;
        }
        int i = num;
        while (i >= 0) {
            if (lock_[i] != -1) {
                return false;
            }
            i = parrent_[i];
        }
        if (dfsCheckLock(num)) {
            dfsUnlock(num);
            lock_[num] = user;
        }
    }

    bool dfsCheckLock(int n) {
        if (lock_[n] != -1) {
            return true;
        }
        for (int i = 0; i < tree_[n].size(); ++i) {
            if (dfsCheckLock(tree_[n][i])) {
                return true;
            }
        }
        return false;
    }

    void dfsUnlock(int n) {
        lock_[n] = -1;
        for (int i = 0; i < tree_[n].size(); ++i) {
            dfsUnlock(tree_[n][i]);
        }
    }

private:
    vector<int> parrent_;
    vector<vector<int> > tree_;
    vector<int> lock_;
};

int main(int argc, char *argv[]) {
    cout << "hello world" << endl;
}
