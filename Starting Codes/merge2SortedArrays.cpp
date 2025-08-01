#include<iostream>
#include<vector>

using namespace std;

void merge(int arr[],int n, int arr2[], int m, int arr3[]) {

    int i = 0;
    int j = 0;
    int k = 0;

    while(i<n && j<m){

        if(arr[i] < arr2[j]) {

            arr3[k] = arr[i];
            k++;
            i++;
        }

        else{

            arr3[k] = arr2[j];
            k++;
            j++;
        
        }
    }

    while(i < n) {

        arr3[k] = arr[i];
        k++;
        i++;
}

while(j < n)  {

    arr3[k] = arr2[j];
    k++;
    j++;

}


}

void print(int arr4[], int s)  {

    for(int i=0; i<s; i++) {

        cout<<arr4[i]<<" ";
    }

    cout<< endl;
}

int main()  {

int arr1[5] = {1,3,5,7,9};
int arr2[3] = {2,4,6};

int arr3[8] = {0};

merge(arr1,5,arr2,3,arr3);

print(arr3,8);

return 0;
}