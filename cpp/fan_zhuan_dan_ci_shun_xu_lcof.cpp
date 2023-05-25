// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/02/06 11:08:03
// Description: https://leetcode.cn/problems/fan-zhuan-dan-ci-shun-xu-lcof/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "util.h"

using namespace std;

vector<string> split(string s) {
    vector<string> r;
    int b = 0;
	while (b < s.size() && s[b] == ' ') {
		++b;
	}
	int p = s.find_first_of(' ', b);
	while (p != string::npos) {
		string t = s.substr(b, p - b);
		r.push_back(t);
		b = p+1;
		while (b < s.size() && s[b] == ' ') {
			++b;
		}
		p = s.find_first_of(' ', b);
	}
	if (b < s.size()) {
		r.push_back(s.substr(b, s.size() - b));
	}
	return r;
}

string reverseWords(string s) {
	vector<string> v = split(s);
	stringstream ss;
	for (int i = v.size() - 1; i >= 0; --i) {
		if (i != v.size() - 1) {
			ss << " ";
		}
		ss << v[i];
	}
	return ss.str();
}

int main(int argc, char *argv[]) {
	string s = "  hello    world!";
	cout << reverseWords(s) << endl;;
}
