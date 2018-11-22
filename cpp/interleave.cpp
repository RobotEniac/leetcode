// =====================================================
//       Filename:  interleave.cpp
//         Author:  wuhaibo <gethaibo@gmail.com>
//        Created:  2017/11/30
//    Description:  
//    Copyright (c) 2017, NONE, All rights reserved. 
// =====================================================

#include <string>
#include <iostream>

using namespace std;

bool isInterleaveInter(const char* s1, const char *s2, const char *s3) {
    if (*s1 == '\0') {
        while (*s2 != '\0' && *s3 != '\0') {
            if (*s2 != *s3) {
                break;
            }
            ++s2;
            ++s3;
        }
        return *s2 == '\0' && *s3 == '\0';
    }
    if (*s2 == '\0') {
        while (*s1 != '\0' && *s3 != '\0') {
            if (*s1 != *s3) {
                break;
            }
            ++s1;
            ++s3;
        }
        return *s1 == '\0' && *s3 == '\0';
    }
    if (*s1 == *s3) {
        if (isInterleaveInter(s1 + 1, s2, s3 + 1)) {
            return true;
        }
    }
    if (*s2 == *s3) {
        if (isInterleaveInter(s1, s2 + 1, s3 + 1)) {
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        cout << "arg number too small\n";
        return 1;
    }
    cout << "s1 = " << argv[1]
        << "\ns2 = " << argv[2]
        << "\ns3 = " << argv[3]
        << "\n isInterleaveInter: " << (isInterleaveInter(argv[1], argv[2], argv[3]) ? "true" : "false") << "\n";
}

