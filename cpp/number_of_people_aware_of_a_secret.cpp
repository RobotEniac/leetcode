// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/09/18 11:19:38
// Description: https://leetcode.cn/problems/number-of-people-aware-of-a-secret/description/?envType=daily-question&envId=2025-09-16

#include <iostream>
#include <vector>
#include <string>
#include <queue>

#include "util.h"

using namespace std;
struct Event
{
    int after;
    int action; // add 1, delete 2
};

struct Compare {
    bool operator()(const Event& lhs, const Event &rhs) {
        return lhs.after > rhs.after;
    }
};

int peopleAwareOfSecret(int n, int delay, int forget)
{
    if (forget < delay) {
        return 1;
    }
    int know = 0;
    priority_queue<Event, vector<Event>, Compare> q;
    int cur = 0;

    Event init;
    init.after = 1;
    init.action = 1;
    q.push(init);
    while (!q.empty()) {
        cout << q.size() << endl;
        Event ev = q.top();
        q.pop();
        if (ev.after > n) {
            break;
        }
        if (ev.after > cur) {
            cur = ev.after;
        }
        if (ev.action == 1) {
            know += 1;
            for (int i = delay; i < forget; ++i)
            {
                Event tell;
                tell.after = cur + i;
                tell.action = 1;
                if (tell.after <= n)
                {
                    q.push(tell);
                }
            }
            Event fg;
            fg.after = cur + forget;
            fg.action = 2;
            if (fg.after <= n)
            {
                q.push(fg);
            }
        } else {
            know -= 1;
        }
    }
    return know;
}

int main(int argc, char *argv[]) {
    cout << peopleAwareOfSecret(4, 1, 3) << endl;
}
