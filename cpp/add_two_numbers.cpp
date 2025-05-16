// =====================================================
//       Filename:  add_two_numbers.cpp
//         Author:  wuhaibo <gethaibo@gmail.com>
//        Created:  2016/03/26
//    Description:
//    Copyright (c) 2016, NONE, All rights reserved.
// =====================================================
// 大数和，逆序后按位加，注意好进位就行

#include "list_node_tpl.h"
#include <iostream>

typedef ListNodeTpl<int> ListNode;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int c = 0;
    ListNode* result = new ListNode(0);
    ListNode * prep = NULL;
    ListNode *p = result;
    while (l1 && l2) {
        p->val = (l1->val + l2->val + c) % 10;
        c = (l1->val + l2->val + c) / 10;
        p->next = new ListNode(0);
        prep = p;
        p = p->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1) {
        p->val = (l1->val + c) % 10;
        c = (l1->val + c) / 10;
        prep = p;
        p->next = new ListNode(0);
        p = p->next;
        l1 = l1->next;
    }
    while (l2) {
        p->val = (l2->val + c) % 10;
        c = (l2->val + c) / 10;
        prep = p;
        p->next = new ListNode(0);
        p = p->next;
        l2 = l2->next;
    }
    if (c != 0) {
        p->val = c;
    }
    if (prep == NULL) {
        return NULL;
    }
    if (p->val == 0) {
        prep->next = NULL;
        delete p;
    }
    return result;
}

int main(int argc, char* argv[]) {
    ListNode* l1 = new ListNode(0);
    ListNode* l2 = new ListNode(7);
    l2->next = new ListNode(3);
    std::cout << "l1: " << l1 << "\n";
    std::cout << "l2: " << l2 << "\n";
    ListNode* ret = addTwoNumbers(l1, l2);
    std::cout << ret << "\n";
    return 0;
}
