// =====================================================
//       Filename:  my_atoi.cpp
//         Author:  roboteniac <>
//        Created:  2017/05/03
//    Description:  
//    Copyright (c) 2017, roboteniac, All rights reserved. 
// =====================================================

#include <string>
#include <iostream>

int myAtoi(const std::string& str) {
    if (str.empty()) {
        return 0;
    }
    int sign = 1;
    int idx = 0;
    while (idx < str.size() && (str[idx] == ' ' || str[idx] == '\t')) ++idx;
    if (str[idx] == '-') {
        sign = -1;
        idx += 1;
    }
    if (str[idx] == '+') {
        sign = 1;
        idx += 1;
    }
    int ret = 0;
    bool overload = false;
    bool has_point = false;
    for (; idx < str.size(); ++idx) {
        if (str[idx] >= '0' && str[idx] <= '9') {
            ret = ret * 10 + str[idx] - '0';
            if (ret < 0) {
                overload = true;
                break;
            }
        } else if (str[idx] == '.') {
            has_point = true;
            break;
        } else {
            break;
        }
    }
    if (overload) {
        if (sign > 0) {
            return INT_MAX;
        }
        return INT_MIN;
    }
    if (has_point) {
        while (idx < str.size() && (str[idx] >= '0' && str[idx] <= '9')) ++idx;
        while (idx < str.size() && (str[idx] == ' ' || str[idx] == '\t')) ++idx;
        if (idx >= str.size()) {
            return ret * sign;
        }
        return 0;
    }
    while (idx < str.size() && (str[idx] == ' ' || str[idx] == '\t')) ++idx;
    if (idx >= str.size()) {
        return ret * sign;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    std::cout << myAtoi(argv[1]) << std::endl;
}

