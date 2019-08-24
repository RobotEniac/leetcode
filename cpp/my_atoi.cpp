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

int myAtoi2(const std::string& str) {
    if (str.empty()) {
        return 0;
    }
    enum Status {
        START,
        SIGN_PARSED,
        NUM
    };

    Status st = START;
    int64_t sign = 1;
    int64_t res = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == ' ' || str[i] == '\t') {
            if (st == START) {
                continue;
            } else if (st == SIGN_PARSED) {
                return 0;
            } else if (st == NUM) {
                break;
            }
        }
        if (str[i] == '-') {
            if (st == START) {
                sign = -1;
                st = SIGN_PARSED;
            } else {
                break;
            }
        } else if (str[i] == '+') {
            if (st == START) {
                sign = 1;
                st = SIGN_PARSED;
            } else {
                break;
            }
        } else if (str[i] >= '0' && str[i] <= '9') {
            if (st == START) {
                sign = 1;
                res = str[i] - '0';
                st = NUM;
            } else if (st == SIGN_PARSED) {
                res = str[i] - '0';
                st = NUM;
            } else if (st == NUM) {
                res = res * 10 + (str[i] - '0');
                int64_t t = res * sign;
                if (t >= INT_MAX) {
                    return INT_MAX;
                }
                if (t <= INT_MIN) {
                    return INT_MIN;
                }
            }
        } else {
            break;
        }
    }
    return (int)(sign * res);
}

int main(int argc, char *argv[]) {
    std::cout << myAtoi2(argv[1]) << std::endl;
}

