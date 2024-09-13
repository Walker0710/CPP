#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2> &pair) const {
        // Combine hashes of the two integers
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

int main() {
    std::unordered_map<std::pair<int, int>, bool, pair_hash> m;
}