// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2022/09/20 10:27:38
// Description: https://leetcode.cn/problems/minimum-genetic-mutation/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>

#include "util.h"

using namespace std;

struct Node {
    string value;
    int flag;

    explicit Node(const std::string& o) :
        value(o),
        flag(0){}
};

int diff(const string& l, const string& r) {
    if (l.size() != r.size()) {
        return -1;
    }
    int count = 0;
    for (int i = 0; i < l.size(); ++i) {
        if (l[i] != r[i]) {
            ++count;
        }
    }
    return count;
}

void bfs(const Node& s, vector<Node>& bank, queue<Node>& ret) {
    for (auto it = bank.begin(); it != bank.end(); ++it) {
        int df = diff(s.value, it->value);
        if (df == 1 && it->flag == 0) {
            Node n(it->value);
            n.flag = s.flag+1;
            ret.push(n);
            it->flag = 1;
        }
    }
}

int minMutation(const string& start, const string& end, vector<string>& bank) {
    vector<Node> bkk;
    for (int i = 0; i < bank.size(); ++i) {
        Node n(bank[i]);
        bkk.push_back(n);
    }
    queue<Node> q;
    Node ns(start);
    bfs(ns, bkk, q);
    while (!q.empty()) {
        Node tmp = q.front();
        q.pop();
        if (tmp.value == end) {
            return tmp.flag;
        } else {
            bfs(tmp, bkk, q);
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {
    vector<string> bank = {"AAAACCCC","AAACCCCC","AACCCCCC"};
    cout << minMutation("AAAAACCC", "AACCCCCC", bank) << endl;
}
