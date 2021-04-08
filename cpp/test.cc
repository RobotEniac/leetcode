// Copyright (c) 2021, Personal Developer
// All rights reserved.
//
// Author: RobotEniac <gethaibo@gmail.com>
// Created: 04/02/21
// Description:

#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[]) {
    string s("abc");
    size_t pos1 = s.find('a');
    size_t pos2 = s.find('d');
    cout << pos1 << ", " << pos2 << "\n";
}

