#include <bits/stdc++.h>

using namespace std;

// << ,

bool hasMoreThanNBy4Copies(const std::vector<int> &A)
{
    int n = A.size();
    std::unordered_map<int, int> candidates;

    // First pass: Find up to 3 potential candidates
    for (int x : A)
    {
        if (candidates.count(x))
        {
            candidates[x]++;
        }
        else if (candidates.size() < 3)
        {
            candidates[x] = 1;
        }
        else
        {
            std::vector<int> toRemove;
            for (auto &[key, count] : candidates)
            {
                candidates[key]--;
                if (candidates[key] == 0)
                {
                    toRemove.push_back(key);
                }
            }
            for (int key : toRemove)
            {
                candidates.erase(key);
            }
        }
    }

    // Second pass: Verify actual counts of candidates
    std::unordered_map<int, int> actualCounts;
    for (int x : A)
    {
        if (candidates.count(x))
        {
            actualCounts[x]++;
        }
    }

    for (const auto &[key, count] : actualCounts)
    {
        if (count > n / 4)
        {
            return true;
        }
    }

    return false;
}

// Example usage
int main()
{
    std::vector<int> A = {1, 2, 3, 1, 2, 1, 1}; // 1 appears 4 times in a size-7 array (n/4 = 1.75)
    if (hasMoreThanNBy4Copies(A))
    {
        std::cout << "An element appears more than n/4 times.\n";
    }
    else
    {
        std::cout << "No element appears more than n/4 times.\n";
    }
    return 0;
}





bool hasMoreThanNBy2Copies(const std::vector<int>& A) {
    int n = A.size();
    int candidate = 0, count = 0;

    // First pass: Find potential majority candidate
    for (int x : A) {
        if (count == 0) {
            candidate = x;
            count = 1;
        } else if (x == candidate) {
            count++;
        } else {
            count--;
        }
    }

    // Second pass: Verify the candidate
    count = 0;
    for (int x : A) {
        if (x == candidate) {
            count++;
        }
    }

    return count > n / 2;
}

// Example usage
int main() {
    std::vector<int> A = {1, 2, 3, 2, 2, 2, 2}; // n = 7 → 2 appears 4 times
    if (hasMoreThanNBy2Copies(A)) {
        std::cout << "An element appears more than n/2 times.\n";
    } else {
        std::cout << "No element appears more than n/2 times.\n";
    }
    return 0;
}
