// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/04/24 16:28:48
// Description: https://leetcode.com/problems/peeking-iterator/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

class Iterator {
    public:
        Iterator(const vector<int>& nums);
        Iterator(const Iterator& iter);
        virtual ~Iterator();
        // Returns the next element in the iteration.
        int next();
        // Returns true if the iteration has more elements.
        bool hasNext() const;
};


class PeekingIterator : public Iterator {
    public:
        PeekingIterator(const vector<int>& nums) : 
            Iterator(nums),
            a_(nums),
            pos_(0) 
        {
                // Initialize any member here.
                // **DO NOT** save a copy of nums and manipulate it directly.
                // You should only use the Iterator interface methods.

        }

        // Returns the next element in the iteration without advancing the iterator.
        int peek() {
            if (pos_ < a_.size()) {
                return a_[pos_];
            }
            return a_[a_.size() - 1];
        }

        // hasNext() and next() should behave the same as in the Iterator interface.
        // Override them if needed.
        int next() {
            if (pos_ < a_.size()) {
                return a_[pos_++];
            }
            return a_[a_.size() - 1];
        }

        bool hasNext() const {
            return pos_ < a_.size();
        }
    private:
        const vector<int> &a_;
        size_t pos_;
};

int main(int argc, char *argv[]) {
    cout << "hello world" << endl;
}
