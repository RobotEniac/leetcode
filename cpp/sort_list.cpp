// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/10/30 11:39:03
// Description: https://leetcode-cn.com/problems/sort-list/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"
#include "list_node.hpp"
#include "file_util.h"

using namespace std;
using namespace leetcode;

ListNode* select(ListNode *start, ListNode* end, ListNode** m) {
    ListNode* pivot = start;
    ListNode *prep = start;
    ListNode *p = start->next;
    ListNode* l = start;
    while (p != end) {
        if (p->val <= pivot->val) {
            if (l == prep) {
                prep = p;
                l = p;
                p = p->next;
            } else {
                prep->next = p->next;
                p->next = l->next;
                l->next = p;
                l = l->next;
                p = prep->next;
            }
        } else {
            prep = p;
            p = p->next;
        }
    }
    if (l != start) {
        start = start->next;
        pivot->next = l->next;
        l->next = pivot;
        *m = l->next;
    } else {
        *m = l;
    }
    return start;
}

bool sorted(ListNode* start, ListNode* end) {
    if (start == end) {
        return true;
    }
    if (start->next == end) {
        return true;
    }

    while(start->next != end) {
        if (start->val > start->next->val) {
            return false;
        }
        start = start->next;
    }
    return true;
}

ListNode* qsort(ListNode* start, ListNode* end) {
    if (sorted(start, end)) {
        return start;
    }
    ListNode* m = NULL;
    start = select(start, end, &m);
    start = qsort(start, m);
    if (m != end) {
        m->next = qsort(m->next, end);
    }
    return start;
}

ListNode* sortList(ListNode* head) {
    return qsort(head, NULL);
}

int main(int argc, char *argv[]) {
    vector<int> v;
    std::string raw = ReadAll("./testcase.txt");
    raw = StringTrim(raw, "[]");
    vector<string> vec_str = SplitString(raw, ",");
    for (int i = 0; i < vec_str.size(); ++i) {
        int t = StringToInt32(StringTrim(vec_str[i]));
        v.push_back(t);
    }
    ListNode *l = MakeList(v);
    l = sortList(l);
    cout << l << endl;
}
