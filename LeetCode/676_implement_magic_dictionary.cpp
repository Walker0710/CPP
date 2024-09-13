#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std; 

class MagicDictionary {
public:
    unordered_set<string>st;
    MagicDictionary() {
        st.clear();
    }
    
    void buildDict(vector<string> arr) {
        for(int i=0;i<arr.size();i++)
        {
            st.insert(arr[i]);
        }
    }
    
    bool search(string s) {
        for(int i=0;i<s.length();i++)
        {
            string temp=s;
            for(int k=0;k<26;k++)
            {
                char curr_char=char(k+'a');
                if(curr_char!=s[i])
                {
                    temp[i]=char(k+'a');
                    if(st.find(temp)!=st.end())
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};


class MagicDictionary {
public:
    vector<string> dic;
    unordered_set<string> st;

    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        dic = dictionary;
        for(auto i:dictionary)
        st.insert(i);
    }
    
    bool search(string searchWord) {
        for(auto i:dic) {

            if(i.length() == searchWord.length() && i != searchWord) {
                int diffCount = 0;
                for(int j = 0; j<i.length(); j++) {
                    if(i[j] != searchWord[j])
                    diffCount++;
                } 

                if(diffCount == 1)
                return true;
            }
        }
        return false;   
    }
};

// my thought 
class MagicDictionary {
public:
    vector<string> v;
    unordered_set<string> st;

    MagicDictionary() {}
    
    void buildDict(vector<string> dictionary) {
        v = dictionary;
        for (auto& word : dictionary) {
            st.insert(word);
        }
    }
    
    bool search(string s) {
        for (auto& word : v) {
            if (word.size() != s.size()) continue;
            
            int diffCount = 0;
            for (int i = 0; i < word.size(); ++i) {
                if (word[i] != s[i]) {
                    diffCount++;
                    if (diffCount > 1) break;
                }
            }
            
            if (diffCount == 1) return true;
        }
        return false;
    }

};