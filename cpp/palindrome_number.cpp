// =====================================================
//       Filename:  palindrome_number.cpp
//         Author:  roboteniac <>
//        Created:  2017/05/22
//    Description:  
//    Copyright (c) 2017, roboteniac, All rights reserved. 
// =====================================================

#include <iostream>

using namespace std;

bool isPalindrome(int x) {
    if (x < 0 || x % 10 == 0)
        return false;
    int half = 0;
    while (x > half) {
        half = half * 10 + x % 10;
        x = x / 10;
    }
    return x == half || half / 10 == x;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    cout << "n = " << n << ", is palindrome: " 
        << (isPalindrome(n) ? "true" : "false") << endl;
}

