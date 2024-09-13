#include<iostream> 
#include<vector>

using namespace std;

vector<int> addArr(vector<int> &arr1, int n, vector<int> &arr2, int m) {

    vector<int> arr3;

    int sum1 = 0;
    int sum2 = 0;

    for(int i = 0; i<n; i++) {

        sum1 = sum1 + arr1[i];
    }

    for(int j = 0; j<m; j++) {

        sum2 = sum2 + arr2[j];
    }

    int sum3 = sum1 + sum2;

    while( sum3 != 0) {

        int digit = sum3%10;

        arr3.push_back(digit);

        sum3 = sum3/10;
    }
}

int main() {

    vector<int> arr1 = {1,2,3,4,5};
    vector<int> arr2 = {1,2,3,4,5,6,7};

    vector<int> yo = addArr(arr1,5,arr2,7);

    for(int f = 0; f<yo.size(); f++) {

        cout<<yo[f]<<" ";
    }
}
