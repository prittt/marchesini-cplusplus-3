#include "rimuovi_singoli_spazi.h"
#include <algorithm>

std::string RimuoviSingoliSpazi01(const std::string& input) {
    std::string result;
    
    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i] != ' ') {
            result += input[i];
        } else {
            bool is_prev_space = (i > 0 && input[i - 1] == ' ');
            bool is_next_space = (i < input.size() - 1 && input[i + 1] == ' ');
            
            if (is_prev_space || is_next_space) {
                result += input[i];
            }
        }
    }
    
    return result;
}

std::string RimuoviSingoliSpazi02(const std::string& input) {
    if (input.empty()) {
        return input;
    }
    
    std::string result;
    size_t i = 0;
    
    while (i < input.size()) {
        if (input[i] != ' ') {
            result += input[i];
            i++;
        } else {
            size_t space_count = 0;
            size_t start = i;
            while (i < input.size() && input[i] == ' ') {
                space_count++;
                i++;
            }
            
            if (space_count > 1) {
                result.append(space_count, ' ');
            }
        }
    }
    
    return result;
}

std::string RimuoviSingoliSpazi03(const std::string& input) {
    std::string result;
    
    for (auto it = input.begin(); it != input.end(); ++it) {
        if (*it != ' ') {
            result += *it;
        } else {
            bool has_prev_space = (it != input.begin() && *(it - 1) == ' ');
            bool has_next_space = (it + 1 != input.end() && *(it + 1) == ' ');
            
            if (has_prev_space || has_next_space) {
                result += *it;
            }
        }
    }
    
    return result;
}


// RimuoviSingoliSpazi04: Using std::find_if_not to find sequences of spaces
std::string RimuoviSingoliSpazi04(const std::string& input) {
    std::string result;
    auto it = input.begin();
    
    while (it != input.end()) {
        if (*it != ' ') {
            result += *it;
            ++it;
        } else {
            auto space_start = it;            
            auto space_end = std::find_if_not(it, input.end(), 
                [](char c) { return c == ' '; });
            
            size_t space_count = std::distance(space_start, space_end);
            
            if (space_count > 1) {
                result.append(space_count, ' ');
            }
            
            it = space_end;
        }
    }
    
    return result;
}
