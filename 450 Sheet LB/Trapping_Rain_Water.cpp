#include <bits/stdc++.h>

using namespace std;

// << ,

int maxWater(vector<int> &arr)
{   
    int n = arr.size();

    vector<int> rightMax(n);
    vector<int> leftMax(n);

    leftMax[0] = arr[0];

    for(int i = 1; i<n; i++) {
        leftMax[i] = max(leftMax[i-1], arr[i]);
    }

    rightMax[n-1] = arr[n-1];

    for(int i = n-2; i>=0; i--) {
        rightMax[i] = max(rightMax[i+1], arr[i]);
    }

    int ans = 0;

    for(int i = 0; i<n; i++) {
        ans = ans + min(rightMax[i], leftMax[i]) - arr[i];
    }

    return ans;
}



int maxWater(vector<int> &arr) {
    int curr = 0;
    int index = -1;
    int sum = 0;
    
    //pehle toh normal wala nikal le
    for(int i = 0; i<arr.size()-1 ; i++){
        if(arr[i+1]<arr[i]){
            index = i;
            curr = arr[i];
            break;
        }
    }
    
    vector<int> prefix_sum(arr.size()+1,0);
    for(int i = 1; i<arr.size(); i++){
        prefix_sum[i] = arr[i-1]+prefix_sum[i-1];
    }
    
    if(index==-1) return 0;
    for(int i = index+1; i<arr.size(); i++){
        if(arr[i]>=curr){
            sum+=(i-index-1)*(curr) - (prefix_sum[i]-prefix_sum[index+1]);
            curr = arr[i];
            index = i;
        }
    }
    // cout<<sum<<endl;
    
    set<pair<int,int>> s;// value,index
    
    for(int i = index+1; i<arr.size() ; i++){
        s.insert({arr[i],i});
    }
    
    while(!s.empty()){
        pair<int,int> p = *prev(s.end());
        s.erase(prev(s.end()));
        if(index>p.second) continue;
        else{
            int value = (p.second-index-1)*(p.first) - (prefix_sum[p.second]-prefix_sum[index+1]);
            if(value<0) break;
            sum+=value;
            curr = p.first;
            index = p.second;
        }
    }

    return sum;
}