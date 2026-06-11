#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <regex>

class Solution {
public:
    static int findTheLongestBalancedSubstring(const std::string& s) {
        std::unordered_map<int, int> map;
        map[0] = -1;
        
        int maxLen = 0;
        int runningSum = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                runningSum += -1;
            } else {
                runningSum += 1;
            }
            
            if (map.find(runningSum) != map.end()) {
                int previousIndex = map[runningSum];
                maxLen = std::max(maxLen, i - previousIndex);
            } else {
                map[runningSum] = i;
            }
        }
        
        return maxLen;
    }
};

int main() {
    std::cout << "Enter a binary string (containing only 0s and 1s): ";
    
    std::string userInput;
    std::getline(std::cin, userInput);
    
    std::regex binaryRegex("^[01]*$");
    if (!std::regex_match(userInput, binaryRegex)) {
        std::cout << "Error: Please enter a valid binary string containing only '0' and '1'." << std::endl;
    } else {
        int result = Solution::findTheLongestBalancedSubstring(userInput);
        std::cout << "The length of the longest substring with equal 0s and 1s is: " << result << std::endl;
    }
    
    return 0;
}
