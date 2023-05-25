// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/03/02 18:43:42
// Description: https://leetcode.cn/problems/0H97ZC/

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "util.h"

using namespace std;

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    map<int, int> m;
    for (int i = 0; i < arr2.size(); ++i) {
        m[arr2[i]] = i;
    }
    auto fun = [&m] (int a, int b) -> bool {
        cout << "[" << a << ", " << b << "]";
        if (m.find(a) != m.end() && m.find(b) != m.end()) {
            cout << "->" << m[a] << ", " << m[b] << endl;
            return m[a] < m[b];
        } else {
            cout << endl;
            return a < b;
        }
    };
    sort(arr1.begin(), arr1.end(), fun);
    return arr1;
}

int main(int argc, char *argv[]) {
    vector<int> a1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> a2 = {2,1,4,3,9,6};
    cout << relativeSortArray(a1, a2) << endl;
}
