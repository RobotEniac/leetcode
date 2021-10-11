// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/09/13 15:47:36
// Description: https://leetcode-cn.com/problems/odd-even-linked-list/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"
#include "list_node.hpp"

using namespace std;

ListNode* oddEvenList(ListNode* head) {
    if (head == NULL) {
        return head;
    }
    if (head->next == NULL) {
        return head;
    }
    ListNode *ret = head;
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *p = even->next;
    int i = 1;
    while (p != NULL) {
        ListNode *tmp = p->next;
        if (i % 2 != 0) {
            p->next = odd->next;
            odd->next = p;
            odd = odd->next;
        } else {
            p->next = even->next;
            even->next = p;
            even = even->next;
        }
        p = tmp;
        ++i;
    }
    even->next = NULL;
    return ret;
}

int main(int argc, char *argv[]) {
    vector<int> v = {1,2,3,4};
    ListNode *root = MakeList(v);
    cout << root << endl;
    cout << oddEvenList(root) << endl;
}
