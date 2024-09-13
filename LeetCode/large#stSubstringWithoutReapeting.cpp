#include<iostream>
#include<unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {

    unordered_map<char, int> charMap;
    int size = 0;

    for(int i = 0; i<s.length(); i++) {

        for(int  j = i; j<s.length(); j++)  {


        }

        
    }


}

        int n = s.length();
        int maxLength = 0;
        unordered_map<char, int> charMap;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            if (charMap.count(s[right]) == 0 || charMap[s[right]] < left) {
                charMap[s[right]] = right;
                maxLength = max(maxLength, right - left + 1);
            } else {
                left = charMap[s[right]] + 1;
                charMap[s[right]] = right;
            }
        }
        
        return maxLength;
    }

