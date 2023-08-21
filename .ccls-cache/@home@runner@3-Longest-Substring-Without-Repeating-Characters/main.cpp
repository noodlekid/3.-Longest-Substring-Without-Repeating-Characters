#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int maxLength = 0;
    vector<int> charIndex(256, -1); // Assuming ASCII characters

    int i = 0; // Starting index of the current substring

    for (int j = 0; j < s.length(); j++) {
      // If the character has been seen in the current substring
      // update the starting index to the next character
      if (charIndex[s[j]] >= i) {
        i = charIndex[s[j]] + 1;
      }

      // Update the index of the current character
      charIndex[s[j]] = j;

      // Update the maximum length
      maxLength = max(maxLength, j - i + 1);
    }

    return maxLength;
  }
};

int main() {

  Solution sol;

  string test = "pwwkew";
  int lolss = sol.lengthOfLongestSubstring(test);
  cout << lolss;
}