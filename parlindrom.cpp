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

std::string parlindrome(const std::string& str) {
    if (str.empty()){
        return std::string("");
    }
    std::string ret;
    size_t str_len = str.size();
    std::vector<std::vector<bool> >
        memo(str_len + 1, std::vector<bool>(str_len + 1, false));
    int max_par_len = 0;
    for (int i = 0; i < str_len; ++i) {
        memo[i][i] = true;
    }
    int len = 1;
    for (; len < str.size() - 1; ++len) {

    }
    return ret;
}
