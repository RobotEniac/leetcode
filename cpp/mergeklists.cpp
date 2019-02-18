#include <iostream>
#include <vector>
#include "list_node_tpl.h"

using namespace std;

typedef ListNodeTpl<int> ListNode;

ListNode *mergeKLists(vector<ListNode*> &list) {
    if (list.size() == 0) {
        return NULL;
    }
    if (list.size() == 1) {
        return list[0];
    }

    int n = list.size();
    vector<ListNode*> idx(n, NULL);
    ListNode max_guard(INT_MAX);
    ListNode *ret = NULL;
    ListNode *ret_last = NULL;
    for (size_t i = 0; i < n; ++i) {
        idx[i] = list[i];
    }
    ListNode *min_p = &max_guard;
    int min_idx = -1;
    while (true) {
        min_p = &max_guard;
        min_idx = -1;
        for (int i = 0; i < n; ++i) {
            if (idx[i] == NULL) {
                idx[i] = &max_guard;
            }
            else if (idx[i] != &max_guard && idx[i]->val <= min_p->val) {
                min_p = idx[i];
                min_idx = i;
            }
        }
        if (min_idx == -1) {
            break;
        }
        else {
            if (ret == NULL) {
                ret = new ListNode(min_p->val);
                ret_last = ret;
            }
            else {
                ret_last->next = new ListNode(min_p->val);
                ret_last = ret_last->next;
            }
            idx[min_idx] = idx[min_idx]->next;
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    std::vector<ListNode*> lists;
    lists.push_back(MakeList(5));
    lists.push_back(MakeList(3));
    lists.push_back(MakeList(1));
    std::cout << lists[0] << std::endl;
    std::cout << lists[1] << std::endl;
    std::cout << lists[2] << std::endl;
    ListNode *p = mergeKLists(lists);
    std::cout << p << std::endl;
}
