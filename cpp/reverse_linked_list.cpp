// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/03/09 17:00:20
// Description: https://leetcode.com/problems/reverse-linked-list/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"
#include "list_node.hpp"

using namespace std;

ListNode* reverseList(ListNode* head) {
    ListNode gd;
    ListNode *p = head;
    ListNode *t = NULL;
    while (p != NULL) {
        t = p->next;
        p->next = gd.next;
        gd.next = p;
        p = t;
    }
    return gd.next;
}

ListNode *reverse(ListNode *root) {
    if (root == NULL) {
        return NULL;
    }
    ListNode a;
    ListNode *p = root;
    while (p != NULL) {
        ListNode *tmp = p->next;
        p->next = a.next;
        a.next = p;
        p = tmp;
    }
    return a.next;
}

int main(int argc, char *argv[]) {
    ListNode *p = MakeList(10, true);
    cout << p << endl;
    cout << reverse(p) << endl;
}
