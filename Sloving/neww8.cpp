#include<iostream>
#include<vector>

using namespace std;

void longestCommon(char arr1[], int a, char arr2[], int b, char arr3[], int c) {

    vector<char> ans;

    for(int i = 0; i < a; i++) {

        if(arr1[i] == arr2[i] && arr2[i] == arr3[i] && arr3[i] == arr1[i]) {

            ans.push_back(arr1[i]);
        }
    }

    for(int i = 0; i<ans.size(); i++) {

        cout<<ans[i];
    }
}

int main() {

    

    

    longestCommon(first,6, second,4, third, 6);

}