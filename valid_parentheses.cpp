// =====================================================
//       Filename:  valid_parentheses.cpp
//         Author:  wuhaibo <gethaibo@gmail.com>
//        Created:  2017/02/14
//    Description:
//    Copyright (c) 2017, NONE, All rights reserved.
// =====================================================

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s) {
    if (s.empty()) {
        return true;
    }
    stack<char> st;
    st.push('#');
    char c, back;
    for (size_t i = 0; i < s.size(); ++i) {
        switch(c = s[i]) {
            case '(':
            case '[':
            case '{':
                st.push(c);
                break;
            case ')':
                back = st.top();
                st.pop();
                if (back != '(') return false;
                break;
            case ']':
                back = st.top();
                st.pop();
                if (back != '[') return false;
                break;
            case '}':
                back = st.top();
                st.pop();
                if (back != '{') return false;
                break;
        }
    }
    return st.top() == '#';
}

int longestValidParentheses(string s) {
    if (s.size() < 2) {
        return s.size();
    }
    stack<int> idx_stk;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            idx_stk.push(i);
        } else if (s[i] == ')') {
            if (!idx_stk.empty()) {
                int j = idx_stk.top();
                if (s[j] == '(') {
                    idx_stk.pop();
                } else {
                    idx_stk.push(i);
                }
            } else {
                idx_stk.push(i);
            }
        }
    }
    if (idx_stk.empty()) {
        return s.size();
    }
    int max_len = 0;
    int end = s.size();
    while (!idx_stk.empty()) {
        if (end - idx_stk.top() - 1 > max_len)
            max_len = end - idx_stk.top() - 1;
        end = idx_stk.top();
        idx_stk.pop();
    }
    if (end > max_len)
        max_len = end;
    return max_len;
}

int main(void) {
    const int N = 4;
    string s[N];
    s[0] = "(()";
    s[1] = "((((((";
    s[2] = "(()()";
    s[3] = ")()())";
    for (int i = 0; i < N; ++i) {
        cout << s[i] << "\n";
        cout << longestValidParentheses(s[i]) << "\n";
    }
}

