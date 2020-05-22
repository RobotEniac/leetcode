#include <stdlib.h>

#include <string>
#include <vector>

std::string TrimString(const std::string &str, const std::string &delim) {
    size_t s = str.find_first_not_of(delim);
    if (s == std::string::npos) {
        return std::string("");
    }
    size_t e = str.find_last_not_of(delim);
    return str.substr(s, e + 1 - s);
}

std::vector<std::string> SplitString(const std::string &str, const std::string &delim) {
    std::vector<std::string> ret;
    if (str.empty()) {
        return ret;
    }
    if (str.find(delim) == std::string::npos) {
        ret.push_back(str);
        return ret;
    }
    std::vector<std::string> &res_ref = ret;
    std::string::size_type start = 0;
    std::string::size_type end = 0;;
    while (start < str.size()) {
        end = str.find(delim, start);
        if (end == std::string::npos) {
            res_ref.push_back(str.substr(start));
            start = str.size();
        }
        else {
            std::string tmp = str.substr(start, end - start);
            if (!tmp.empty()) {
                res_ref.push_back(tmp);
            }
            start = end + delim.size();
        }
    }
    return ret;
}

int32_t StringToInt(const std::string &s) {
    const char *sptr = s.c_str();
    char *end = NULL;
    int64_t l = ::strtol(sptr, &end, 10);
    return (int32_t)l;
}

