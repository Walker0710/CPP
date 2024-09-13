#include<iostream>

using namespace std;



int sort1(int arr[], int n) {

int start = 0;
int end = n-1;

while(start < end) {

    if(arr[start] = arr[end] && start < end) {

        if(arr[start] == 1) {

            end--;
        }

        else{

            start++;
        }
    }

    if(arr[start] > arr[end] && start < end) {

        swap(arr[start],arr[end]);
    }

    if(arr[start] < arr[end] && start < end) {

        start++;
    }
}

return 0;

}

int print(int arr[], int n) {

    for(int i = 0; i<n; i++) {

        cout<<arr[i]<<" ";
    }

    return 0;
}

int main() {

    int arr[8] = {1,1,0,0,0,0,1,0};

    sort1(arr,8);

    print(arr,8);

    return 0;


}