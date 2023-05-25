// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/02/06 11:19:34
// Description: https://leetcode.cn/problems/sort-array-by-increasing-frequency/

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "util.h"

using namespace std;

vector<int> frequencySort(vector<int>& nums) {
	vector<int> r(nums.begin(), nums.end());
	map<int, int> m;
	for (int i = 0; i < nums.size(); ++i) {
		if (m.find(nums[i]) == m.end()) {
			m[nums[i]] = 1;
		} else {
			m[nums[i]]++;
		}
	}
	auto fun = [&](int i, int j) -> bool {
		if (m[i] < m[j]) {
			return true;
		} else if (m[i] == m[j]) {
			return i > j;
		} else {
			return false;
		}
	};
	sort(r.begin(), r.end(), fun);
	return r;
}

int main(int argc, char *argv[]) {
	vector<int> a = {-1,1,-6,4,5,-6,1,4,1};
	cout << frequencySort(a) << endl;
}
