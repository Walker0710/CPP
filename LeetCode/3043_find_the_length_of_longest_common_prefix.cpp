#include <iostream>
#include <vector>
#include <limits.h>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

// brut force
int prefix(int i, int j)
{
    string f = to_string(i);
    string s = to_string(j);

    int ans = 0;

    int itI = 0;
    int itJ = 0;

    while (itI < f.length() && itJ < s.length() && f[itI] == s[itJ])
    {
        itI++;
        itJ++;
        ans++;
    }
    return ans;
}

int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
{
    unordered_set<int> one(arr1.begin(), arr1.end());
    unordered_set<int> second(arr2.begin(), arr2.end());

    int ans = 0;

    for (auto i = one.begin(); i != one.end(); i++)
    {
        for (auto j = second.begin(); j != second.end(); j++)
        {

            int yo = prefix(*i, *j);
            ans = max(yo, ans);
        }
    }
    return ans;
}

// optimize

int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
{
    unordered_map<string, int> mp;

    for (auto it : arr1)
    {
        string a = to_string(it);

        string x = "";

        for (auto b : a)
        {
            x += b;
            mp[x]++;
        }
    }
    int ans = 0;
    for (auto it : arr2)
    {

        string a = to_string(it);

        string x = "";

        for (auto b : a)
        {
            x += b;
            if (mp.find(x) != mp.end())
            {
                ans = max(ans, static_cast<int>(x.size()));
            }
        }
    }

    return ans;
}

//using trie
#pragma GCC optimize("O3", "unroll-loops")
struct Trie {
    Trie* next[10];
    bool isEnd = 0;

    Trie() {
        fill(next, next+10, (Trie*)NULL);
    }

    ~Trie() {
    //    cout<<"Destructor\n";
        for (int i=0; i<10; ++i) {
            if (next[i] !=NULL) {
                delete next[i];
            }
        }
    }

    void insert(string word) {
        Trie* Node=this;
        for(char c: word){
            int i=c-'0';
            if(Node->next[i]==NULL)
                Node->next[i]=new Trie();
            Node=Node->next[i];
        }
        Node->isEnd=1;
    }
    
    int commonPrefix(string s) {
        Trie* Node = this;
        int len=0;
        for(char c : s){
            int i = c - '0';
            if(Node->next[i]==NULL) return len;
            Node = Node->next[i];
            len++;
        }
        return len;
        
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie=Trie();
        for (int x: arr2)
            trie.insert(to_string(x));
        int maxLen=0;
        for (int x: arr1)
            maxLen=max(maxLen, trie.commonPrefix(to_string(x)));
        return maxLen;
    }
};
