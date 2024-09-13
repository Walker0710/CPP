#include<iostream>
#include<vector>

using namespace std;

vector<int> merge(int arr1[], int n, int arr2[], int m) {

    vector<int> MergedArr;
 
    int i=0;
    int j=0;

    while(i<n && j<m) {

            if(arr1[i] < arr2[j]) {

                MergedArr.push_back(arr1[i]);
                i++;
            }

            if(arr1[i] > arr2[j]) {

                MergedArr.push_back(arr2[j]);
                j++;
            }
        }

    while( i<n ) {

        MergedArr.push_back(arr1[i]);
    }

    while(j<m) {

        MergedArr.push_back(arr2[j]);
    }

    
}




int main() {

    int arr1[6] = {1,3,5,7,9,11};
    int arr2[9] = {2,4,6,8,10,12,13,14,15};

    vector<int> ans = merge(arr1,6,arr2,9);

    for(int i = 0; i<ans.size(); i++) {

        cout<<ans[i];
    }
}