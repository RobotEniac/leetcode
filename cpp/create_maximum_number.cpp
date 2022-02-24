// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/05/11 21:24:37
// Description: https://leetcode.com/problems/create-maximum-number/

#include <unistd.h>

#include <iostream>
#include <vector>
#include <string>
#include <stack>

#include "util.h"

using namespace std;

vector<int> maxArray2(vector<int>& num, int k) {
    if (num.size() == k) {
        return num;
    }
    if (num[0] < num[1]) {
        vector<int> sub(num.begin()+1, num.end());
        return maxArray2(sub, k);
    }
    int p = 0;
    while (p < num.size()-1 && num[p] > num[p+1]) {
        ++p;
    }
    vector<int> sub;
    for (int i = 0; i < num.size(); ++i) {
        if (i != p) {
            sub.push_back(num[i]);
        }
    }
    return maxArray2(sub, k);
}


vector<int> maxArray(vector<int>& num, int k) {
    vector<int> ret(k, 0);
    for (int i = 0, j = 0; i < num.size(); ++i) {
        if (j == 0) {
            ret[j++] = num[i];
            continue;
        }
        while (j > 0 && ret[j-1] < num[i] && num.size() - i > k - j) {
            --j;
        }
        if (j < k) {
            ret[j++] = num[i];
        }
    }
    return ret;
}

vector<int> remove0(vector<int>& a) {
    int i = 0;
    while (i < a.size() && a[i] == 0) i++;
    if (i == a.size()) {
        return a;
    }
    vector<int> ret(a.begin() + i, a.end());
    return ret;
}

int compare(vector<int> &a, vector<int>& b) {
    a = remove0(a);
    b = remove0(b);
    if (a.size() > b.size()) {
        return 1;
    }
    if (a.size() < b.size()) {
        return -1;
    }
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] > b[i]) {
            return 1;
        } else if (a[i] < b[i]) {
            return -1;
        }
    }
    return 0;
}

void show(vector<int> a, int s) {
    cout << a.size()-s << ":[";
    for (int i = s; i < a.size(); ++i) {
        if (i != s) {
            cout << ", ";
        }
        cout << a[i];
    }
    cout << "]";
}

int dfs(vector<int>& n1, vector<int>& n2, int s1, int s2, int k, vector<int>& res, vector<int>& mmax) {
    show(n1, s1);
    cout << ", ";
    show(n2, s2);
    cout << ", ";
    show(res, 0);
    cout << ", ";
    show(mmax, 0);
    cout << endl;
    if (n1.size() - s1 + n2.size() - s2 < k) {
        return -1;
    }
    if (k == 0) {
        if (compare(res, mmax) > 0) {
            mmax = res;
        }
        return 1;
    }
    int p = n1.size() - s1 + n2.size() - s2 - k;
    int p1 = -1;
    int p2 = -1;
    for (int i = s1; p >= 0 && i < n1.size(); ++i) {
        if (p1 < 0 || n1[i] > n1[p1]) {
            p1 = i;
            if (n1[p1] == 9) {
                break;
            }
        }
        --p;
    }

    p = n1.size() - s1 + n2.size() - s2 - k;
    for (int i = s2; p >= 0 && i < n2.size(); ++i) {
        if (p2 < 0 || n2[i] > n2[p2]) {
            p2 = i;
            if (n2[p2] == 9) {
                break;
            }
        }
        --p;
    }

    if (p2 < 0 || n1[p1] > n2[p2]) {
        res.push_back(n1[p1]);
        int t = dfs(n1, n2, p1+1, s2, k-1, res, mmax);
        res.pop_back();
        return t;
    } else if (p1 < 0 || n1[p1] < n2[p2]) {
        res.push_back(n2[p2]);
        int t = dfs(n1, n2, s1, p2+1, k-1, res, mmax);
        res.pop_back();
        return t;
    } else {
        vector<int> left;
        vector<int> right;
        res.push_back(n1[p1]);
        int t = dfs(n1, n2, p1+1, s2, k-1, res, mmax);
        res.pop_back();
        left = mmax;

        res.push_back(n2[p2]);
        t = dfs(n1, n2, s1, p2+1, k-1, res, mmax);
        res.pop_back();
        if (compare(left, mmax) > 0) {
            mmax = left;
        }
    }

    return 1;
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> ret;
    vector<int> mmax;
    dfs(nums1, nums2, 0, 0, k, ret, mmax);
    return mmax;
}

int main(int argc, char *argv[]) {
    vector<int> n1 = {3, 4, 6, 5};
    vector<int> n2 = {9, 1, 2, 5, 8, 3};
    // vector<int> n1 = {6,4,7,8,6,5,5,3,1,7,4,9,9,5,9,6,1,7,1,3,6,3,0,8,2,1,8,0,0,7,3,9,3,1,3,7,5,9,4,3,5,8,1,9,5,6,5,7,8,6,6,2,0,9,7,1,2,1,7,0,6,8,5,8,1,6,1,5,8,4};
    // vector<int> n2 = {3,0,0,1,4,3,4,0,8,5,9,1,5,9,4,4,4,8,0,5,5,8,4,9,8,3,1,3,4,8,9,4,9,9,6,6,2,8,9,0,8,0,0,0,1,4,8,9,7,6,2,1,8,7,0,6,4,1,8,1,3,2,4,5,7,7,0,4,8,4};
    // 70
    // vector<int> n1 = {8,5,9,5,1,6,9};
    // vector<int> n2 = {2,6,4,3,8,4,1,0,7,2,9,2,8};

    cout << maxNumber(n1, n2, 5) << endl;
}
