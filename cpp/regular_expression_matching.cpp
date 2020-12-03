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

bool match(const char *s, const char *p, int space) {
    // sleep(1);
    // cout << string(space, ' ') << "============================================================\n";
    while (*s && *p) {
        // cout << string(space, ' ') << string(s) << "\n";
        // cout << string(space, ' ') << string(p) << "\n";
        cout << string(s) << "\n";
        cout << string(p) << "\n";
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
                if (match(s++, p, space+1)) {
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

bool match2(const char *s, const char *p) {
    const char *ss = s;
    const char *ps = NULL;
    while (*s && *p) {
        cout << string(s) << "\n" << string(p) << "\n";
        if (*s == *p || *p == '?') {
            ++s;
            ++p;
        } else if (*p == '*') {
            ps = ++p;
            ss = s;
        } else if (ps != NULL) {
            s = ss++;
            p = ps;
        } else {
            return false;
        }
    }
    while (*p == '*') {
        ++p;
    }
    return *p == 0;
}

bool isMatch(string s, string p) {
    return match(s.c_str(), p.c_str(), 0);
}

bool isMatch2(string s, string p) {
    return match2(s.c_str(), p.c_str());
}

int main(int argc, char *argv[]) {
    // string s = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb";
    // string p = "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb";
    string s = argv[1];
    string p = argv[2];
    cout << s << "\n" << p << endl;
    cout << boolalpha << isMatch2(s, p) << endl;
}
