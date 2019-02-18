// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/02/06
// Description: 

#include <vector>
#include <string>
#include <iostream>
#include "util.h"

using namespace std;

class MinStack {
public:
    MinStack() {
    }

    void push(int x) {
        if (s_.empty()) {
            s_.push_back(x);
            min_s_.push_back(x);
        } else if (x > min_s_.back()) {
            s_.push_back(x);
        } else if (x <= min_s_.back()) {
            min_s_.push_back(x);
            s_.push_back(x);
        }
    }

    void pop() {
        if (s_.back() <= min_s_.back()) {
            min_s_.pop_back();
        }
        s_.pop_back();
    }

    int top() {
        if (s_.empty()) {
            return -1;
        }
        return s_.back();
    }

    int getMin() {
        if (min_s_.empty()) {
            return -1;
        }
        return min_s_.back();
    }

    void Show() {
        std::cout << s_ << std::endl;
        std::cout << min_s_ << std::endl;
    }

private:
    vector<int> s_;
    vector<int> min_s_;
};

int main(int argc, char *argv[]) {
    MinStack ms;
    srand(12345);
    for (int i = 0; i < 10; ++i) {
        ms.push(rand() % 10);
    }
    ms.Show();
    for (int i = 0; i < 10; ++i) {
        std::cout << i << ":\n";
        std::cout << "top = " << ms.top() << ", min = " << ms.getMin() << std::endl;
        ms.pop();
        if (i % 2 == 0) {
            ms.Show();
        }
    }
}

