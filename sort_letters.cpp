// =====================================================
//       Filename:  sort_letters.cpp
//         Author:  wuhaibo <gethaibo@gmail.com>
//        Created:  2017/11/30
//    Description:  
//    Copyright (c) 2017, NONE, All rights reserved. 
// =====================================================

#include <string>
#include <iostream>

using namespace std;

bool isSmall(char c) {
    return c >= 'a' && c <= 'z';
}

void sortLetters(string &chars) {
    if (chars.size() < 2) {
        return;
    }
    int left = 0;
    int right = 0;
    while (right < chars.size()) {
        if (isSmall(chars[right])) {
            char t = chars[left];
            chars[left] = chars[right];
            chars[right] = t;
            ++left;
        }
        ++right;
    }
}

int main(int argc, char *argv[]) {
    string s(argv[1]);
    cout << s << endl;
    sortLetters(s);
    cout << s << endl;
}

