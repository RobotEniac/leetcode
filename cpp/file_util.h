#pragma once
#include <string>
#include <vector>

namespace leetcode {
    std::string ReadAll(const std::string &fname);

    std::vector<std::string> SplitString(const std::string &str, const std::string &delim);

    std::string StringTrim(const std::string &str, const std::string& pattern = "\r\n\t ");

    int32_t StringToInt32(const std::string &s);
}
