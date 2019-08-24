// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/08/24 14:16:27
// Description: https://leetcode.com/problems/regular-expression-matching/

#include <unistd.h>

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

bool match(const char *s, const char *p) {
    cout << string(s) << "\n" << string(p) << endl;
    // sleep(1);
    while (*s && *p) {
        if (*s == *p) {
            ++s;
            ++p;
        } else if (*p == '?') {
            ++s;
            ++p;
        } else if (*p == '*') {
            while (*p == '*') ++p;
            if (*p == 0) {
                return true;
            }
            while (*s != 0) {
                if (match(s++, p)) {
                    return true;
                }
            }
            return false;
        } else {
            return false;
        }
    }
    if (*s == 0 && *p == 0) {
        return true;
    }
    if (*s == 0) {
        while (*p && *p == '*') {
            ++p;
        }
        return *p == 0;
    }
    return false;
}

bool isMatch(string s, string p) {
    return match(s.c_str(), p.c_str());
}

int main(int argc, char *argv[]) {
    string s = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb";
    string p = "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb";
    cout << s << "\n" << p << endl;
    cout << boolalpha << isMatch(s, p) << endl;
}
