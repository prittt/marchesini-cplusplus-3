#ifndef NODUP_H
#define NODUP_H

#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>

// Nodup01: Using unordered_set (preserves order of first occurrence)
// Time Complexity: O(n) average
// Space Complexity: O(n)
template<typename T>
std::vector<T> Nodup01(const std::vector<T>& v_in) {
    std::unordered_set<T> seen;
    std::vector<T> v_out;
    
    for (const T& elem : v_in) {
        if (seen.find(elem) == seen.end()) {
            seen.insert(elem);
            v_out.push_back(elem);
        }
    }
    
    return v_out;
}

// Nodup02: Using unordered_set with insert().second
// Time Complexity: O(n) average
// Space Complexity: O(n)
template<typename T>
std::vector<T> Nodup02(const std::vector<T>& v_in) {
    std::unordered_set<T> seen;
    std::vector<T> v_out;
    
    for (const T& elem : v_in) {
        if (seen.insert(elem).second) {
            v_out.push_back(elem);
        }
    }
    
    return v_out;
}

// Nodup03: Using set (sorted output, no order preserved)
// Time Complexity: O(n log n)
// Space Complexity: O(n)
template<typename T>
std::vector<T> Nodup03(const std::vector<T>& v_in) {
    std::set<T> unique_set(v_in.begin(), v_in.end());
    return std::vector<T>(unique_set.begin(), unique_set.end());
}

// Nodup04: Using std::sort and std::unique (modifies order)
// Time Complexity: O(n log n)
// Space Complexity: O(1) additional space (in-place sort)
template<typename T>
std::vector<T> Nodup04(std::vector<T> v_in) {
    std::sort(v_in.begin(), v_in.end());
    auto last = std::unique(v_in.begin(), v_in.end());
    v_in.erase(last, v_in.end());
    return v_in;
}

// 1 3 4 5 3 6
// 1 3 4 5 6 ?

// Nodup05: Manual nested loop
// Time Complexity: O(n²)
// Space Complexity: O(n)
template<typename T>
std::vector<T> Nodup05(const std::vector<T>& v_in) {
    std::vector<T> v_out;
    
    for (const T& elem : v_in) {
        bool found = false;
        for (const T& existing : v_out) {
            if (elem == existing) {
                found = true;
                break;
            }
        }
        if (!found) {
            v_out.push_back(elem);
        }
    }
    
    return v_out;
}

// Nodup06: Using std::find
// Time Complexity: O(n²)
// Space Complexity: O(n)
template<typename T>
std::vector<T> Nodup06(const std::vector<T>& v_in) {
    std::vector<T> v_out;
    
    for (const T& elem : v_in) {
        if (std::find(v_out.begin(), v_out.end(), elem) == v_out.end()) {
            v_out.push_back(elem);
        }
    }
    
    return v_out;
}

#endif // NODUP_H
