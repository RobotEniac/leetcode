#include <iostream>
#include <vector>
#include <deque>

#include "string.hpp"

using namespace std;

#define null 0x0f0f0f0f

int main(int ac, char *av[]) {
    string s(av[1]);
    cout << StringToInt(s) << endl;
}

