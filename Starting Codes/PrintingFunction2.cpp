#include<iostream>
#include<vector>

using namespace std;

void Reverse(int arr[], int n, int k) {

    int ans[n];

    for(int i = 0; i<n; i++) {

        ans[i] = arr[(i+k)%n];
    }

    for(int j =0; j<n; j++) {

        arr[j] = ans[j];
    }
}

int main() {

    int arr[5] = {1,2,3,4,5};

    Reverse(arr, 5, 2);

    for(int i = 0; i<5; i++) {

        cout<<arr[i]<<" ";
    }
}



