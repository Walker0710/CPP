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

        for(int i = 0; i<26; i++) {

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

        //base case 
        if(word.length() == 0) {

            root -> isTerminal = true;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        //is present
        if(root -> children[index] != NULL) {

            child = root -> children[index];
        }

        else {

            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }

        insertUntil(child, word.substr(1));
    }

    void inserWord(string word) {

        insertUntil(root, word);
    }

    bool searchUntil(TrieNode* root, string word) {

        if(word.length() == 0) {

            return root -> isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if(root -> children[index] != NULL) {

            child = root -> children[index];
        }

        else {

            return false;
        }

        return searchUntil(child, word.substr(1));
    }

    bool search(string word) {

        return searchUntil(root, word);
    }
};

vector<int> lexicalOrder(int n) {

    Trie* t = new Trie();

    for(int i = 1; i<=n; i++) {

        string stri = to_string(i);
        t -> inserWord(stri);
    }

}

