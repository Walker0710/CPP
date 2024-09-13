#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Custom comparator function
bool customSort(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second; // If first elements are equal, sort by second element
    }
    return a.first < b.first; // Otherwise, sort by first element
}

int main() {
    // Sample vector
    vector<pair<int, int>> vec = {{1, 3}, {2, 2}, {1, 2}, {2, 3}, {1, 1}};

    // Sorting using custom comparator
    sort(vec.begin(), vec.end(), customSort);

    // Printing sorted vector
    for (const auto& p : vec) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    return 0;
}
