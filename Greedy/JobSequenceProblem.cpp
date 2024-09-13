#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

static bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n) {

    sort(arr, arr+n, cmp);

    int maxiDeadline = INT_MIN;

    for(int i = 0; i<n; i++) {

        maxiDeadline = max(maxiDeadline, arr[i].dead);
    }

    vector<int> schedule(maxiDeadline + 1, -1);

    int count = 0;
    int maxProfit = 0;

    for(int i = 0; i<n; i++) {

        int currProfit = arr[i].profit;
        int currJobID = arr[i].id;
        int currDead = arr[i].dead;

        for(int k = currDead; k>0; k--) {

            if(schedule[k] == -1) {

                count++;
                maxProfit += currProfit;
                schedule[k] = currJobID;
                break;
            }
        }
    }

    vector<int> ans;
    ans.push_back(count);
    ans.push_back(maxProfit);

    return ans;
}