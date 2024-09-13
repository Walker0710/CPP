#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {

    unordered_map<string, vector<string>> anagrams;

    for(int i = 0; i<strs.size(); i++) {

        string word = strs[i];
        string sorted = strs[i];
        sort(sorted.begin(), sorted.end());
        

        anagrams[sorted].push_back(word);                                  
    }

    vector<vector<string>> result;
    for (const auto& entry : anagrams) {
        result.push_back(entry.second);
    }

    return result;
}

//doubt ye h ki map ko vector me kase convert kiya and wo syntax kya h 2nd for loop wla 