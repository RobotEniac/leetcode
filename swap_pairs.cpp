// =====================================================
//       Filename:  swap_pairs.cpp
//         Author:  wuhaibo <gethaibo@gmail.com>
//        Created:  2017/02/17
//    Description:  
//    Copyright (c) 2017, NONE, All rights reserved. 
// =====================================================

#include "list_node_tpl.h"
#include <iostream>

using namespace std;

typedef ListNodeTpl<int> ListNode;

ListNode* swapPairs(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode dummy(0);
    dummy.next = head;
    ListNode *curr = &dummy;
    while (curr->next != NULL && curr->next->next != NULL) {
        ListNode *tmp = curr->next;
        curr->next = curr->next->next;
        tmp->next = curr->next->next;
        curr->next->next = tmp;
        curr = curr->next->next;
    }
    return dummy.next;
}

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);
    ListNode *head = MakeList(n);
    
    cout << head << endl;
    cout << swapPairs(head) << endl;
}
