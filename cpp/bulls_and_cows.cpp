// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/04/15 17:14:08
// Description: https://leetcode.com/problems/bulls-and-cows/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "util.h"

using namespace std;

bool inSet(vector<int>& s, int x) {
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == x) {
            return true;
        }
    }
    return false;
}

string getHint(string secret, string guess) {
    int a = 0;
    int b = 0;
    for (int i = 0; i < secret.size(); ++i) {
        if (secret[i] == guess[i]) {
            ++a;
            guess[i] = 'a';
        }
    }
    for (int i = 0; i < secret.size(); ++i) {
        for (int j = 0; j < guess.size(); ++j) {
            if (guess[j] == secret[i]) {
                guess[j] = 'a';
                ++b;
            }
        }
    }
    stringstream ss;
    ss << a << "A" << b << "B";
    return ss.str();
}

int main(int argc, char *argv[]) {
    string secret;
    for (int i = 0; i < 4; ++i) {
        int r  = rand() % 10;
        secret.push_back(r + '0');
    }
    bool ok = false;
    while (!ok) {
        string guess;
        cout << "guess: ";
        cin >> guess;
        if (guess[0] == 'q') {
            cout << secret << "\n";
            break;
        }
        if (guess == secret) {
            cout << "congratulations!\n";
            ok = true;
        } else {
            cout << getHint(secret, guess) << "\n";
        }
    }
}
