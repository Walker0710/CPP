#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <limits.h>
#include <algorithm>

using namespace std;

inline const auto optimize = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

int findCenter(vector<vector<int>> &edges)
{

    vector<int> degree(edges.size() + 2, 0);

    for (auto i : edges)
    {
        degree[i[0]]++;
        degree[i[1]]++;
    }

    for (int i = 0; i < degree.size(); i++)
    {
        if (degree[i] == edges.size())
            return i;
    }
}

int findCenter(vector<vector<int>> &edges)
{
    return (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) ? edges[0][0] : edges[0][1];
}