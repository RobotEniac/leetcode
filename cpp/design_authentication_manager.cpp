// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/04/08 12:01:09
// Description: https://leetcode-cn.com/problems/design-authentication-manager/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

#include "util.h"

using namespace std;

class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive)
        : ttl_(timeToLive)
    {
    }

    void generate(string tokenId, int currentTime) {
        Token t;
        std::stringstream ss;
        t.id = tokenId;
        t.exp_time = currentTime + ttl_;
        ss << tokenId << "_" << currentTime;
        t.code = std::hash<std::string>()(ss.str());
        cache_[t.id] = t;
    }

    void renew(string tokenId, int currentTime) {
        auto it = cache_.find(tokenId);
        std::stringstream ss;
        if (it == cache_.end()) {
            return;
        }
        if (it->second.exp_time <= currentTime) {
            return;
        }
        ss << tokenId << "_" << currentTime;
        it->second.code = std::hash<std::string>()(ss.str());
        it->second.exp_time = currentTime + ttl_;
    }

    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for (auto it = cache_.begin(); it != cache_.end(); ++it) {
            if (it->second.exp_time > currentTime) {
                ++count;
            }
        }
        return count;
    }

private:
    struct Token {
        string id;
        uint64_t exp_time;
        size_t code;
    };

private:
    int ttl_;
    std::map<string, Token> cache_;
};

int main(int argc, char *argv[]) {
    cout << "hello world" << endl;
}
