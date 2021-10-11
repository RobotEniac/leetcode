// =====================================================
//       Filename:  list_node_tpl.h
//         Author:  wuhaibo <gethaibo@gmail.com>
//        Created:  2016/03/26
//    Description:  list node template
//    Copyright (c) 2016, NONE, All rights reserved.
// =====================================================
#include <sstream>
#include <vector>

template<class T>
struct ListNodeTpl {
    T val;
    ListNodeTpl* next;
    ListNodeTpl() : val(0), next(NULL) {}
    ListNodeTpl(T x) : val(x), next(NULL) {}
    ~ListNodeTpl() {
    }
};

typedef ListNodeTpl<int> ListNode;

template<class T>
std::ostream& operator<<(std::ostream& out, const ListNodeTpl<T>* list) {
    const ListNodeTpl<T>* p = list;
    if (p == NULL) {
        out << "()";
    }
    out << "(";
    while (p->next) {
        out << p->val << " -> ";
        p = p->next;
    }
    out << p->val << ")";
    return out;
}

ListNodeTpl<int>* MakeList(int length, bool random = false) {
    ListNodeTpl<int> head;
    ListNodeTpl<int> *p = &head;
    for (int i = 1; i <= length; ++i) {
        ListNodeTpl<int> *tmp;
        if (random) {
            tmp = new ListNodeTpl<int>(rand() % 10);
        } else {
            tmp = new ListNodeTpl<int>(i);
        }
        p->next = tmp;
        p = p->next;
    }
    return head.next;
}

template<typename T>
ListNodeTpl<T>* MakeList(std::vector<T> &v) {
    ListNodeTpl<T> head;
    ListNodeTpl<T> *p = &head;
    for (size_t i = 0; i < v.size(); ++i) {
        p->next = new ListNodeTpl<T>(v[i]);
        p = p->next;
    }
    return head.next;
}

template<typename T>
ListNodeTpl<T> **findIndirect(ListNodeTpl<T> *head, T val) {
    ListNodeTpl<T> **p = &head;
    while ((*p) != NULL && (*p)->val != val) {
        p = &(*p)->next;
    }
    return p;
}

template<typename T>
ListNodeTpl<T> *FindNode(ListNodeTpl<T> *head, T val) {
    ListNodeTpl<T> **p = findIndirect(head, val);
    return *p;
}

template<typename T>
ListNodeTpl<T> InsertNode(ListNodeTpl<T> *head, T before, ListNodeTpl<T> *insert) {
    ListNodeTpl<T> **p = findIndirect(head, before);
    insert->next = (*p)->next;
    *p = insert;
}

template<typename T>
ListNodeTpl<T> RemoveNode(ListNodeTpl<T> *head, T remove) {
    ListNodeTpl<T> **p = findIndirect(head, remove);
    *p = (*p)->next;
}

