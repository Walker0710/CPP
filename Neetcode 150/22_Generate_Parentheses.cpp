#include <bits/stdc++.h>

using namespace std;

// << ,
void backtrack(int open, int close, int n, string& stack, vector<string>& ans) {
    if(open == n && close == n) {
        ans.push_back(stack);
        return ;
    }

    if(open < n) {
        stack = stack + '(';
        backtrack(open+1, close, n, stack, ans);
        stack.pop_back();
    }

    if(close < open) {
        stack = stack + ')';
        backtrack(open, close+1, n, stack, ans);
        stack.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string stack;
    
    backtrack(0, 0, n, stack, ans);

    return ans;
}