// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/03/07 14:40:15
// Description: https://leetcode.com/problems/remove-linked-list-elements/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"
#include "list_node.hpp"

using namespace std;

ListNode* removeElements(ListNode* head, int val) {
    if (head == NULL) {
        return head;
    }
    if (head->next == NULL && head->val == val) {
        return NULL;
    }
    ListNode guard(-1);
    guard.next = head;
    ListNode *prep = &guard;
    ListNode *p = head;
    while (p) {
        if (p->val == val) {
            prep->next = p->next;
            p->next = NULL;
            delete p;
            p = prep->next;
        } else {
            prep = p;
            p = p->next;
        }
    }
    return guard.next;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int val = atoi(argv[2]);
    ListNode *root = MakeList(n, true);
    cout << root << endl;
    ListNode *p = removeElements(root, val);
    cout << p << endl;
}
