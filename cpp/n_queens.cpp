// =====================================================
//       Filename:  n_queens.cpp
//         Author:  wuhaibo <gethaibo@gmail.com>
//        Created:  2017/07/06
//    Description:  
//    Copyright (c) 2017, NONE, All rights reserved. 
// =====================================================

#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>
string vector2string(const vector<T> &v) {
    stringstream ss;
    ss << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i > 0)
            ss << ",";
        ss << v[i];
    }
    ss << "]";
    return ss.str();
}

void solve(int n, vector<string>& board, vector<vector<string> >& res) {
    for (int i = 0; i < board[n].size(); ++i) {
        board[n][i] = 'Q';
        bool available = true;
        for (int j = n + 1; j < board.size(); ++j) {
            if (board[j][i] == 'Q') {
                available = false;
                break;
            }
            if (i - j + n >= 0
                    && board[j][i - j + n] == 'Q') {
                available = false;
                break;
            }
            if (i + j - n < board[n].size()
                    && board[j][i + j - n] == 'Q') {
                available = false;
                break;
            }
        }
        if (available) {
            if (n == 0) {
                res.push_back(vector<string>(board));
            } else {
                solve(n - 1, board, res);
            }
        }
        board[n][i] = '.';
    }
}

vector<vector<string> > NQueen(int n) {
    vector<string> board(n, string(n, '.'));
    vector<vector<string> > res;
    solve(n - 1, board, res);
    return res;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    vector<vector<string> > res = NQueen(n);
    for (size_t i = 0; i < res.size(); ++i) {
        cout << "====" << i+1 << "====\n";
        for (size_t j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << "\n";
        }
    }
}

