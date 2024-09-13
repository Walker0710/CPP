#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

// 1st approch
string longestCommonPrefix(vector<string> &arr, int n)
{

    string first = arr[0];
    string ans = "";

    for(int i = 0; i<arr.size(); i++) {

        if(arr[i].size() == 0)
        return ans;
    }

    for (int i = 0; i < arr[0].length(); i++)
    {
        char letter = first[i];
        bool flag = true;

        for (int j = 1; j < n; j++)
        {
            string yo = arr[j];

            if (yo.size() < i || letter != yo[i])
            {
                flag = false;
                break;
            }
        }

        if (flag == false)
            break;

        if (flag)
            ans.push_back(letter);
    }

    return ans;
}

// 2nd approch
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;

        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }

        isTerminal = false;
        childCount = 0;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUntil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        // is present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        insertUntil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUntil(root, word);
    }

    void LCP(string str, string &ans)
    {
        TrieNode *current = root;
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];
            if (current->childCount == 1)
            {
                ans.push_back(ch);
                int index = ch - 'a';
                current = current->children[index];
            }
            else
            {
                break;
            }
            if (current->isTerminal)
            {
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<string> &arr)
{
    Trie *t = new Trie();

    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i].size() == 0) {

            return "";
        }
        t->insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    t->LCP(first, ans);

    return ans;
}

int main()
{
    vector<string> words = {"flower", "flow", "flight"};
    int n = words.size();

    string result = longestCommonPrefix(words, n);
    cout << "Longest Common Prefix: " << result << endl;

    return 0;
}

//3rd approch
    string longestCommonPrefix(vector<string>& v) {
        string ans="";
        sort(v.begin(),v.end());
        int n=v.size();
        string first=v[0],last=v[n-1];
        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i]!=last[i]){
                return ans;
            }
            ans+=first[i];
        }
        return ans;
    }