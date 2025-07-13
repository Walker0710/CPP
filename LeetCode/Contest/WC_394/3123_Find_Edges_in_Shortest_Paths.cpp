#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> dijkstra(unordered_map<int, list<pair<int, int>>> &adj, int source, int vertices) 
{
    vector<int> dist(vertices);
    
    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT32_MAX;
    }

    set<pair<int, int>> st;

    dist[source] = 0;
    st.insert(make_pair(0, source));

    while (!st.empty())
    {
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        // remove top record now
        st.erase(st.begin());

        for (auto neigh : adj[topNode])
        {
            if (nodeDistance + neigh.second < dist[neigh.first])
            {
                auto record = st.find(make_pair(dist[neigh.first], neigh.first));

                // if record found then erase it
                if (record != st.end())
                {
                    st.erase(record);
                }

                // distance update
                dist[neigh.first] = nodeDistance + neigh.second;

                // record push in set
                st.insert(make_pair(dist[neigh.first], neigh.first));
            }
        }
    }

    return dist;
}

vector<bool> findAnswer(int n, vector<vector<int>> &edges)
{
    unordered_map<int, list<pair<int, int>>> adj;
    
    for(int i = 0; i<edges.size(); i++) {
        
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> first = dijkstra(adj, 0, n);
    vector<int> second = dijkstra(adj, n-1, n);

    int shorte = first[n-1];

    vector<bool> ans(edges.size());

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        if(first[u] != INT_MAX && second[v] != INT_MAX && first[u] + w + second[v] == shorte) {
            ans[i] = true;
        }

        if(first[v] != INT_MAX && second[u] != INT_MAX && first[v] + w + second[u] == shorte) {
            ans[i] = true;
        }
    }

    return ans;
}