// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/04/02 18:32:50
// Description: https://leetcode-cn.com/problems/remove-comments/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

vector<string> removeComments(vector<string>& source) {
    vector<string> ret;
    enum Stat {
        STAR_BEGIN,
        STAR_END
    };
    Stat st = STAR_END;
    for (int i = 0; i < source.size(); ++i) {
        std::string line = source[i];
        if (st == STAR_END) {
            size_t pos1 = line.find("//");
            size_t pos2 = line.find("/*");
            if (pos1 == string::npos && pos2 == string::npos) {
                ret.push_back(line);
            } else if (pos2 == string::npos || pos1 < pos2) {
                if (pos1 != 0) {
                    ret.push_back(line.substr(0, pos1));
                }
            } else if (pos1 == string::npos || pos2 < pos1) {
                ret.push_back(line.substr(0, pos2));
                size_t pos3 = line.find("*/", pos2+2);
                if (pos3 == string::npos) {
                    st = STAR_BEGIN;
                } else {
                    if (pos3 + 2 >= line.size()) {
                        if (ret.back().empty()) {
                            ret.pop_back();
                        }
                    } else {
                        ret[ret.size() - 1] += line.substr(pos3+2);
                    }
                }
            }
        } else {
            size_t pos = line.find("*/");
            if (pos != string::npos) {
                if (pos + 2 >= line.size()) {
                    if (ret.back().empty()) {
                        ret.pop_back();
                    }
                } else {
                    string tmp = ret.back() + line.substr(pos+2);
                    ret.pop_back();
                    source[i] = tmp;
                    --i;
                }
                st = STAR_END;
            }
        }
    }
    return ret;
}

void print(const vector<string> &source) {
    for (int i = 0; i < source.size(); ++i) {
        if (i != 0) {
            cout << "\n";
        }
        cout << source[i] << "\n";
    }
}

int main(int argc, char *argv[]) {
    vector<string> source = {"a/*/b//*c","blank","d/*/e*//f"};
    print(source);
    cout << "================================================================================\n";
    print(removeComments(source));
}
