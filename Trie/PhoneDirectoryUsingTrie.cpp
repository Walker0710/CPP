#include<iostream>
#include<vector>

using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;

        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }

        isTerminal = false;
    }
};

class Trie { 
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUntil(TrieNode* root, string word) {
        // base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        char ch = word[0];
        int index = tolower(ch) - 'a'; // Handle both uppercase and lowercase
        TrieNode* child;

        // is present
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(ch);
            root->children[index] = child;
        }

        insertUntil(child, word.substr(1));
    }

    void inserWord(string word) {
        insertUntil(root, word);
    }

    void printSuggestion(TrieNode* curr, vector<string>& temp, string prefix) {
        if (curr->isTerminal) {
            temp.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            TrieNode* next = curr->children[ch - 'a'];

            if (next != NULL) {
                prefix.push_back(ch);
                printSuggestion(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestion(string str) {
        TrieNode* prev = root;
        vector<vector<string>> ans;

        string prefix = "";

        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];
            prefix.push_back(ch);
            vector<string> toPush;

            int index = tolower(ch) - 'a'; // Handle both uppercase and lowercase
            TrieNode* curr = prev->children[index];

            if (curr == NULL) {
                break;
            }

            printSuggestion(curr, toPush, prefix);

            ans.push_back(toPush);
            toPush.clear();
            prev = curr;
        }

        return ans;
    }
};

vector<vector<string>> phoneDirectory(const vector<string>& contactList, const string& queryStr) {
    Trie* t = new Trie();

    for (int i = 0; i < contactList.size(); i++) {
        string yo = contactList[i];
        t->inserWord(yo);
    }

    return t->getSuggestion(queryStr);
}