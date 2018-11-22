// =====================================================
//       Filename:  length_of_longest_substring.cpp
//         Author:  wuhaibo <gethaibo@gmail.com>
//        Created:  2015/12/25
//    Description:  
//    Copyright (c) 2015, NONE, All rights reserved. 
// =====================================================

#include <iostream>
#include <string>
#include <unordered_map>

int lengthOfLongestSubstring(std::string s) {
    std::unordered_map<char, size_t> char_map;
    size_t start = 0;
    int temp_len, max_len;
    temp_len = max_len = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (char_map.find(s[i]) == char_map.end()) {
            ++temp_len;
            char_map[s[i]] = i;
            if (temp_len > max_len) {
                max_len = temp_len;
            }
        } else {
            size_t pos = char_map[s[i]];
            for (; start < pos; ++start) {
                char_map.erase(s[start]);
            }
            start = pos + 1;
            temp_len = i - start + 1;
            char_map[s[i]] = i;
        }
    }
    return max_len;
}

int main(int argc, char* argv[]) {
    std::string s(argv[1]);
    std::cout << "longest substring length = " << lengthOfLongestSubstring(s) << "\n";
    std::cout << "hello world\n";
}
