// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/11/17 21:05:39
// Description: https://leetcode.cn/problems/valid-word/?envType=daily-question&envId=2025-11-17

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

bool isValid(string word) {
    if (word.size() < 3) {
        return false;
    }
    bool a = false;
    bool b = false;
    for (int i = 0; i < word.size(); ++i)
    {
        if (word[i] >= 'a' && word[i] <= 'z' || word[i] >= 'A' && word[i] <= 'Z')
        {
            switch (word[i])
            {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                a = true;
                break;
            default:
                b = true;
                break;
            }
        } else if (word[i] >= '0' && word[i] <= '9') {
            continue;
        } else {
            return false;
        }
    }
    return a && b;
}

int main(int argc, char *argv[]) {
    cout << isValid("UuE6") << endl;
}
