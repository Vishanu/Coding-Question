/*
A string s is called happy if it satisfies the following conditions:

s only contains the letters 'a', 'b', and 'c'.
s does not contain any of "aaa", "bbb", or "ccc" as a substring.
s contains at most a occurrences of the letter 'a'.
s contains at most b occurrences of the letter 'b'.
s contains at most c occurrences of the letter 'c'.
Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.
Example 2:

Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It is the only correct answer in this case.
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<pair<int, char>> freq = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        string res = "";
        
        while (true) {
            // Sort the characters by their frequency in descending order
            sort(freq.rbegin(), freq.rend());
            
            bool added = false;
            for (int i = 0; i < 3; ++i) {
                int count = freq[i].first;
                char ch = freq[i].second;
                
                // If the current character count is zero, return the result
                if (count <= 0) {
                    return res;
                }
                
                // If the last two characters are the same as the current one, skip this iteration
                if (res.size() >= 2 && res[res.size() - 1] == ch && res[res.size() - 2] == ch) {
                    continue;
                }
                
                // Add the character to the result string
                res += ch;
                --freq[i].first;  // Decrease the count of the added character
                added = true;
                break;
            }
            
            // If no character was added, return the result
            if (!added) {
                return res;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.longestDiverseString(1, 1, 7) << endl; // Example call
    return 0;
}
