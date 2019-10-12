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
    const char *ps = NULL;
    const char *ss = s;
    while (*s) {
        if (*s == *p || *p == '?') {
            ++s;
            ++p;
        } else if (*p == '*') {
            ss = s;
            ps = p++;
        } else if (ps != NULL) {
            s = ss++;
            p = ps+1;
        } else {
            return false;
        }
    }
    while (*p && *p == '*') {
        ++p;
    }
    return *p == 0;
}

bool isMatch(string s, string p) {
    return match(s.c_str(), p.c_str());
}

int main(int argc, char *argv[]) {
    // string s = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb";
    // string p = "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb";
    string s(argv[1]);
    string p(argv[2]);
    cout << s << "\n" << p << endl;
    cout << boolalpha << isMatch(s, p) << endl;
}
