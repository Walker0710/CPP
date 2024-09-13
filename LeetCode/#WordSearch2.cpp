#include<iostream>
#include<vector>

using namespace std;

//1st approch without trie
pair<int, int> search(vector<vector<char>>& board, char ch) {

    int m = board.size();
    int n = board[0].size();

    for(int i = 0; i<m; i++) {

        for(int j = 0; j<n; j++) {

            if(board[i][j] == ch) {

                pair<int, int> ans = make_pair(i, j);
                return ans;
            }
        }
    }

    return make_pair(-1, -1);
}

bool isVaid(int m, int n, int row, int col) {

    if(row < m && row >= 0 && col < n && col >= 0) {

        return true;
    }
    return false;
}

bool GiveMeTheWordIWillGiveYouResult(vector<vector<char>>& board, string word, int row, int col) {

    int m = board.size();
    int n = board[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n));

    for(int i = 1; i<word.length(); i++) {

        char ch = word[i];

        if(isVaid(m, n, row - 1, col) && board[row-1][col] == ch) {

            return true;
        }

        else if(isVaid(m, n, row, col+1) && board[row][col+1] == ch) {

            return true;
        }

        else if(isVaid(m, n, row+1, col) && board[row+1][col] == ch) {

            return true;
        }

        else if(isVaid(m, n, row, col-1) && board[row][col-1] == ch) {

            return true;
        }
    }

    return false;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

    int m = board.size();
    int n = board[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n));

    for(int i = 0; i<words.size(); i++) {

        string word = words[i];

        for(int j = 0; j<word.length(); i++) {

            int ch = word[j];

            pair<int, int> yo = search(board, ch);

            if(yo.first == -1 && yo.second == -1) 
            break;

            else {


            } 
        }
    }


}

//2nd approch using trie
class trieNode
{
public:
    char value;
    trieNode *children[26];
    bool terminate;

    trieNode(char value)
    {
        this->value = value;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
        this->terminate = false;
    }
};
class Trie
{
public:
    trieNode *root;
    Trie()
    {
        root = new trieNode('\0');
    }
    void insi(trieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->terminate = true;
            return;
        }

        int index = word[0] - 'a';
        trieNode *temp;
        if (root->children[index] != NULL)
        {
            temp = root->children[index];
        }
        else
        {
            temp = new trieNode(word[0]);
            root->children[index] = temp;
            temp = root->children[index];
        }
        insi(temp, word.substr(1));
    }

    void insert(string word)
    {
        insi(root, word);
    }

    bool siri(trieNode *root, string word)
    {
        if (word.length() == 0)
            return root->terminate;
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
        {
            return siri(root->children[index], word.substr(1));
        }
        return false;
    }

    bool search(string word)
    {
        return siri(root, word);
    }

    bool pre(trieNode *root, string word)
    {
        if (word.length() == 0)
            return true;
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
        {
            return pre(root->children[index], word.substr(1));
        }
        return false;
    }

    bool startsWith(string prefix)
    {
        return pre(root, prefix);
    }
};

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

    trieNode* allWord = new trieNode('\0');

    for (int i = 0; i < words.size(); i++) {

        string yo = words[i];
        allWord -> insert(yo);
    }

    int row = board.size();
    int col = board[0].size();

    for(int i = 0; i<row; i++) {

        for(int j = 0; j<col; j++) {

            int index = board[i][j] - 'a';

            if(allWord -> children[index] != NULL) {

                
            }
        }
    }


}