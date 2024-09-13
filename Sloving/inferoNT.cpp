#include<iostream>
#include<vector>

using namespace std;

int main() {

    long long n;
    long long k;

    vector<long long> yo;

    for(long long i = 1; i*i<=n; i++) {

        if(n%i == 0) {

            yo.push_back(i);

            if(i != n/i) {

                yo.push_back(n/i);
            }
        }

        sort(yo.begin(), yo.end());
        k--;

        if(k >= yo.size()) {

            cout<<"-1"<<endl;
        }
        


    



    int ans = yo[k-1];
}

}