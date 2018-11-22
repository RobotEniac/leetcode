// =====================================================
//       Filename:  big_number.cpp
//         Author:  wuhaibo <gethaibo@gmail.com>
//        Created:  2017/03/03
//    Description:  
//    Copyright (c) 2017, NONE, All rights reserved. 
// =====================================================

#include <stdlib.h>
#include <string.h>

#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> add_int(vector<int>& a, vector<int>& b) {
    if (a.size() == 0)
        return b;
    if (b.size() == 0)
        return a;
    int m = a.size() - 1;
    int n = b.size() - 1;
    vector<int> sum;
    int carry = 0;
    while (m >= 0 && n >= 0) {
        int s = a[m] + b[n] + carry;
        carry = s / 10;
        s = s % 10;
        sum.push_back(s);
        --m;
        --n;
    }
    while (m >= 0) {
        int s = a[m] + carry;
        carry = s / 10;
        s = s % 10;
        sum.push_back(s);
        --m;
    }
    if (carry > 0) {
        sum.push_back(carry);
    }
    for (int i = 0, j = sum.size() - 1; i < j; ++i, --j) {
        int tmp = sum[i];
        sum[i] = sum[j];
        sum[j] = tmp;
    }
    return sum;
}

string add(const string& addend, const string& augend) {
    vector<int> addend_int, augend_int;
    bool first_available = false;
    for (int i = 0; i < addend.size(); ++i) {
        if (addend[i] > '9' || addend[i] < '0') {
            return "";
        }
        if (!first_available && addend[i] == '0')
            continue;
        first_available = true;
        addend_int.push_back(addend[i] - '0');
    }

    first_available = false;
    for (int i = 0; i < augend.size(); ++i) {
        if (augend[i] > '9' || augend[i] < '0') {
            return "";
        }
        if (!first_available && augend[i] == '0')
            continue;
        first_available = true;
        augend_int.push_back(augend[i] - '0');
    }
    vector<int> sum;
    if (addend_int.size() > augend_int.size()) {
        sum = add_int(addend_int, augend_int);
    } else {
        sum = add_int(augend_int, addend_int);
    }
    string ret;
    for (int i = 0; i < sum.size(); ++i) {
        ret.push_back(sum[i] + '0');
    }
    return ret;
}

string mul_one_bit(const string& a, char one_bit) {
    int n = one_bit - '0';
    string sum = "0";
    for (int i = 0; i < n; ++i) {
        sum = add(sum, a);
    }
    return sum;
}

string mul(const string& a, const string& b) {
    string sum("0");
    for (int i = 0; i < b.size(); ++i) {
        string res = mul_one_bit(a, b[i]);
        sum.push_back('0');
        sum = add(sum, res);
    }
    return sum;
}

string desc(const string& n) {
    if (n == "1") {
        return "0";
    }
    string res;
    int carry = 1;
    int curr = n.size() - 1;
    while (curr >= 0) {
        int a = n[curr] - '0' - carry;
        if (a < 0) {
            carry = 1;
            a = a + 10;
        } else {
            carry = 0;
        }
        res.push_back(a + '0');
        --curr;
    }
    int len = res.size() - 1;
    while (res[len] == '0') --len;
    res = res.substr(0, len + 1);
    for (int i = 0, j = res.size() - 1; i < j; ++i, --j) {
        int tmp = res[i];
        res[i] = res[j];
        res[j] = tmp;
    }
    return res;
}

string f(const string& n) {
    if (n == "0") {
        return "1";
    }
    if (n == "1") {
        return "1";
    }
    return mul(n, f(desc(n)));
}

int f_int(int n) {
    if (n < 2) {
        return 1;
    }
    return n * f_int(n - 1);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "usage " << argv[0] << " n";
        return 1;
    }
    string n(argv[1]);
    cout << f(n) << endl;
    cout << f_int(atoi(n.c_str())) << endl;
}

