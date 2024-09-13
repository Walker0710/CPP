#include<iostream>
#include<vector>

using namespace std;

vector<int> pairSum(vector<int> &arr, int n, int key) {

    vector<int> ans;

    for(int i = 0; i<arr.size(); i++) {

        for(int j = i+1; j<arr.size(); j++) {

            if(arr[i] + arr[j] == key) {

                ans.push_back(arr[i]);
                ans.push_back(arr[j]);
            }
        }
    }

    return ans;
}

int main() {

    vector<int> arr = {1,2,3,4,5};

    vector<int> arr2 = pairSum(arr, 5, 5);

    for(int i = 0; i<arr2.size(); i++) {

        cout<<arr2[i]<<" ";
    }
}



