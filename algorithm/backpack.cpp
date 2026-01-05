// Copyright (c) 2025, Personal Developer
// All rights reserved.
//
// Author: RobotEniac <gethaibo@gmail.com>
// Created: 05/19/25
// Description: https://www.hello-algo.com/chapter_dynamic_programming/knapsack_problem/


#include <vector>
#include <iostream>

using namespace std;

void dfs(vector<int>& w, vector<int>& v, int limit, int i, int value, int &max_value) {
    cout << "limit = " << limit << ", value = " << value << endl;
    if (limit < 0 || i >= w.size()) {
        return;
    }
    if (max_value < value) {
        max_value = value;
    }
    dfs(w, v, limit, i+1, value, max_value);
    dfs(w, v, limit-w[i], i+1, value+v[i], max_value);
}

void dp(vector<int>& w, vector<int>& v, int limit) {

}

int knapsack(vector<int>& weight, vector<int>& values, int limit) {
    int m = 0;
    dfs(weight, values, limit, 0, 0, m);
    return m;
}

int main(int argc, char *argv[]) {
    vector<int> w = {1,2,3,4,5};
    vector<int> v = {5,12,15,21,24};
    cout << knapsack(w, v, 5) << endl;
}
