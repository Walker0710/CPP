#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <limits.h>
#include <set>
#include <algorithm>

using namespace std;

//1st approch
double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
{

    unordered_map<int, list<pair<int, double>>> adj;

    for (int i = 0; i < edges.size(); i++)
    {

        adj[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i]));
        adj[edges[i][1]].push_back(make_pair(edges[i][0], succProb[i]));
    }

    vector<double> prob(adj.size());

    for (int i = 0; i < adj.size(); i++)
        prob[i] = INT_MIN;

    prob[start_node] = 0;

    set<pair<double, int>> st;
    st.insert(make_pair(0, start_node));

    while (!st.empty())
    {

        auto top = *(st.begin());

        double nodeProb = top.first;
        int TopNode = top.second;

        st.erase(st.begin());

        for (auto neigh : adj[TopNode])
        {

            if (nodeProb * (neigh.second) > prob[neigh.first])
            {
                auto record = st.find(make_pair(prob[neigh.first], neigh.first));

                if (record != st.end())
                    st.erase(record);

                prob[neigh.first] = nodeProb * (neigh.second);

                st.insert(make_pair(prob[neigh.first], neigh.first));
            }
        }
    }

    if (prob[end_node])
        return 0.0;

    return prob[end_node];
}

// 2nd approch
using v = pair<double, int>;
vector<vector<v>> adj;

void create_adj(int n, vector<vector<int>> &edges, vector<double> &succProb)
{
    adj.resize(n);
    int eN = edges.size();
    for (int i = 0; i < eN; i++)
    {
        int v0 = edges[i][0], v1 = edges[i][1];
        adj[v0].push_back({succProb[i], v1});
        adj[v1].push_back({succProb[i], v0});
    }
}

double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
{
    vector<double> prob(n, 0);
    create_adj(n, edges, succProb);
    priority_queue<v, vector<v>> pq;

    pq.push({1.0, start});
    prob[start] = 1.0;

    while (!pq.empty())
    {
        auto [cur_prob, i] = pq.top();
        pq.pop();

        if (i == end)
        {
            return cur_prob;
        }

        for (auto [next_prob, j] : adj[i])
        {
            double new_prob = cur_prob * next_prob;
            if (new_prob > prob[j])
            {
                prob[j] = new_prob;
                pq.push({new_prob, j});
            }
        }
    }
    return 0.0;
}
