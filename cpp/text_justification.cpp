// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/07/23 14:33:17
// Description: https://leetcode.com/problems/text-justification/

#include <sstream>
#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int ceiling(double f) {
    if (f - (double)(int)f < 0.0000001) {
        return (int)f;
    }
    return (int)(f + 1);
}

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int line_len = 0;
    int line_words_len = 0;
    int line_start = 0;
    vector<string> ret;
    for (int i = 0; i < words.size(); ++i) {
        int tmp_len = (line_len == 0) ? words[i].size() : (line_len + 1 + words[i].size());
        if (tmp_len < maxWidth) {
            line_len = tmp_len;
            line_words_len += words[i].size();
        } else if (tmp_len == maxWidth) {
            stringstream ss;
            for (int j = line_start; j <= i; ++j) {
                if (j != line_start) {
                    ss << ' ';
                }
                ss << words[j];
            }
            ret.push_back(ss.str());
            line_start = i + 1;
            line_len = 0;
            line_words_len = 0;
        } else {
            int space_len = maxWidth - line_words_len;
            stringstream ss;
            if (i - line_start == 1) {
                ss << words[line_start];
                ss << string(space_len, ' ');
            } else {
                for (int j = line_start; j < i; ++j) {
                    if (j != line_start) {
                        string sp(ceiling((double)space_len / (i - j)), ' ');
                        ss << sp;
                        space_len -= sp.size();
                    }
                    ss << words[j];
                }
            }
            ret.push_back(ss.str());
            line_start = i;
            line_len = words[i].size();
            line_words_len = words[i].size();
        }
    }
    stringstream ss;
    for (int j = line_start; j < words.size(); ++j) {
        if (j != line_start) {
            ss << ' ';
        }
        ss << words[j];
    }
    if (!ss.str().empty()) {
        int last_line_size = ss.str().size();
        ss << string(maxWidth - last_line_size, '_');
        ret.push_back(ss.str());
    }
    return ret;
}

void show(const vector<string> &v) {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << "\n";
    }
}

int main(int argc, char *argv[]) {
    // vector<string> v = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    vector<string> v = {"This", "is", "an", "example", "of", "text", "justification."};
    show(fullJustify(v, 16));
}
