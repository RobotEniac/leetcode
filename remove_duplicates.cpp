// =====================================================
//       Filename:  remove_duplicates.cpp
//         Author:  wuhaibo <gethaibo@gmail.com>
//        Created:  2017/02/17
//    Description:  
//    Copyright (c) 2017, NONE, All rights reserved. 
// =====================================================

#include <vector>
#include <string>
#include <iostream>

#include "util.h"

using namespace std;

int removeDuplicates(vector<int>& a) {
    if (a.size() < 2) {
        return a.size();
    }
    int d = 1;
    for (int i = 1; i < a.size(); ++i) {
        if (a[i] != a[i-1]) a[d++] = a[i];
    }
    return d;
}

int main(int argc, char* argv[]) {
    int len = atoi(argv[1]);
    vector<int> v;
    for (int i = 0; i < len; ++i) {
        if (i % 2 == 1)
            v.push_back(i);
        else
            v.push_back(i + 1);
    }
    cout << v << endl;
    int sz = removeDuplicates(v);
    for (int i = 0; i < sz; ++i) {
        if (i != 0) cout << ", ";
        cout  << v[i];
    }
    cout << endl;
}
