// =====================================================
//       Filename:  list_node_tpl.h
//         Author:  wuhaibo <gethaibo@gmail.com>
//        Created:  2016/03/26
//    Description:  list node template
//    Copyright (c) 2016, NONE, All rights reserved. 
// =====================================================
#include <sstream>

template<class T>
struct ListNodeTpl {
    T val;
    ListNodeTpl* next;
    ListNodeTpl(T x) : val(x), next(NULL) {}
};

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

ListNodeTpl<int>* MakeList(int length) {
    ListNodeTpl<int> *head = NULL;
    ListNodeTpl<int> *p = NULL;
    for (int i = 1; i <= length; ++i) {
        ListNodeTpl<int> *tmp = new ListNodeTpl<int>(i);
        if ( i == 1) {
            head = tmp;
            p = tmp;
        } else {
            p->next = tmp;
            p = p->next;
        }
    }
    return head;
}
