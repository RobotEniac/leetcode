// =====================================================
//       Filename:  remove_nth_node.cpp
//         Author:  wuhaibo <gethaibo@gmail.com>
//        Created:  2017/02/14
//    Description:  
//    Copyright (c) 2017, NONE, All rights reserved. 
// =====================================================

#include <iostream>

#include "list_node_tpl.h"

using namespace std;
typedef ListNodeTpl<int> ListNode;

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == NULL) {
        return NULL;
    }
    ListNode *p1, *p2;
    ListNode *prev;
    p1 = p2 = NULL;
    p2 = head;
    int i = 0;
    for (; i < n; ++i) {
        if (p2 == NULL) {
            break;
        }
        p2 = p2->next;
    }
    if (i < n) {
        return head;
    }
    prev = NULL;
    p1 = head;
    while (p2 != NULL) {
        prev = p1;
        p1 = p1->next;
        p2 = p2->next;
    }
    if (prev == NULL) {
        prev = p1;
        p1 = p1->next;
        delete prev;
    } else {
        prev->next = p1->next;
        p1->next = NULL;
        delete p1;
        p1 = head;
    }
    return p1;
}

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);
    int nth = atoi(argv[2]);
    ListNode *head = NULL;
    ListNode *p = NULL;
    for (int i = 1; i <= n; ++i) {
        ListNode *tmp = new ListNode(i);
        if ( i == 1) {
            head = tmp;
            p = tmp;
        } else {
            p->next = tmp;
            p = p->next;
        }
    }
    cout << head << endl;
    cout << removeNthFromEnd(head, nth) << endl;
}
