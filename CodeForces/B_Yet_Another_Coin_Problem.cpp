#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

// << ,
// int solveMem(vector<int> &a, int total, vector<int> &dp) {
//     if(total == 0) 
//     return 0;

//     if(total < 0) 
//     return INT_MAX;

//     if(dp[total] != -1)
//     return dp[total];

//     int ans = INT_MAX;

//     for(int i = 4; i>=0; i--) {
//         ans = min(ans, 1 + solveMem(a, total - a[i], dp));
//     }

//     return dp[total] = ans;
// }

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<int> a(5);
//     a[0] = 1;
//     a[1] = 3;
//     a[2] = 6;
//     a[3] = 10;
//     a[4] = 15;
    
//     vector<int> dp(n+1, -1);
//     dp[0] = 0;

//     int ans = solveMem(a, n, dp);
//     cout <<ans<< endl;
// }

// signed main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }



int getAns(int n){
    int ans=0;
    ans+=n/15;
    n%=15;
    ans+=n/6;
    n%=6;
    ans+=n/3;
    n%=3;
    ans+=n;
    return ans;
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
 
    int testcases;
    cin>>testcases;
    for(int i=1;i<=testcases;i++){
        int n;cin>>n;
        if(n<10){
            cout<<getAns(n)<<endl;
        }else if(n<20){
            cout<<min(getAns(n),getAns(n-10)+1)<<endl;
        }else{
            cout<<min({getAns(n),getAns(n-10)+1,getAns(n-20)+2})<<endl;
        }
    }
}