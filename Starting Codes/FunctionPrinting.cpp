#include<iostream>
#include<vector>

using namespace std;

int bubbleSort(int arr[], int n) {

    for(int i = 0; i<n; i++) {

        for(int j = 0; j<n-1; j++) {

            if(arr[j] > arr[j+1]) {

                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main() {

    int arr[6] = {3,5,1,4,8,6};

    bubbleSort(arr, 6);

    for(int i = 0; i<6; i++) {

        cout<<arr[i]<<" ";
    }
}

