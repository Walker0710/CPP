#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int solve(int *arr, int n, int k) {

    deque<int> maxi(k);
    deque<int> mini(k);

    //addion for first window
    for(int i = 0; i<n; i++) {

        while(!maxi.empty() && arr[maxi.back()] <= arr[i]) {

            maxi.pop_back();
        }

        while(!mini.empty() && arr[mini.back()] <= arr[i]) {

            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans = 0;
    for(int i = k; i<n; i++) {

        ans = ans + arr[mini.front()] + arr[maxi.front()];

        //next window 

        //removal
        while(!maxi.empty() && i - maxi.front() >= k) {

            maxi.pop_front();
        }

        while(!mini.empty() && i - mini.front() >= k) {

            mini.pop_front();
        }

        //addition

        while(!maxi.empty() && arr[maxi.back()] <= arr[i]) {

            maxi.pop_back();
        }

        while(!mini.empty() && arr[mini.back()] <= arr[i]) {

            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    ans = ans + arr[maxi.front()] + arr[mini.front()];

    return ans;
}