#include<iostream>

using namespace std;

int pair(int arr[], int n, int key) {

    for(int i = 0; i<n; i++) {

        for(int j = i+1; j<n; j++) {

           if(arr[i] + arr[j] == key) {

            cout<<arr[i]<<" "<<arr[j];
           }


        }
    }
}

int main() {

    int arr[] = {1,2,3,4,5};

    int key = 5;

    int n = sizeof(arr)/sizeof(int);

    pair(arr, n, key);

    return 0;
}
