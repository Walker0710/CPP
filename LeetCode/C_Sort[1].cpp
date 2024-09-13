#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <limits.h>
#include <algorithm>
using namespace std;

int solve(string first, string second, int l, int r) {
    vector<int> freqFirst(26, 0);
    vector<int> freqSecond(26, 0);

    for(int i = l; i <= r; i++) {
        freqFirst[first[i] - 'a']++;
        freqSecond[second[i] - 'a']++;
    }

    int ans = 0;

    for(int i = 0; i<26; i++) {
        ans = ans + abs(freqFirst[i] - freqSecond[i]);
    }

    return ans/2;
} 

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;

        vector<vector<int>> firstRec(n+1, vector<int> (26));
        vector<vector<int>> secondRec(n+1, vector<int> (26));

        for(int i = 0; i<n; i++) {
            
        }

        string a;
        string b;
        cin>>a>>b;

        while (q--)
        {
            int l,r;
            cin>>l>>r;
            l--,r--;
            int ans = solve(a,b,l,r);
            cout<<ans<<endl;
        }
        
    }
}
