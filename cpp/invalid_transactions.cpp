// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2022/10/31 15:49:21
// Description: https://leetcode.cn/problems/invalid-transactions/

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <sstream>

#include "util.h"

using namespace std;

int toNum(const string &s) {
    return atoi(s.c_str());
}

int sub(const string &l, const string& r) {
    int x = toNum(l) - toNum(r);
    if (x < 0) {
        return -x;
    }
    return x;
}

void show(map<string, vector<int> > &m) {
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it != m.begin()) {
            cout << ", ";
        }
        cout << it->first << "->[";
        for (auto jt = it->second.begin(); jt != it->second.end(); ++jt) {
            if (jt != it->second.begin()) {
                cout << ",";
            }
            cout << *jt;
        }
        cout << "]";
    }
    cout << endl;
}

vector<string> SplitString(const string& s) {
    size_t start = 0;
    size_t pos = s.find_first_of(",", start);
    vector<string> ret;
    while (pos != string::npos) {
        ret.push_back(s.substr(start, pos - start));
        start = pos+1;
        pos = s.find_first_of(",", start);
    }
    ret.push_back(s.substr(start));
    return ret;
}

// "{name},{time},{amount},{city}"
vector<string> invalidTransactions(vector<string>& transactions) {
    set<int> rs;
    map<string, vector<int> > m;
    for (int i = 0; i < transactions.size(); ++i) {
        vector<string> t = SplitString(transactions[i]);
        int amount = toNum(t[2]);
        if (amount > 1000) {
            rs.insert(i);
        }
        auto it = m.find(t[0]);
        if (it != m.end()) {
            vector<int> &tr = it->second;
            for (int j = 0; j < tr.size(); ++j) {
                vector<string> vs = SplitString(transactions[tr[j]]);
                if (vs[3] != t[3]
                    && sub(vs[1], t[1]) < 60) {
                    // cout << "insert " << i << ", " << tr[j] << endl;
                    rs.insert(tr[j]);
                    rs.insert(i);
                }
            }
            tr.push_back(i);
        } else {
            m[t[0]] = vector<int>(1, i);
        }
        show(m);
    }
    vector<string> ret;
    for (auto it = rs.begin(); it != rs.end(); ++it) {
        ret.push_back(transactions[*it]);
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<string> tr = {"bob,55,173,barcelona","lee,113,952,zurich","maybe,115,1973,madrid","chalicefy,229,283,istanbul","bob,24,874,shanghai","alex,568,412,tokyo","alex,242,1710,milan","iris,722,879,shenzhen","chalicefy,281,1586,warsaw","maybe,246,778,bangkok","xnova,605,166,newdelhi","iris,631,991,hongkong","chalicefy,500,620,tokyo","chalicefy,380,428,istanbul","iris,905,180,barcelona","alex,810,732,shenzhen","iris,689,389,paris","xnova,475,298,singapore","lee,58,709,amsterdam","xnova,717,546,guangzhou","maybe,78,435,shenzhen","maybe,333,145,hongkong","lee,405,1230,hongkong","lee,456,1440,tokyo","chalicefy,286,1071,amsterdam","alex,55,271,shanghai","bob,91,273,warsaw","iris,195,1825,tokyo","maybe,639,417,madrid","maybe,305,882,chicago","lee,443,47,chicago","chalicefy,958,840,budapest","lee,162,1239,budapest","bob,701,505,montreal","alex,52,1575,munich","bob,533,1407,amsterdam","lee,621,491,tokyo","chalicefy,866,622,rome","alex,925,455,hongkong","lee,968,164,moscow","chalicefy,31,1119,newdelhi","iris,527,700,warsaw","bob,286,1694,dubai","maybe,903,29,barcelona","maybe,474,1606,prague","maybe,851,648,beijing","lee,48,655,chicago","maybe,378,25,toronto","lee,922,691,munich","maybe,411,903,taipei","lee,651,112,guangzhou","lee,664,506,dubai","chalicefy,704,924,milan","maybe,333,1264,budapest","chalicefy,587,1112,singapore","maybe,428,437,moscow","lee,721,366,newdelhi","iris,824,1962,beijing","chalicefy,834,489,istanbul","alex,639,1473,zurich","xnova,898,738,tokyo","chalicefy,585,1313,frankfurt","xnova,730,759,beijing","alex,69,892,montreal","lee,77,91,barcelona","lee,722,611,taipei","chalicefy,706,1982,jakarta","chalicefy,743,584,luxembourg","xnova,683,322,istanbul","chalicefy,60,861,prague","alex,366,871,shenzhen","chalicefy,77,870,shenzhen","iris,913,1501,warsaw","iris,846,1176,warsaw","bob,873,69,zurich","alex,601,181,chicago","chalicefy,118,145,hongkong","bob,879,982,montreal","lee,994,950,chicago","maybe,885,1900,shanghai","lee,717,1447,shanghai","chalicefy,71,434,istanbul","bob,870,968,toronto","maybe,718,51,beijing","alex,669,896,istanbul","chalicefy,639,506,rome","alex,594,934,frankfurt","maybe,3,89,jakarta","xnova,328,1710,rome","alex,611,571,chicago","chalicefy,31,458,montreal","iris,973,696,toronto","iris,863,148,rome","chalicefy,926,511,warsaw","alex,218,1411,zurich","chalicefy,544,1296,shenzhen","iris,27,23,montreal","chalicefy,295,263,prague","maybe,575,31,munich","alex,215,174,prague"};
    cout << tr << endl;
    cout << invalidTransactions(tr) << endl;
}
