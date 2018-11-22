// =====================================================
//       Filename:  divide.cpp
//         Author:  wuhaibo <gethaibo@gmail.com>
//        Created:  2017/02/17
//    Description:  
//    Copyright (c) 2017, NONE, All rights reserved. 
// =====================================================

#include <iostream>

using namespace std;

inline int abs(int a) {
    return a > 0 ? a : -a;
}

int divide(int dividend, int divisor) {
    return 0;
}

int multiply(int a, int b) {
    int sign = ((a < 0) ^ (b < 0)) ? -1 : 1;
    cout << sign << endl;
    int sum = 0;
    int i = 0;
    a = abs(a);
    b = abs(b);
    while (b > 0) {
        if (b & 1) {
            sum += (a << i);
        }
        ++i;
        b = b >> 1;
    }
    return sign > 0 ? sum : -sum;
}

int main(int argc, char *argv[]) {
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    cout << a << " * " << b << " = " << multiply(a, b) << endl;
}

