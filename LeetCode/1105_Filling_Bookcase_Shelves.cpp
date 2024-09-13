#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

// only rec
int solve(vector<vector<int>> &books, int shelfWidth, int index, int width, int height)
{

    if (index >= books.size())
        return height;

    int ans = 0;

    if (width + books[index][0] > shelfWidth)
    {
        ans = ans + height;
        height = 0;
    }

    else
        int yo = solve(books, shelfWidth, index - 1, books[index][0] + width, max(height, books[index][1]));

    return ans;
}

int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
{
    return solve(books, shelfWidth, books.size() - 1, 0, 0);
}

// rec + mem
int solve(vector<vector<int>> &books, int i, int remShelfWidth, int maxShelfHeight, int shelfWidth, vector<vector<int>> &dp)
{
    if (i == books.size())
    return maxShelfHeight;

    if (dp[i][remShelfWidth] != -1)
    return dp[i][remShelfWidth];

    int currShelf = INT_MAX, nextShelf = INT_MAX;

    int bookWidth = books[i][0];
    int bookHeight = books[i][1];

    if (bookWidth <= remShelfWidth)
    currShelf = solve(books, i + 1, remShelfWidth - bookWidth, max(maxShelfHeight, bookHeight), shelfWidth, dp);
    

    nextShelf = maxShelfHeight + solve(books, i + 1, shelfWidth - bookWidth, bookHeight, shelfWidth, dp);

    return dp[i][remShelfWidth] = min(currShelf, nextShelf);
}

int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
{
    vector<vector<int>> dp(1001, vector<int>(shelfWidth + 1, -1));
    return solve(books, 0, shelfWidth, 0, shelfWidth, dp);
}
