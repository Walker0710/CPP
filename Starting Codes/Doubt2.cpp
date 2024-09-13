#include<iostream>
#include<vector>

using namespace std;

vector<int> ArrInsertion ( vector<int> &arr1, int n, vector<int> &arr2, int m) {

    int i = 0;
    int j = 0;

    vector<int> ans;

    while(i<n && j<m) {

        if(arr1[i] == arr2[j]){

            ans.push_back(arr1[i]);

            i++;
            j++;           
        }

        if(arr1[i] > arr2[j]) {

            j++;
        }

        if(arr1[i] < arr2[j]) {

            i++;
        }
    }
    return ans;
}


int main() {

    int arr1[6] = {1,2,2,4,5,6};
    int arr2[4] ={2,2,2,5};

    

    for(int k = 0; ; k++) {

        cout<<
    }


}


