// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/02/06 12:01:00
// Description: https://leetcode.cn/problems/minimum-distance-to-type-a-word-using-two-fingers/

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "util.h"

using namespace std;

map<char, vector<int> > kb;

void initKeyboard() {
	int i = 0;
	int j = 0;
	for (int a = 0; a < 26; ++a) {
		char c = 'A' + a;
		vector<int> pos(2, 0);
		pos[0] = a / 6;
		pos[1] = a % 6;
		kb[c] = pos;
	}
}

int distance(char x, char y) {
	if (x == 0 || y == 0) {
		return 0;
	}
	return abs(kb[x][0] - kb[y][0]) + abs(kb[x][1] - kb[y][1]);
}

void dfs(string& s, int i, char f1, char f2, int dist, int &mmin) {
	if (i >= s.size()) {
		if (dist < mmin) {
			mmin = dist;
		}
		return;
	}
	dfs(s, i+1, s[i], f2, dist + distance(s[i], f1), mmin);
	dfs(s, i+1, f1, s[i], dist + distance(s[i], f2), mmin);
}

int minimumDistance(string word) {
	initKeyboard();
	int ret = INT_MAX;
	dfs(word, 0, 0, 0, 0, ret);
	return ret;
}

int main(int argc, char *argv[]) {
	string s("OPVUWZLCKTDPSUKGHAXIDWHLZFKNBDZEWHBSURTVCADUGTSDMCLDBTAGFWDPGXZBVARNTDICHCUJLNFBQOBTDWMGILXPSFWVGYBZVFFKQIDTOVFAPVNSQJULMVIERWAOXCKXBRI");
	cout << minimumDistance(s) << endl;
}
