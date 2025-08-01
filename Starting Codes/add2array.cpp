#include<iostream>
#include<vector>

using namespace std;

vector<int> reverse(vector<int> v )  {

    int s = 0;
    int e = v.size()-1;

    while(s<e) {

        swap(v[s++], v[e--]);
    }

}

vector<int> findArrrySum(vector<int>& a, int n, vector<int>& b, int m)  {

    int i = n-1;
    int j = m-1;

    int carry = 0;

    while(i>=0 && j>=0) {

        int val1 = a[i];
        int val2 = b[j];

        int sum = val1 = val2 + carry;

        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
        j--;
    }

    while(i>=0) {

        int sum = a[i] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
    }

    while(carry! = 0) {

        int sum = carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
    }

    return ans;

}

