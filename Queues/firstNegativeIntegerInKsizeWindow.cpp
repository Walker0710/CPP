#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {

    deque<long long int> dq;
    vector<long long> ans;

    //process first window 0f k size
    for(int i = 0; i<K; i++) {

        if(A[i] < 0) {

            dq.push_back(i);
        }
    }

    //store ans of first k size window
    if(dq.size() > 0) {

        ans.push_back(A[dq.front()]);
    }

    else {

        ans.push_back(0);
    }

    //process for remaining window 
    for(int i = K; i<N; i++) {

        //removal
        if(!dq.empty() && i - dq.front() >= K) {

            dq.pop_front();
        }

        //addition
        if(A[i] < 0) {

            dq.push_back(i);
        }

        //ans store
        if(dq.size() > 0) {

            ans.push_back(A[dq.front()]);
        }

        else {

            ans.push_back(0);
        }
    }

    return ans;
}

//2nd approch
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {

    int counter = K;
    vector<int> ans;

    for(int i = 0; i<N; i++) {

        for(int j = i; j<K+i && j<N; j++) {

            if(A[j] < 0) {

                ans.push_back(A[j]);
                //break;

            }
        }
    }
}

//2nd approch me thora sa doubt h
