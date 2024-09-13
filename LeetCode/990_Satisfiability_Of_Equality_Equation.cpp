#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <limits.h>
#include <algorithm>

using namespace std;

void makeSet(vector<int> &parent, vector<int> &rank, int n) {             

    for(int i = 0; i<n; i++) {

        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node) {           
                                                        
    if(parent[node] == node)
    return node;

    return findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {

    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] < rank[v]) 
    parent[u] = v;

    else if(rank[v] < rank[u]) 
    parent[v] = u;

    else {

        parent[v] = u;
        rank[u]++;
    }
}

bool equationsPossible(vector<string>& equations) {

    vector<int> parent(26);
    vector<int> rank(26);

    makeSet(parent, rank, 26);

    for(int i = 0; i<equations.size(); i++) {

        string yo = equations[i];

        if(yo[1] == '=') {

            unionSet(yo[0] - 'a', yo[3] - 'a', parent, rank);
        }
    }

    for(int i = 0; i<equations.size(); i++) {

        string yo = equations[i];

        if(yo[1] == '!') {

            int u = findParent(parent, yo[0] - 'a');
            int v = findParent(parent, yo[3] - 'a');

            if(u == v) 
            return false;
        }
    }

    return true;
}

