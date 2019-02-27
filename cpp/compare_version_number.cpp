// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/02/18
// Description: 

#include "stdlib.h"
#include <vector>
#include <string>
#include <iostream>

#include "util.h"

using namespace std;

std::vector<int> split(const std::string &version) {
    vector<int> ret;
    size_t s = 0;
    while (s != std::string::npos) {
        size_t e = version.find(".", s);
        if (e == std::string::npos) {
            break;
        }
        string sub = version.substr(s, e - s);
        if (!sub.empty()) {
            int v = atoi(sub.c_str());
            ret.push_back(v);
        }
        s = e + 1;
    }
    string sub = version.substr(s);
    if (!sub.empty()) {
        int v = atoi(sub.c_str());
        ret.push_back(v);
    }
    return ret;
}

int compareVersion(string version1, string version2) {
    std::vector<int> v1 = split(version1);
    std::vector<int> v2 = split(version2);
    for (int i = 0; i < std::max(v1.size(), v2.size()); ++i) {
        int n1 = i < v1.size() ? v1[i] : 0;
        int n2 = i < v2.size() ? v2[i] : 0;
        if (n1 < n2) {
            return -1;
        }
        if (n1 > n2) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    std::string v1 = argv[1];
    std::string v2 = argv[2];

    cout << v1 << ", " << v2 << "\n";
    cout << compareVersion(v1, v2) << endl;
}
