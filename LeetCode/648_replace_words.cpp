#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>

using namespace std; 

string replaceWords(vector<string>& dictionary, string sentence) {
    std::unordered_set<std::string> map(dictionary.begin(), dictionary.end());

    vector<int> spaces;
    spaces.push_back(-1);

    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == ' ')
            spaces.push_back(i);
    }
    spaces.push_back(sentence.length());

    string ans;

    for (int i = 0; i < spaces.size() - 1; i++) {
        int first = spaces[i] + 1;
        int last = spaces[i + 1];
        string word = sentence.substr(first, last - first);
        
        string prefix;
        for (int j = 1; j <= word.length(); j++) {
            prefix = word.substr(0, j);
            if (map.count(prefix)) {
                ans += prefix + " ";
                break;
            }
        }

        if (!map.count(prefix)) {
            ans += word + " ";
        }
    }

    if (!ans.empty()) ans.pop_back(); // Remove trailing space
    return ans;
}


//leet code 
class Solution {
public:
    struct trieNode {
        struct trieNode* child[26];
        bool endOfWord;

        trieNode() {
            for (int i = 0; i < 26; ++i) {
                child[i] = nullptr;
            }
            endOfWord = false;
        }
    };

    typedef struct trieNode node;

    node* buildPrefixTrie(node* root, const string& word, int n, int i) {
        if (i == n) {
            root->endOfWord = true;
            return root;
        }
        if(i<n && root->endOfWord == true){
            return root;
        }
        if (root->child[word[i] - 'a'] == nullptr) {
            root->child[word[i] - 'a'] = new node();
        }
        root->child[word[i] - 'a'] = buildPrefixTrie(root->child[word[i] - 'a'], word, n, i + 1);
        return root;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        node* root = new node();
        for (const auto& word : dictionary) {
            buildPrefixTrie(root, word, word.size(), 0);
        }
        stringstream ss(sentence);
        string word;
        string result;
        while (ss >> word) {
            node* p = root;
            int i = 0;
            int n = word.size();
            string temp = "";
            while (i < n) {
                if (p->endOfWord) {
                    result += temp;
                    break;
                }
                if (p->child[word[i] - 'a'] == nullptr) {
                    result += word;
                    break;
                }
                temp += word[i];
                p = p->child[word[i] - 'a'];
                i++;
            }
            if (i == n) { // means we went through the entire word without finding a shorter prefix
                result += word;
            }
            result += " ";
        }
        if (!result.empty()) {
            result.pop_back(); // Remove the last space
        }
        return result;
    }
};