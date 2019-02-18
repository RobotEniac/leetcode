// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/02/07
// Description: 

#include <vector>
#include <iostream>

#include "util.h"
#include "list_node_tpl.h"

typedef ListNodeTpl<int> ListNode;

using namespace std;

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *pa = headA;
    ListNode *pb = headB;
    while (pa && pb) {
        pa = pa->next;
        pb = pb->next;
    }
    if (pa == NULL && pb == NULL) {
        return NULL;
    }
    if (pa == NULL) {
        pa = headB;
        while (pb) {
            pa = pa->next;
            pb = pb->next;
        }
        pb = headA;
        while (pa != pb) {
            pa = pa->next;
            pb = pb->next;
        }
        return pa;
    }
    return getIntersectionNode(headB, headA);
}

ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
    ListNode *pa = headA;
    ListNode *pb = headB;
    while (pa != pb) {
        pa = pa ? pa->next : headB;
        pb = pb ? pb->next : headA;
    }
    return pa;
}

int main(int argc, char *argv[]) {
    // vector<int> a = {4,1,8,4,5};
    // vector<int> b = {5,0,1,8,4,5};
    vector<int> c = {8,4,5};
    ListNode *inter = MakeList(c);
    ListNode *la = new ListNode(4);
    ListNode *pa = la;
    pa->next = new ListNode(1);
    pa = pa->next;
    pa->next = inter;

    ListNode *pb = new ListNode(5);
    ListNode *lb = pb;
    lb->next = new ListNode(0);
    lb = lb->next;
    lb->next = new ListNode(1);
    lb = lb->next;
    lb->next = inter;
    lb = pb;
    std::cout << la << std::endl;
    std::cout << lb << std::endl;

    ListNode *t = getIntersectionNode(la, lb);
    std::cout << t << std::endl;

    t = getIntersectionNode2(la, lb);
    std::cout << t << std::endl;
}
