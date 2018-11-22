// =====================================================
//       Filename:  permutation.cpp
//         Author:  wuhaibo <gethaibo@gmail.com>
//        Created:  2017/02/18
//    Description:  
//    Copyright (c) 2017, NONE, All rights reserved. 
// =====================================================

#include "util.h"
#include <vector>
#include <iostream>

using namespace std;

bool next_permutation(vector<int>& v) {
    if (v.size() < 2) {
        return false;
    }
    int i = v.size() - 1;
    while (i > 0 && v[i-1] >= v[i]) --i;
    if (i == 0) {
        for (int start = 0, end = v.size() - 1; start < end; ++start, --end) {
            int tmp = v[start];
            v[start] = v[end];
            v[end] = tmp;
        }
        return false;
    }
    --i;
    int j = v.size() - 1;
    while (v[j] <= v[i]) --j;
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
    for (int start = i+1, end = v.size() - 1; start < end; ++start, --end) {
        int tmp = v[start];
        v[start] = v[end];
        v[end] = tmp;
    }
    return true;
}

int main(int argc, char* argv[]) {
    int len = atoi(argv[1]);
    vector<int> v;
    for (int i = 0; i < len; ++i) {
        v.push_back(i + 1);
    }
    int i = 1;
    while (next_permutation(v)) {
        cout << v << endl;
        ++i;
    }
    cout << i << endl;
}

