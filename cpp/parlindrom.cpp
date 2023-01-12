// =====================================================
//       Filename:  parlindrom.cpp
//         Author:  wuhaibo <gethaibo@gmail.com>
//        Created:  2016/04/02
//    Description:
//    Copyright (c) 2016, NONE, All rights reserved.
// =====================================================

#include <iostream>
#include <string>
#include <vector>

using namespace std;

std::string parlindrome(const std::string& str) {
    if (str.empty()){
        return std::string("");
    }
    if (str.size() == 1) {
        return str;
    }
    std::string ret;
    size_t str_len = str.size();
    std::vector<std::vector<bool> >
        memo(str_len + 1, std::vector<bool>(str_len + 1, false));
    int max_par_len = 0;
    for (int i = 0; i < str_len; ++i) {
        memo[i][i] = true;
        memo[i][i+1] = true;
    }
    int max_len = 1;
    int ms = 0;
    int me = 1;
    for (int len = 2; len <= str.size(); ++len) {
        for (int i = 0; i < str_len - 1; ++i) {
            if (memo[i+1][i+len-1] && str[i] == str[i+len-1]) {
                memo[i][i+len] = true;
                if (len > max_len) {
                    max_len = len;
                    ms = i;
                    me = i+len;
                }
            }
        }
    }
    ret = str.substr(ms, max_len);
    return ret;
}

int main(int argc, char *argv[]) {
    std::string s(argv[1]);
    cout << s << endl;
    cout << "parlindrome = " << parlindrome(s) << endl;
}
