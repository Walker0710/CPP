#include<iostream>

using namespace std;

int word(int n, string arr[]) {

    if(n==0) {

        return 0;
    }

    int digit = n%10;

    n=n/10;

    cout<<arr[digit]<<" ";

    word(n,arr);

    cout<<arr[digit]<<" ";

}

int main() {

    int n;
    cin>>n;

    string arr[10] = {"zero", "one", "two","three", "four", "five", "six", "seven", "eight", "nine"};

    word(n,arr);
}