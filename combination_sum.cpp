// =====================================================
//       Filename:  combination_sum.cpp
//         Author:  wuhaibo <gethaibo@gmail.com>
//        Created:  2017/02/19
//    Description:  
//    Copyright (c) 2017, NONE, All rights reserved. 
// =====================================================

#include <iostream>
#include <vector>

#include "util.h"

using namespace std;

vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    if (candidates.size() == 0) {
        return vector<vector<int> >();
    }
    if (candidates.size() == 1) {
        if (candidates[0] != target) {
            return vector<vector<int> >();
        } else {
            vector<int> temp_v(1, target);
            return vector<vector<int> >(1, temp_v);
        }
    }
    if (candidates[0] > target) {
        return vector<vector<int> >();
    }
    if (candidates[0] == target) {
        vector<int> temp_v(1, target);
        return vector<vector<int> >(1, temp_v);
    }
    int n = candidates[0];
    vector<vector<int> > ret;

    vector<vector<int> > with_n_ret = combinationSum(candidates, target - n);
    for (size_t i = 0; i < with_n_ret.size(); ++i) {
        with_n_ret[i].push_back(n);
        ret.push_back(with_n_ret[i]);
    }

    vector<int> without_n(candidates.begin() + 1, candidates.end());
    vector<vector<int> > without_n_ret = combinationSum(without_n, target);
    for (size_t i = 0; i < without_n_ret.size(); ++i) {
        ret.push_back(without_n_ret[i]);
    }
    return ret;
}

int main(int argc, char* argv[]) {
    const int N = 4;
    int a[N] = {2, 3, 6, 7};
    vector<int> com(a, a+N);
    vector<vector<int> > ret = combinationSum(com, 7);
    for (size_t i = 0; i < ret.size(); ++i) {
        cout << ret[i] << endl;
    }
}

