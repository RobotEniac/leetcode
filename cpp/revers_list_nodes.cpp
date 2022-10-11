// =====================================================
//       Filename:  revers_list_nodes.cpp
//         Author:  wuhaibo <gethaibo@gmail.com>
//        Created:  2017/02/17
//    Description:
//    Copyright (c) 2017, NONE, All rights reserved.
// =====================================================

#include "list_node_tpl.h"
#include <iostream>

using namespace std;

typedef ListNodeTpl<int> ListNode;

ListNode* reverse(ListNode *begin, ListNode* end) {
    if (begin == NULL || begin == end) {
        return begin;
    }
    if (begin != end && begin->next == end) {
        return begin;
    }
    ListNode dummy(0);
    dummy.next = end;
    ListNode *curr = begin;
    while (curr != NULL && curr != end) {
        ListNode *tmp = curr->next;
        curr->next = dummy.next;;
        dummy.next = curr;
        curr = tmp;
    }
    return dummy.next;
}

ListNode *reversek(ListNode *root, int k) {
    ListNode dummy(0);
    dummy.next = root;
    ListNode *ch = root;
    ListNode *p = root;
    int i = 0;
    while (p != NULL) {
        if (
    }
}

int main(int argc, char* argv[]) {
    int len = atoi(argv[1]);
    if (len < 6) {
        cerr << "len must over 6\n";
        exit(1);
    }
    ListNode *head = MakeList(len);
    ListNode *p = head;
    for (int i = 0; i < 5; ++i) {
        p = p->next;
    }
    std::cout << head << endl;
    cout << reverse(head, p) << endl;
}

