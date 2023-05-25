// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/02/06 11:47:07
// Description: https://leetcode.cn/problems/watering-plants/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int wateringPlants(vector<int>& plants, int capacity) {
	int step = 0;
	int bkt = capacity;
	for (int i = 0; i < plants.size(); ++i) {
		if (bkt >= plants[i]) {
			++step;
			bkt -= plants[i];
		} else {
			step += i + i + 1;
			bkt = capacity - plants[i];
		}
	}
	return step;
}

int main(int argc, char *argv[]) {
	vector<int> p = {1,1,1,4,2,3};
	cout << wateringPlants(p, 4) << endl;
}
