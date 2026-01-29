#include "formato.h"
#include <cctype>
#include <regex>

// VerificaFormatoData01: Manual character checking
// Approach: Check each position character by character
bool VerificaFormatoData01(const std::string& data) {
    // Check length
    if (data.size() != 10) {
        return false;
    }
    
    // Check format: DD/MM/YYYY
    // Positions 0,1 must be digits (day)
    if (!std::isdigit(data[0]) || !std::isdigit(data[1])) {
        return false;
    }
    
    // Position 2 must be '/'
    if (data[2] != '/') {
        return false;
    }
    
    // Positions 3,4 must be digits (month)
    if (!std::isdigit(data[3]) || !std::isdigit(data[4])) {
        return false;
    }
    
    // Position 5 must be '/'
    if (data[5] != '/') {
        return false;
    }
    
    // Positions 6,7,8,9 must be digits (year)
    if (!std::isdigit(data[6]) || !std::isdigit(data[7]) || 
        !std::isdigit(data[8]) || !std::isdigit(data[9])) {
        return false;
    }
    
    return true;
}

// VerificaFormatoData02: Using regex
// Approach: Regular expression pattern matching
bool VerificaFormatoData02(const std::string& data) {
    std::regex pattern("\\d{2}/\\d{2}/\\d{4}");
    return std::regex_match(data, pattern);
}

// VerificaFormatoData03: Loop-based checking
// Approach: Iterate and validate each section
bool VerificaFormatoData03(const std::string& data) {
    if (data.size() != 10) {
        return false;
    }
    
    // Check day (positions 0-1)
    for (int i = 0; i < 2; ++i) {
        if (!std::isdigit(data[i])) {
            return false;
        }
    }
    
    // Check first separator
    if (data[2] != '/') {
        return false;
    }
    
    // Check month (positions 3-4)
    for (int i = 3; i < 5; ++i) {
        if (!std::isdigit(data[i])) {
            return false;
        }
    }
    
    // Check second separator
    if (data[5] != '/') {
        return false;
    }
    
    // Check year (positions 6-9)
    for (int i = 6; i < 10; ++i) {
        if (!std::isdigit(data[i])) {
            return false;
        }
    }
    
    return true;
}

// VerificaFormatoData04: Using string operations
// Approach: Split by separator and validate parts
bool VerificaFormatoData04(const std::string& data) {
    if (data.size() != 10) {
        return false;
    }
    
    // Find separator positions
    size_t first_slash = data.find('/');
    size_t last_slash = data.rfind('/');
    
    // Check separator positions
    if (first_slash != 2 || last_slash != 5) {
        return false;
    }
    
    // Extract parts
    std::string day = data.substr(0, 2);
    std::string month = data.substr(3, 2);
    std::string year = data.substr(6, 4);
    
    // Validate each part contains only digits
    auto all_digits = [](const std::string& s) {
        for (char c : s) {
            if (!std::isdigit(c)) {
                return false;
            }
        }
        return true;
    };
    
    return all_digits(day) && all_digits(month) && all_digits(year);
}
