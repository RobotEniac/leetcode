// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2024/01/19 19:01:31
// Description: https://leetcode.cn/problems/html-entity-parser/description/?envType=daily-question&envId=2024-01-17

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

// 双引号：字符实体为 &quot; ，对应的字符是 " 。
// 单引号：字符实体为 &apos; ，对应的字符是 ' 。
// 与符号：字符实体为 &amp; ，对应对的字符是 & 。
// 大于号：字符实体为 &gt; ，对应的字符是 > 。
// 小于号：字符实体为 &lt; ，对应的字符是 < 。
// 斜线号：字符实体为 &frasl; ，对应的字符是 / 。


string entityParser(string text) {
    int i = 0;
    const string& quot("&quot;");
    const string& apos("&apos;");
    const string& amp("&amp;");
    const string& gt("&gt;");
    const string& lt("&lt;");
    const string& frasl("&frasl;");

    const string& quot_r("\"");
    const string& apos_r("\'");
    const string& amp_r("&");
    const string& gt_r(">");
    const string& lt_r("<");
    const string& frasl_r("/");

    while (i < text.size()) {
        if (text[i] == '&') {
            if (text.substr(i, gt.size()) == gt) {
                text.replace(i, gt.size(), gt_r);
            }
            else if (text.substr(i, lt.size()) == lt) {
                text.replace(i, lt.size(), lt_r);
            }
            else if (text.substr(i, amp.size()) == amp) {
                text.replace(i, amp.size(), amp_r);
            }
            else if (text.substr(i, apos.size()) == apos) {
                text.replace(i, apos.size(), apos_r);
            }
            else if (text.substr(i, quot.size()) == quot) {
                text.replace(i, quot.size(), quot_r);
            }
            else if (text.substr(i, frasl.size()) == frasl) {
                text.replace(i, frasl.size(), frasl_r);
            }
        }
        ++i;
    }
    return text;
}

int main(int argc, char *argv[]) {
    string a1("&amp; is an HTML entity but &ambassador; is not.");
    string a2("x &gt; y &amp;&amp; x &lt; y is always false");
    cout << entityParser(a1) << endl;
    cout << entityParser(a2) << endl;
}
