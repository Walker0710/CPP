#include<iostream>
#include<vector>

using namespace std;

double median(vector<int> &arr1, vector<int> &arr2) {

    vector<int> temp;

    int i = 0;
    int j = 0;

    while(i<arr1.size() && j<arr2.size()) {

        if(arr1[i] < arr2[j]) {

            temp.push_back(arr1[i]);
            i++;
        }

        else {

            temp.push_back(arr2[j]);
            j++;
        }
    }

    while(i<arr2.size()) {

        temp.push_back(arr1[i]);
        i++;
    }

    while(j<arr2.size()) {

        temp.push_back(arr2[j]);
        j++;
    }

    if(temp.size()%2 == 1) {

        int yo = temp.size()/2;

        return temp[yo];
    }

    if(temp.size()%2 == 0) {

        int yo = temp.size()/2;

        double ans = (double)(temp[yo] + temp[yo-1])/2;

        return ans;
    }
}


int main() {

    vector<int> arr1;
    int n;
    cin>>n;

    int val;

    for(int i = 0; i<n; i++) {

        cin>>val;
        arr1.push_back(val);
    }

    vector<int> arr2;
    int m;
    cin>>m;

    for(int i = 0; i<m; i++) {

        cin>>val;
        arr2.push_back(val);
    }

    double ans = median(arr1, arr2);

    cout<<endl<<ans<<endl;
}