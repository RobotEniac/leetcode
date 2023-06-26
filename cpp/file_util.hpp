#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace lc {
std::string ReadAll(const std::string &fname) {
    using namespace std;
    ifstream f(fname);
    if (!f.is_open()) {
        cerr << "file[" << fname << "] is not open\n";
        return "";
    }
    f.seekg(0, f.end);
    int len = f.tellg();
    f.seekg(0, f.beg);
    string ret(len, 0);
    f.read(&ret[0], len);
    if (!f) {
        cerr << "file[" << fname << "] only " << f.gcount() << " could be read\n";
        return "";
    }
    return ret;
}

std::vector<std::string> SplitString(const std::string &str, const std::string &delim) {
    using namespace std;
    vector<string> ret;
    size_t start = 0;
    while (start < str.size()) {
        size_t pos = str.find(delim, start);
        string tmp;
        if (pos == string::npos) {
            tmp = str.substr(start);
            ret.push_back(tmp);
            break;
        } else {
            tmp = str.substr(start, pos - start);
            start = pos + delim.size();
        }
        ret.push_back(tmp);
    }
    return ret;
}

std::string StringTrim(const std::string &str,
                       const std::string& pattern = "\r\n\t ") {
    using namespace std;
    size_t s = str.find_first_not_of(pattern);
    size_t e = str.find_last_not_of(pattern);
    if (s == string::npos && e == string::npos) {
        return str;
    } else if (e == string::npos) {
        return str.substr(s);
    } else {
        return str.substr(s, e-s+1);
    }
}

int32_t StringToInt32(const std::string &s) {
    using namespace std;
    std::string st = StringTrim(s);
    return atoi(st.c_str());
}

std::vector<int> ReadArrayInt(const std::string &fname) {
    std::string content = ReadAll(fname);
    std::vector<std::string> lines = SplitString(content, "\n");
    std::vector<std::string> vs = SplitString(lines[0], ",");
    std::vector<int> ret;
    for (int i = 0; i < vs.size(); ++i) {
        std::string t = StringTrim(vs[i], "\n\r\n[]");
        ret.push_back(StringToInt32(t));
    }
    return ret;
}
}
