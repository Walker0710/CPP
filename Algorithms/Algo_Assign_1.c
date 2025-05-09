#include <stdio.h>
#include <stdlib.h>

int merge(int arr[], int low, int mid, int high) {

    int* temp = (int*)malloc((high - low + 1) * sizeof(int)); // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    int cnt = 0;
    int k = 0;

    //storing elements in the temporary array in a sorted manner//
    while (left <= mid && right <= high) {

        if (arr[left] <= arr[right]) {
            temp[k++] = arr[left++];
        }

        else {
            temp[k++] = arr[right++];
            cnt += (mid - left + 1); 
        }
    }

    // if elements on the left half are still left //
    while (left <= mid) {
        
        temp[k++] = arr[left++];
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        
        temp[k++] = arr[right++];
    }

    // transferring all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        
        arr[i] = temp[i - low];
    }

    free(temp);
    return cnt; 
}

int mergeSort(int arr[], int low, int high) {
    
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);  // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}

int countInversions(int a[], int n) {
    
    return mergeSort(a, 0, n - 1);
}

int main() {
    
    int a[] = {5, 4, 3, 2, 1};
    int n = 5;
    int cnt = countInversions(a, n);
    printf("The number of inversions are: %d\n", cnt);
    return 0;
}


