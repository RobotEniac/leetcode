// =====================================================
//       Filename:  is_bad_version.cpp
//         Author:  wuhaibo <gethaibo@gmail.com>
//        Created:  2017/11/30
//    Description:  
//    Copyright (c) 2017, NONE, All rights reserved. 
// =====================================================

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class SVNRepo {
    public:
        static int bad;
        static bool isBadVersion(int k) {
            return k >= bad;
        }
};

int SVNRepo::bad = 5;

int binarySearch(int s, int e) {
    if (s >= e) {
        return e;
    }
    int mid = (s + e) / 2;
    if (SVNRepo::isBadVersion(mid)) {
        if (mid == s || !SVNRepo::isBadVersion(mid - 1)) {
            return mid;
        }
        return binarySearch(s, mid - 1);
    } else {
        return binarySearch(mid + 1, e);
    }
}

int findFirstBadVersion(int n) {
    return binarySearch(1, n);
}

int main(int argc, char *argv[]) {
    SVNRepo::bad = atoi(argv[1]);
    int n = atoi(argv[2]);
    cout << findFirstBadVersion(n) << endl;
}

