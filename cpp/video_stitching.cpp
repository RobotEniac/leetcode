// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/10/28 19:37:19
// Description: https://leetcode-cn.com/problems/video-stitching/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "util.h"

using namespace std;

void show(vector<vector<int>> &v) {
    cout << "[";
    for (int i = 0; i < v.size(); ++i) {
        if (i != 0) {
            cout << ", ";
        }
        cout << "[" << v[i][0] << ", " << v[i][1] << "]";
    }
    cout << "]\n";
}

int videoStitching(vector<vector<int>>& clips, int T) {
    sort(clips.begin(), clips.end(),
         [&clips](vector<int>& v1, vector<int>& v2) -> bool { return v1[0] < v2[0]; });
    int s = 0;
    int cnt = 0;
    int last = 0;
    while (s < T) {
        int longest = s;
        for (int i = last; i < clips.size(); ++i) {
            if (clips[i][0] <= s) {
                if (clips[i][1] > longest) {
                    longest = clips[i][1];
                    last = i;
                }
            } else {
                break;
            }
        }
        if (longest == s) {
            return -1;
        }
        s = longest;
        ++cnt;
    }
    return cnt;
}

int main(int argc, char *argv[]) {
    vector<vector<int>> v = {{0,2},{4,6},{8,10},{1,9},{1,5},{5,9}};
    cout << videoStitching(v, 10) << endl;
}
