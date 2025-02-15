#include<iostream>

using namespace std;

void merge(int *arr[], int s, int e) {

    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copying value

    int mainArrIndex = s;

    for(int i = 0; i<len1; i++) {

        first[i] = arr[mainArrIndex++];
    }

    int k = mid + 1;
    for(int i = 0; i<len2; i++) {

        second[i] = arr[mainArrIndex++];
    }

    //merge

    int index1 = 0;
    int index2 = 0;

    while(index1 < len1 && index2 < len2) {

        if(first[index1] < second[index2]) {

            arr[mainArrIndex++] = first[index1++]; 
        }

        else {

            arr[mainArrIndex++] = second[index2++];
        }
    }

    while(index1 < len1) {

        arr[mainArrIndex++] = first[index1++];
    }

    while(index2 < len2) {

        arr[mainArrIndex++] = second[index2++];
    }
}

void mergeSort(int *arr, int s, int e) {

    //base case

    if(s>=e) {

        return ;
    }

    int mid = (s+e)/2;

    //left part sort
    mergeSort(arr, s, mid);

    //right part sort
    mergeSort(arr, mid + 1, e);

    merge(arr,s,e);
}

int main() {

    int arr[5] = {2,5,1,6,9};
    int n = 5;

    mergeSort(arr, 0, n-1);

    for(int i = 0; i<n; i++) {

        cout<<arr[i]<<" ";
    }

    return 0;
}







int partition(int arr[], int s, int e) {

    int pivot = arr[s];

    int count = 0;

    for(int i = s+1; i<=e, i++) {

        if(arr[i] <= pivot) {

            count++;
        }
    }

    //placing pivot at right position

    int pivotIndex = s + count;

    swap(arr[pivotIndex], arr[s]);

    //left and right wla part smbhal lete h

    int i = s, j = e;

    while(i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {

            i++;
        }

        while(arr[j] > pivot) {

            j--;
        }

        if(i < pivotIndex && j > pivotIndex) {

            swap(arr[i++], arr[j--]);
        }
    }  

    return pivotIndex;
}


void quickSort(int arr[], int s, int e) {

    //base case
    if(s >= e) {

        return ;
    }

    int p = partition(arr, s, e);

    //sortint left part
    quickSort(arr, s, p-1);

    //sorting right part
    quickSort(arr, p+1, e);
}


