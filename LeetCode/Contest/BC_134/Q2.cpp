#include <bits/stdc++.h>

using namespace std;

// << ,

long long maximumPoints(vector<int> &enemyEnergies, int currentEnergy)
{
    sort(enemyEnergies.begin(), enemyEnergies.end());

    if (currentEnergy < enemyEnergies[0])
        return 0;

    long long temp = 1LL * currentEnergy;

    int n = enemyEnergies.size();

    int l = 0;
    int r = n - 1;
    long long ans = 0;

    while (l <= r)
    {
        if (temp >= enemyEnergies[l])
        {
            temp = temp - enemyEnergies[l];
            ans++;
        }

        else
        {
            temp = temp + enemyEnergies[r];
            r--;
        }
    }

    return ans;
}


long long maximumPoints(vector<int> &enemyEnergies, int currentEnergy)
{
    long long profit = 0, mn = INT_MAX;
    long long totalEnergy = currentEnergy;
    
    for (long long i = 0; i < enemyEnergies.size(); i++)
    {
        if (enemyEnergies[i] < mn)
        mn = enemyEnergies[i];
        
        totalEnergy += enemyEnergies[i];
    }

    if (currentEnergy < mn)
    return 0;
    
    totalEnergy -= mn;
    
    return totalEnergy / mn;
}