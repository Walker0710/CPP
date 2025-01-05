#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <limits.h>
#include <map>
#include <unordered_set>

using namespace std;

// << ,

void reverseArray(vector<int> &arr) {
    int s = 0;
    int e = arr.size()-1;

    while(s < e) {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}