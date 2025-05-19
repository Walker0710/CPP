#include<iostream>

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
        if(word.length() == 0) 
            root -> isTerminal = true;
        
        int index = word[0] - 'A';
        TrieNode* child;

        //is present
        if(root -> children[index] != NULL) 
            child = root -> children[index];

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

        if(word.length() == 0) 
            return root -> isTerminal;
        
        int index = word[0] - 'A';
        TrieNode* child;

        if(root -> children[index] != NULL) 
            child = root -> children[index];

        else {
            return false;
        }
        return searchUntil(child, word.substr(1));
    }

    bool search(string word) {
        return searchUntil(root, word);
    }
};

//time complexity of insertion, Deletion, searching = O(length)

int main() {

    Trie* t = new Trie();
}

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;  // Corrected variable name

    TrieNode(char ch) {
        data = ch;

        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }

        isTerminal = false;  // Corrected variable name
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode('\0');
    }

    void insertUntil(TrieNode* root, string word) {
        // base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        // is present
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUntil(child, word.substr(1));
    }

    void insert(string word) {
        insertUntil(root, word);
    }

    bool searchUntil(TrieNode* root, string word) {
        if (word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return false;
        }

        return searchUntil(child, word.substr(1));
    }

    bool search(string word) {
        return searchUntil(root, word);
    }

    bool startUntil(TrieNode* root, string word) {
        if (word.length() == 0) {
            return true;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return false;
        }

        return startUntil(child, word.substr(1));
    }

    bool startsWith(string prefix) {
        return startUntil(root, prefix);
    }
};


class trieNode {
    public:
        char value;
        trieNode* children[26];
        bool terminate;

        trieNode(char value) {
            this -> value = value;

            for(int i = 0; i<26; i++) 
            children[i] = NULL;

            this -> terminate = false;
        }
}


class Trie {
public:

    trieNode* root;

    Trie() {
        root = new trieNode('\0');
    }

    void insi(trieNode* root, string word) {

        if(word.length() == 0) {
            root -> terminate = true;
            return ;
        }

        int ele = word[0] - 'a';
        trieNode* temp;

        if(root -> children[ele] != NULL) {
            temp = root -> children[ele];
        }

        else {
            temp = new trieNode(word[0]);
            root -> children[ele] = temp;
            temp = root -> children[ele];
        }

        insi(temp, word.substr(1));
    }
    
    void insert(string word) {
        insi(root, word);
    }

    bool siri(trieNode* root, string word) {
        if(word.length() == 0) {
            return root -> terminate;
        }

        int ele = word[0] - 'a';

        if(root -> children[ele] != NULL) {
            return siri(root -> children[ele], word.substr(1));
        }

        return false;
    }
    
    bool search(string word) {
        return siri(root, word);
    }
    
    bool startsWith(string prefix) {
        
    }
};