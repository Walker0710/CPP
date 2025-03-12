#include <bits/stdc++.h>

using namespace std;

// << ,

bool solve(int i, int j, string &wild, string &pattern) {
    if (i == wild.length() && j == pattern.length()) {
        return true;
    }

    if (i < wild.length() && wild[i] == '*') {
        return (solve(i + 1, j, wild, pattern) || (j < pattern.length() && solve(i, j + 1, wild, pattern)));
    }

    if (i < wild.length() && j < pattern.length() && (wild[i] == pattern[j] || wild[i] == '?')) {
        return solve(i + 1, j + 1, wild, pattern);
    }

    return false;
}

bool match(string wild, string pattern) {
    return solve(0, 0, wild, pattern);
}
