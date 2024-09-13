#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int maxAtrea(int M[][MAX], int n, int m) {

    vector<int> height;

    int sum = 0;

    for(int k = 0; k<n; k++) {

        for(int j = 0; j<m; j++) {

            for(int i = 0; i<=k; i++) {

                if(M)

                sum = sum + M[j][i];
            }            

            height.push_back(sum);
        }
    }


}

