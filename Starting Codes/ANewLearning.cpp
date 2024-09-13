#include<iostream>

using namespace std;

int main() {

int n;
cin>>n;

for(int i = 1; i<=n; i++) {

    int count = 1;

    for(int j = n; j>=i; j--) {

        cout<<count;
        count++;
    }

    for(int s=2; s<=i; s++) {

        cout<<"*";
    }

    for(int t =2; t<=i; t++) {

        cout<<"*";
    }

    int yo = n-i+1;

    for(int r=n; r>=i;r--) {

        cout<<yo;
        yo--;
    }

    cout<<endl;


}
}



