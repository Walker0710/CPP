#include<iostream>
#include<vector>

using namespace std;

vector<int> moveZero(int arr[], int n) {

    vector<int> ans;

    for(int i = 0; i<n; i++) {

        if(arr[i] != 0) {

            ans.push_back(arr[i]);
        }
    }

    int count = 0;

    for(int j = 0; j<n; j++) {

        if(arr[j] == 0) {

            count++;
        }
    }

    for(int k = 0; k < count; k++) {

        ans.push_back(0);
    }
}

int main() {

    int arr[7] = {0,1,5,0,3,0,8};

    vector<int> yo = moveZero(arr,7);

    for(int i = 0; i<yo.size(); i++) {

        cout<<yo[i]<<" ";
    }
}


