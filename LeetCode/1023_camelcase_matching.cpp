#include <iostream>
#include <vector>
#include <limits.h>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

class TrieNode{
    public: 
    char data;
    TrieNode* children[58];
    bool isTerminal;

    TrieNode(char ch): data(ch), isTerminal(false){
        for(int i = 0; i < 58; i++){
            children[i] = 0;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    void insertUtil(TrieNode* root, string &word, int i){
        if(word.size() <= i){
            root->isTerminal = true;
            return;
        }

        int index = word[i] - 'A';
        if(root->children[index] == NULL){
            root->children[index] = new TrieNode(word[i]);
        }

        insertUtil(root->children[index], word, i + 1);
    }

    bool searchUtil(TrieNode* root, string &word, int i){
        if(word.size() <= i){
            return root->isTerminal;
        }

        int index = word[i] - 'A';

        if(root->children[index]){ 
            return searchUtil(root->children[index], word, i+1);
        }
        else if(islower(word[i])){
            return searchUtil(root, word, i+1);
        }
        return false;
    }

    Trie() {
        root = new TrieNode('\0');
    }
    void insert(string& word) {
        return insertUtil(root, word, 0);
    }
    
    bool search(string& word) {
        return searchUtil(root, word, 0);
    }
};

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool>ans;
        Trie trie;
        trie.insert(pattern);
        for(auto querie : queries){
            bool op = trie.search(querie);
            ans.push_back(op);
        }
        return ans;
    }
};

// 2nd
bool isSubsequence(string &word, string &pattern)
{
    int p_len = pattern.length(), word_len = word.length();
    int i = 0, j = 0;

    while (j < p_len && i < word_len)
    {
        if (pattern[j] == word[i])
        {
            j++;
        }
        i++;
    }
    return j == p_len;
}

bool isAllPresent(string &word, string &pattern)
{
    int i = 0, j = 0;

    while (i < word.length() && j < pattern.length())
    {
        while (i < word.length() && !isupper(word[i]))
            i++;

        while (j < pattern.length() && !isupper(pattern[j]))
            j++;

        if (i < word.length() && j < pattern.length() && word[i] != pattern[j])
            return false;

        if (i < word.length() && j < pattern.length())
        {
            i++;
            j++;
        }
    }

    while (j < pattern.length())
    {
        if (isupper(pattern[j]))
            return false;
        j++;
    }

    while (i < word.length())
    {
        if (isupper(word[i]))
            return false;
        i++;
    }

    return true;
}

vector<bool> camelMatch(vector<string> &queries, string pattern)
{
    vector<bool> ans;

    for (auto word : queries)
    {
        bool toPush = isAllPresent(word, pattern) && isSubsequence(word, pattern);
        ans.push_back(toPush);
    }
    return ans;
}