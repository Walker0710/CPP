#include<iostream> 

using namespace std;

bool search(int arr[], int size, int k) {

    //base case

    if(size == 0) {

        return false;
    }

    if(arr[0] == k) {

        return true;
    }

    else {

        bool remaining = search(arr + 1, size - 1, k);


        return remaining;
    }
}

int main() {

    
}