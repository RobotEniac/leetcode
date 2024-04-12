// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2024/03/22 11:28:47
// Description: https://leetcode.cn/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"
#include "list_node.hpp"

using namespace std;

ListNode* removeZeroSumSublists(ListNode* head) {
    const int flag = 0x0f0f0f0f;
    ListNode h;
    h.val = 0;
    h.next = head;
    map<int, ListNode*> m;
    vector<ListNode*> to_be_del;
    int sum = 0;
    for (ListNode* p = &h; p != NULL; p = p->next) {
        sum += p->val;
        if (m.find(sum) == m.end()) {
            m[sum] = p;
        } else {
            if (m[sum]->val != flag) {
                ListNode *t = m[sum];
                ListNode *pn = p->next;
                while (t->next != pn) {
                    t->next->val = flag;
                    to_be_del.push_back(t->next);
                    t->next = t->next->next;
                }
                p = t;
            } else {
                m[sum] = p;
            }
        }
    }
    for (int i = 0; i < to_be_del.size(); ++i) {
        delete to_be_del[i];
    }
    return h.next;
}

int main(int argc, char *argv[]) {
    vector<int> v = {1,3,2,-3,-2,5,5,-5,1};
    ListNode *l = MakeList(v);
    cout << l << endl;
    l = removeZeroSumSublists(l);
    cout << l << endl;
}
