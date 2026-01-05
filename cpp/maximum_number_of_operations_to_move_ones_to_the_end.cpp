// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/11/13 11:10:10
// Description:
// https://leetcode.cn/problems/maximum-number-of-operations-to-move-ones-to-the-end/description/?envType=daily-question&envId=2025-11-13

#include <iostream>
#include <string>
#include <vector>

#include "util.h"

using namespace std;

int maxOperations(string s) {
  int ones = 0;
  int l = 0;
  int r = 0;
  int ret = 0;
  while (r < s.size()) {
    while (l < s.size() && s[l] == '1') {
      ++l;
      ++ones;
    }
    r = l;
    while (r < s.size() && s[r] == '0') {
      ++r;
    }
    if (l < r) {
      ret += ones;
    }
	l = r;
  }
  return ret;
}

int main(int argc, char *argv[]) { 
    cout << maxOperations("1001101") << endl; 
}
