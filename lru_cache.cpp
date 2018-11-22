// =====================================================
//       Filename:  lru_cache.cpp
//         Author:  wuhaibo <gethaibo@gmail.com>
//        Created:  2017/07/02
//    Description:  
//    Copyright (c) 2017, NONE, All rights reserved. 
// =====================================================

#include <map>
#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

class LRUCache {
public:
    struct Node {
        int val;
        int index;
    };

    typedef map<int, Node>::iterator iterator;

public:
    LRUCache(int capacity);

    ~LRUCache() {}

    void set(int key, int value);

    int get(int key);

private:
    map<int, Node> m_map;

    vector<int> m_lru_list;
};

LRUCache::LRUCache(int capacity)
    : m_lru_list(capacity) {
}

void LRUCache::set(int key, int value) {
    iterator it = m_map.find(key);
}

int LRUCache::get(int key) {
    return 0;
}

