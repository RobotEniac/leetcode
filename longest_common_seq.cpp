// =====================================================
//       Filename:  longest_common_seq.cpp
//         Author:  wuhaibo <gethaibo@gmail.com>
//        Created:  2017/12/01
//    Description:  
//    Copyright (c) 2017, NONE, All rights reserved. 
// =====================================================

#include <vector>
#include <string>
#include <iostream>

#include "util.h"

using namespace std;

int LCS(string &s1, string &s2) {
    int l1 = s1.size();
    int l2 = s2.size();
    if (l1 == 0 || l2 == 0) {
        return 0;
    }
    vector<vector<int> > memo(l1, vector<int>(l2, 0));
    for (int i1 = 0; i1 < l1; ++i1) {
        for (int i2 = 0; i2 < l2; ++i2) {
            if (i1 == 0 || i2 == 0) {
                memo[i1][i2] = 0;
            } else if (s1[i1] == s2[i2]) {
                memo[i1][i2] = memo[i1 - 1][i2 - 1];
            } else {
                memo[i1][i2] = max(memo[i1][i2 - 1], memo[i1 - 1][i2]);
            }
        }
    }
    return memo[l1 - 1][l2 - 1];
}

