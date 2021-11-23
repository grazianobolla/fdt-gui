#pragma once
#include <string>
#include <vector>
#include <bits/stdc++.h>

bool checkIPv4(std::string s)
{
    // Store the count of occurrence
    // of '.' in the given string
    int cnt = 0;
  
    // Traverse the string s
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.')
            cnt++;
    }
  
    // Not a valid IP address
    if (cnt != 3)
        return false;
  
    // Stores the tokens
    std::vector<std::string> tokens;
  
    // stringstream class check1
    std::stringstream check1(s);
    std::string intermediate;
  
    // Tokenizing w.r.t. '.'
    while (getline(check1,
                   intermediate, '.')) {
        tokens.push_back(intermediate);
    }
  
    if (tokens.size() != 4)
        return false;
  
    // Check if all the tokenized strings
    // lies in the range [0, 255]
    for (int i = 0; i < tokens.size(); i++) {
        int num = 0;
  
        // Base Case
        if (tokens[i] == "0")
            continue;
  
        if (tokens[i].size() == 0)
            return false;
  
        for (int j = 0;
             j < tokens[i].size();
             j++) {
            if (tokens[i][j] > '9'
                || tokens[i][j] < '0')
                return false;
  
            num *= 10;
            num += tokens[i][j] - '0';
  
            if (num == 0)
                return false;
        }
  
        // Range check for num
        if (num > 255 || num < 0)
            return false;
    }
  
    return true;
}